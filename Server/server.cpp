#include "server.h"
#include "ui_server.h"
#include <QByteArray>
#include <QMessageBox>
#include <QtNetwork>
#include <QTime>
#include "user_information.h"
#include "messagequeue.h"


int currentsize; //总的下标位置

struct user_data
{
    user_imformation *v[M];
    int size; //用户数
}*User_data;

messageQueue* Me;

bool isfirst =false;

int mode[M];
enum {Acceptlogin=0, Chat}; //登录交流和离线消息发送

int indexofv;

server::server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::server)
{
    ui->setupUi(this);
    User_data = new user_data();
    for (int i=0; i<M; i++)
    {
        User_data->v[i] = NULL;
        mode[i] = Chat;
    }
    indexofv = 0;
    User_data->size = 0;
    currentsize = 0;
    Me = NULL;
    isfirst = true;
    userload(); //加载用户信息
    userstateupdate();
    QTime t = QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);

    QString localHostName = QHostInfo::localHostName();
    qDebug() <<"localHostName: "<<localHostName;
    QHostInfo info = QHostInfo::fromName(localHostName);
    foreach(QHostAddress address,info.addresses())
    {
         if(address.protocol() == QAbstractSocket::IPv4Protocol)
         {
            qDebug() << address.toString();
            ui->textBrowser->append(address.toString());
         }
    }
    for(int i=0;i <M;i ++)
    {
        tcpSocket[i] = new QTcpSocket(this);
    }

    tcpServer = new QTcpServer(this);
    //绑定监听
    tcpServer->listen(QHostAddress::Any,8888);
    setWindowTitle(QString("服务器端口：8888"));
    ui->bt_save->hide();
    connect(tcpServer,&QTcpServer::newConnection,
            [=]()
    {
        //获取通信套接字
        int index = currentsize;//currentsize为1的时候只有一个套接字
        tcpSocket[index] = tcpServer->nextPendingConnection();

        currentsize++; //每次总个数总要发生变化，但是单独的下标不发生变化

        //获取对方IP、port
        QString ip = tcpSocket[index]->peerAddress().toString().section(":",3,3);
//        QString ip = tcpSocket[index]->peerAddress().toString();
        quint16 port = tcpSocket[index]->peerPort();

        QString str = QString("[%1:%2]:成功连接").arg(ip).arg(port);
        ui->textBrowser->append(str);


        connect(tcpSocket[index], &QTcpSocket::connected, //连接上的处理操作
                [=]()
        {

           //消息队列处理

            ui->bt_save->setEnabled(false);//此时不能保存

        });

        connect(tcpSocket[index], &QTcpSocket::disconnected, //断开连接的操作
                    [=]()
        {
            QString str2 = QString("[%1:%2]:断开连接").arg(ip).arg(port);
            ui->textBrowser->append(str2);
            for(int i=0; i<User_data->size; i++)
            {
//                if(User_data->v[i]->ip == ip && User_data->v[i]->port == port)
                if(User_data->v[i]->ip == ip)
                {
                    ui->textBrowser->append(QString("%1离线了").arg(User_data->v[i]->username));
                    User_data->v[i]->state = 0; //离线
                    break;
                }
            }
            if(index < currentsize-1) //不是在最后一个，需要改变指针数组里面元素的值
            {
                for(int i=index; i<currentsize-1; i++)
                {
                    tcpSocket[i] = tcpSocket[i+1]; //节省空间
                }
            }
            currentsize -- ;
            userstateupdate();
        });

        connect(tcpSocket[index], &QTcpSocket::readyRead, //处理收到的信息
                [=]()
        {
            QByteArray buf = tcpSocket[index]->readAll();
            //采用回射信息进行粘包处理

            if(mode[index] == Acceptlogin)
            {
                if("login" == QString(buf).section("##",0,0)) //login
                {
                    //比较密码
                    qDebug() << "login";
                    bool ispass=false;
                    for(int i=0; i<User_data->size; i++)
                    {
                        if(User_data->v[i]->username == QString(buf).section("##",1,1)
                                && User_data->v[i]->password == QString(buf).section("##",2,2))
                        {
                            ispass = true; //通过
                            ui->textBrowser->append(QString("%1上线了").arg(User_data->v[i]->username));
                            User_data->v[i]->state = 1; //在线
                            User_data->v[i]->ip = ip;
                            User_data->v[i]->port = qrand()%10000+10000; //存储 客户端服务器port信息 的地方，由自己定

                            break;
                        }
                    }
                    if(ispass) //##login successed##dingding
                    {
                        //发送离线消息

                        tcpSocket[index]->write(QString("##login successed##%1").arg(QString(buf).section("##",1,1)).toUtf8());
                        qDebug() << "##login successed##%1";
                    }
                    else
                    {
                        tcpSocket[index]->write(QString("##login fail##%1").arg(QString(buf).section("##",1,1)).toUtf8());
                        mode[index] = Chat;
                    }

                }
                else if("register" == QString(buf).section("##",0,0) )//注册
                {
                    qDebug() << "regsiter";
                    QString myname = QString(buf).section("##",1,1);
                    QString mypassword = QString(buf).section("##",2,2);
                    QString myquestion =  QString(buf).section("##",3,3);
                    QString myanswer = QString(buf).section("##",4,4);
                    bool islogined=false;
                    for(int i=0; i<User_data->size; i++)
                    {
                        if(User_data->v[i]->username == myname)
                        {
                            islogined = true; //注册过
                            break;
                        }
                    }
                    if(!islogined) //未注册过
                    {
                        int newport = qrand()%10000+10000; //存储 客户端服务器port信息 的地方，由自己定
                        User_data->v[User_data->size] = new user_imformation(myname, mypassword, myquestion, myanswer,1, ip, newport);
                        User_data->size++; //需要改变大小

                        tcpSocket[index]->write(QString("##register successed##%1").arg(myname).toUtf8());
                        on_bt_save_clicked(); //保存数据
                        qDebug() << "##register successed##%1";
                    }

                    else //已经注册过
                    {
                        tcpSocket[index]->write("register failed! 重复用户名");
                        mode[index] = Chat;
                    }
                }
                else if("find" == QString(buf).section("##",0,0) ) //找回密码
                {
                    qDebug() << "find";
                    QString findname = QString(buf).section("##",1,1);
                    bool isreturnquestion =false;
                    for(int i=0; i<User_data->size; i++)
                    {
                        if(User_data->v[i]->username == findname)
                        {
                            indexofv = i; //存下此时的i
                            isreturnquestion = true;
                            tcpSocket[index]->write(QString("##question##%1").arg(User_data->v[i]->question).toUtf8()); //发送问题
                            qDebug() << "##question##%1";
                        }

                    }
                    if(!isreturnquestion) //问题返回
                    {
                        tcpSocket[index]->write("user don't exist"); //不存在用户
                        mode[index] = Chat;
                    }
                }
                else if("answer" == QString(buf).section("##",0,0))//传输回来的问题答案
                {
                    QString answer = QString(buf).section("##",1,1);
                    if(User_data->v[indexofv]->answer == answer) //##answer is right##dingding##123
                    {
                        ui->textBrowser->append(QString("%1上线了").arg(User_data->v[indexofv]->username));
                        User_data->v[indexofv]->state = 1; //在线
                        User_data->v[indexofv]->ip = ip;
                        User_data->v[indexofv]->port = qrand()%10000+10000; //存储 客户端服务器port信息 的地方，由自己定
                        tcpSocket[index]->write(QString("##answer is right##%1##%2").
                                                arg(User_data->v[indexofv]->username).arg(User_data->v[indexofv]->password).toUtf8());

                        qDebug() << "##answer is right##%1##%2";
                    }
                    else
                    {
                        tcpSocket[index]->write("the answer is wrong");
                        mode[index] = Chat;
                    }

                }
                else if("##login succeed, request for user_imformation" == QString(buf))
                {
                    userstateupdate();
                    ui->bt_save->setEnabled(true);
                }
                else if("Offline message" == QString(buf).section("##",0,0))
                {
                    qDebug() << "开始传递离线消息";
                    handlemessage(QString(buf).section("##",1,1),tcpSocket[index]);
                    mode[index] = Chat;
                }
                else
                {
                    ui->textBrowser->append(QString("登录失败"));
                    tcpSocket[index]->disconnectFromHost(); //服务器断开连接
                    mode[index] = Chat; //登录失败

                }
            }
            else if(mode[index] == Chat)
            {
                if("##request for login" == QString(buf)) //登录类请求
                {
                    qDebug() << "##request for login";
                    tcpSocket[index]->write("##permission for login");
                    qDebug() << "##permission for login";
                    mode[index] = Acceptlogin;
                }
                else //离线消息队列
                {
                    qDebug() << "普通消息:" << QString(buf);
                    QString recvname = QString(buf).section("##",2,2);
                    for(int i=0; i<User_data->size; i++)
                    {
                        qDebug() << i << " " << User_data->size << " " << User_data->v[i]->username;
                        if(recvname == User_data->v[i]->username)
                        {
                            if(User_data->v[i]->state == 1) //在线
                            {
                                for(int j=0; j<currentsize; j++) //找到socket并发送
                                {
//                                    tcpSocket[j]->peerAddress().toString().section(":",3,3)
                                    if(tcpSocket[j]->peerAddress().toString().section(":",3,3) == User_data->v[i]->ip) //找到相等的ip说明发给这个人
                                    {
                                        tcpSocket[j]->write(buf);
                                        break;
                                    }
                                }
                            }
                            else //离线
                            {
                                messageQueue* m = Me;
                                if(Me == NULL) //如果首队列为空
                                {
                                    Me = new messageQueue(QString(buf), QString(buf).section("##",2,2));
                                }
                                else //添加最后一个为空的队列
                                {
                                    while(m->next != NULL)
                                    {
                                        m = m->next;
                                    }
                                    m->next = new messageQueue(QString(buf), QString(buf).section("##",2,2));
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }); //函数完毕
    });

}

server::~server()
{
    delete User_data;
    User_data =NULL;
    delete ui;
}

void server::userload()
{
    QFile myfile("NP.txt");
    qDebug() << "读取数据";
    if(myfile.open(QIODevice::ReadOnly | QIODevice :: Text))
    {
        /*文本输出流，用于保存数据*/
        QByteArray a = QByteArray::fromBase64(myfile.readAll());
        QString b = QString(a);
        QTextStream in(&b);
        QString username = "";
        QString password = "";
        QString question = "";
        QString answer = "";
        User_data->size = 0;
        while( !in.atEnd()) //未到文件尾
        {
            in >> username;
            if(username != "")
            {
                qDebug() << username;
                in >> password;
                in >> question;
                in >> answer;
                User_data->v[User_data->size] = new user_imformation(username, password, question, answer);
                User_data->size++;
            }
            else
            {
                break;
            }
        }
        myfile.close();

    }
    else //用户密码文件打开失败
    {
        QMessageBox::warning(this, "Warning!", "用户密码文件打开失败", QMessageBox::Yes);
        close(); //退出
    }
}

void server::userstateupdate()
{
    qDebug() << "状态更新,用户数：" << User_data->size;
    ui->le_usernum_off->clear();
    ui->le_usernum_on->clear();
    ui->tb_off->clear();
    ui->tb_on->clear();
    int num_on=0, num_off=0;
    QString updatemessage = QString("load users' states##%1##").arg(User_data->size);
    for(int i=0; i<User_data->size; i++)
    {
        updatemessage = updatemessage.append(User_data->v[i]->toString());
//        ui->textBrowser->append(QString::number(User_data->v[i]->state) +" " + User_data->v[i]->username);
        if(User_data->v[i]->state == 1) //在线
        {
            ui->tb_on->append(User_data->v[i]->username);
            num_on ++;
        }
        else
        {
            ui->tb_off->append(User_data->v[i]->username);
            num_off ++;
        }
    }
    ui->le_usernum_on->setText(QString::number(num_on, 10));
    ui->le_usernum_off->setText(QString::number(num_off, 10));
    if(isfirst) //第一次加载不需要发送
    {
        isfirst = false;
    }
    else
    {
        for(int i=0; i<M; i++)
        {
            if(tcpSocket[i]->isOpen())
            {
                qDebug() << "状态信息发送给的客户端下标:" << i;
                tcpSocket[i]->write(updatemessage.toUtf8()); //发送更新消息
            }
            else
            {
                break;
            }
        }
    }

}

void server::handlemessage(QString myname, QTcpSocket* socket) //用户发出离线消息请求
{
    messageQueue *a=Me;
    QString sendmessage = "";
    int count = 0;
    while(a) //不为空
    {
        if(a->recvname == myname) //要发送给的对象一样选择发送
        {
//            socket->write(a->message.toUtf8()); //发送消息
            sendmessage.append(QString("&&%1").arg(a->message));
            count ++;
            a->issended = true; //已经被发送
        }
        a = a->next;
    }
    if(count != 0)
    {
        QString sendmessage2 = QString("offline message&&%1").arg(count).append(sendmessage);
        socket->write(sendmessage2.toUtf8());
    }
//    QMessageBox::information(this, "提示!", "离线消息发送完毕", QMessageBox::Yes);
    ui->textBrowser->append("离线消息发送完毕");
    //开始清理已经发送过的消息
    messageQueue* head = Me;
    while(head!=NULL && head->issended) //找到第一个未被发送的信息
    {
        messageQueue* pre = head;
        head = head->next;
        delete pre; //销毁空间
        pre = NULL;
    }
    if(head == NULL)
    {
        Me = NULL; //头结点为空
    }
    else
    {
        Me = head; //头结点重新定位
        messageQueue* p = Me; //定位未发送节点
        messageQueue* q = Me->next; //定位未发送节点的下一位
        while(q != NULL)
        {
            if(q->issended) //发送过了
            {
                while(q!= NULL && q->issended) //寻找下一个未发送的节点
                {
                    messageQueue* later = q;
                    q = q->next;
                    delete later; //销毁空间
                    later = NULL;
                }
                if(q == NULL) //全部发送了
                {
                    //不做啥
                }
                else
                {
                    p = q; //q此时未发送
                    q = p->next;
                }
            } //q未发送
            else
            {
                p = q;
                q = p->next;
            }
        }
    }

}

void server::on_bt_save_clicked()
{
    //文件保存
    QFile myfile("NP.txt");
    if(myfile.open(QIODevice::WriteOnly)) //以文本文式写入
    {
        QByteArray in;
        for(int i=0; i<User_data->size; i++)
        {
            in.append(User_data->v[i]->username.toUtf8());
            in.append(QString(" ").toUtf8());
            in.append(User_data->v[i]->password.toUtf8());
            in.append(QString(" ").toUtf8());
            in.append(User_data->v[i]->question.toUtf8());
            in.append(QString(" ").toUtf8());
            in.append(User_data->v[i]->answer.toUtf8());
            in.append(QString(" ").toUtf8());
        }
        myfile.write(in.toBase64());
        myfile.close();
    }
    else
    {
        QMessageBox::warning(this, "Warning!", "用户密码文件打开失败", QMessageBox::Yes);
        close(); //退出
    }
}

