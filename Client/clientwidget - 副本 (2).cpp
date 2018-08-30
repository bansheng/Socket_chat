#include "clientwidget.h"
#include "ui_clientwidget.h"
#include "logindialog.h"
#include "findpassword.h"
#include "user_imformation.h"
#include "chat.h"

#include <QByteArray>
#include <QMessageBox>
#include <QTextStream>
#include <QtNetwork>
#include <QTime>



bool isfind =false; //设置是否找回密码的标志
bool isquestionreturned; // 问题是否返回

QString loginmessage = ""; //这是要发送给服务器的信息，确定是登录还是注册还是找回。
QString myquestion, myanswer; //服务器交流的内容


const int M=20;//先假定最多用户数
user_imformation *v[M];
int mysize; //当前用户数

int mode; //设置消息处理的类型
enum { Login=0, Send, Recv, Chatting, Client};
bool isoffline; //指示上线时是否需要接收离线消息
bool istititleseted; //指示窗口名称不需要设置



//被下面界面引用的变量
QString connected_ip; //尝试连接本机的ip
quint16 Port_number; //这个服务器的小型客户端监听端口！
QString name; //本机用户名
QString try_connect_ip;
quint16 try_connect_port;
bool isAttempToConnect; //指示此时是尝试发起私聊连接还是被连接的



ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientwidget)
{
    ui->setupUi(this);

    //初始化一些变量
    for (int i=0; i<M; i++)
    {
        v[i] = NULL;
    }
    mysize = 0;
    mode = Chatting;
    isoffline = true; //离线消息是否已经尝试接收
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &ClientWidget::connect_failure);

    //获得客户端ip
    QString localHostName = QHostInfo::localHostName();
    qDebug() <<"localHostName: "<<localHostName;
    QHostInfo info = QHostInfo::fromName(localHostName);
    foreach(QHostAddress address,info.addresses())
    {
         if(address.protocol() == QAbstractSocket::IPv4Protocol)
         {
            qDebug() << address.toString();
         }
    }
    Port_number = 7777;
    setWindowTitle(QString("客户端端口:%1").arg(Port_number));
    istititleseted = false; //需要设置窗口

    //设置窗口
    ui->frame_client_off->setEnabled(false);
    ui->frame_client_on->setEnabled(false);
    ui->buttonClose->setEnabled(false); //一开始不能断开吧
    ui->frame_message->setEnabled(false);
    ui->lineEditIp->setText("222.20.104.4");
    ui->lineEditPort->setText("8888"); //默认端口

    tcpSocket = new QTcpSocket(this); //与服务器交流
    //绑定监听


    connect(tcpSocket, &QTcpSocket::connected,
            [=]()
    {
        isoffline = false; //连接服务器需要离线数据
        ui->le_state->setText("已经连接!");
        ui->frame_client_off->setEnabled(true);
        ui->frame_client_on->setEnabled(true);
        ui->frame_message->setEnabled(true); //可以发送消息
        ui->frame_ip->setEnabled(false); //ip不能由用户修改
        ui->buttonClose->setEnabled(true); //可以断开啊
        ui->bt_connect_client->setEnabled(true); //一开始允许连接
        mode = Chatting;
    });

    connect(tcpSocket, &QTcpSocket::disconnected,
                [=]()
    {
        setWindowTitle(QString("客户端端口:%1").arg(Port_number)); //窗口名称复原
        istititleseted = false; //需要设置窗口
        ui->le_state->setText("未连接!");
        ui->le_username->clear();
        ui->frame_client_off->setEnabled(false);
        ui->frame_client_on->setEnabled(false);
        ui->frame_message->setEnabled(false);
        ui->frame_ip->setEnabled(true); //ip能再由用户修改
        ui->buttonClose->setEnabled(false); //不能断开吧
        //用户列表清除
        ui->le_usernum_off->setText("0");
        ui->le_usernum_on->setText("0");
        ui->cb_client_off->clear();//清除用户列表
        ui->cb_client_off->addItem(QString("无"));
        ui->cb_client_on->clear();//清除用户列表
        ui->cb_client_on->addItem(QString("无"));
        ui->lineEditIp->setText("222.20.104.4");
        ui->lineEditPort->setText("8888"); //默认端口
        loginmessage.clear();  //清空本用户信息
    });
    connect(tcpSocket,&QTcpSocket::readyRead,
            [=]()
    {
        QByteArray buf = tcpSocket->readAll(); //接收消息种类
        if (mode == Login) //登录
        {
            if(!isfind) //不是找回密码
            {
                if("login successed" == QString(buf).section("##",1,1) ) //登录注册成功 "##login successed##dingding"
                {
                    name = QString(buf).section("##",2,2);
                    QMessageBox::information(NULL,"恭喜",QString("%1,登录成功").arg(name));
                    tcpSocket->write("##login succeed, request for user_imformation");

                    mode = Chatting;
                    ui->frame_message->setEnabled(true); //用户能发送消息
                    ui->le_username->setText(name);//设置用户名
                }
                else if ("register successed" == QString(buf).section("##",1,1)) //"##register successed##dingding"
                {
                    name = QString(buf).section("##",2,2);
                    QMessageBox::information(NULL,"恭喜",QString("%1,注册并登录成功").arg(name)); //用户名放最后
                    tcpSocket->write("##login succeed, request for user_imformation");

                    mode = Chatting;
                    ui->frame_message->setEnabled(true); //用户能发送消息
                    ui->le_username->setText(name);//设置用户名
                }
                else
                {
                    QMessageBox::information(NULL,"Warning","登录或者注册失败！");
                    on_buttonClose_clicked(); //断开连接！
                }
            }
            else if("question" ==QString(buf).section("##",1,1))//问题未发送
            {
                myquestion = QString(buf).section("##",2,2);
                findpassword* dlgf = new findpassword();
                dlgf->exec();
                tcpSocket->write(myanswer.toUtf8()); //发送给服务器答案
                isquestionreturned = true; //问题已经收到
            }
            else if("answer is right" == QString(buf).section("##",1,1))//"##answer is right##123##dingding"
            {
                name = QString(buf).section("##",3,3);
                QMessageBox::information(NULL,"密码找回",QString("%1，您的密码是:%2,已经自动登录").arg(name).arg(QString(buf).section("##",2,2))); //分割的第二部分
                tcpSocket->write("##login succeed, request for user_imformation");
                mode = Chatting;
                ui->frame_message->setEnabled(true); //用户能发送消息
                ui->le_username->setText(name);//设置用户名
            }
            else //收到其他答案
            {
                QMessageBox::information(NULL,"Warning",QString(buf));
                tcpSocket->write("##something wrong!");
                on_buttonClose_clicked(); //断开连接
                mode = Chatting;
            }

        }
        else if(mode == Client) //请求连接模式
        {
            if("fine, contact" == QString(buf).section("##",1,1)) //收到连接指令 ding##fine, contact##yaya 丁丁允许亚亚连接
            {
                if(name == QString(buf).section("##",2,2)) //与本机name一样
                {
                    QString connect_name = QString(buf).section("##",0,0);
                    QString myip = "";
                    qint16 myport = 0;
                    for(int i=0; i<mysize; i++)
                    {
                        if(v[i]->username == connect_name) //找到对方的监听端口,对方的ip和port
                        {
                            myip = v[i]->ip;
                            myport = v[i]->port;
                        }
                    }
                    if(myip != "" && myport != 0)
                    {
                        try_connect_ip = myip;
                        try_connect_port = myport;
                        isAttempToConnect = true;
                        Chat* dlgc = new Chat();
                        dlgc->show();
                    }

                }
                else //与本机连接不一样
                {
                    QMessageBox::information(NULL,"Warning","收到连接对象非本机的点对点连接");
                }
            }
            mode = Chatting;
            ui->frame_message->setEnabled(true); //用户能发送消息
        }
        else if("request for contact" == QString(buf).section("##",1,1)) //服务器说要其他用户请求直接连接 dingding##request for contact##yaya
        {
            if(name != QString(buf).section("##",2,2))
            {
                QMessageBox::information(NULL,"信息发送错了",QString("来自%1的信息错误").arg(QString(buf).section("##",0,0)));
            }
            else
            {
                QString connected_name = QString(buf).section("##",0,0);
                for(int i=0; i<mysize; i++)
                {
                    if(v[i]->username == connected_name) //找到对方的ip,方便监听
                    {
                        connected_ip = v[i]->ip;
                    }
                }
                ui->cb_client_on->setCurrentText(QString(buf).section("##",0,0));
                tcpSocket->write(QString("%1##fine, contact##%2").arg(name).arg(QString(buf).section("##",0,0)).toUtf8());
                isAttempToConnect = false; //被连接的对象
                qDebug() << Port_number;
                Chat* dlgc = new Chat();
                dlgc->show();
            }
        }
        else if("load users' states" == QString(buf).section("##",0,0))//用户状态变更  load users' states##10##....
        {
            for (int i=0; i<M; i++) //把元素清空
            {
                v[i] = NULL;
            }
            mysize = 0;
            QString a = ui->cb_client_off->currentText();
            QString b = ui->cb_client_on->currentText();
            ui->cb_client_off->clear();//清除用户列表
            ui->cb_client_off->addItem(QString("无"));
            ui->cb_client_on->clear();//清除用户列表
            ui->cb_client_on->addItem(QString("无"));
            ui->lineEditIp->clear();
            ui->lineEditPort->clear();
            //获取用户状态信息
            mysize = QString(buf).section("##",1,1).toInt(); // 10##.. 首先获取数组大小
            if(mysize > 0)
            {
                QString imformation = (QString(buf).section("##",2,2)); //用户信息
                QTextStream userinformation(&imformation);//读取用户信息
                int num_on = 0, num_off = 0;
                for(int i=0; i<mysize; i++)
                {
                    QString myname, myip;
                    int myport;
                    int ison;
                    userinformation >> myname ;
                    userinformation >> ison;
                    userinformation >> myip;
                    userinformation >> myport;
                    user_imformation *u = new user_imformation(myname,ison,myip,myport);
                    v[i] = u;
                    //加载用户列表信息
                    if(!istititleseted && myname==name)
                    {
                        setWindowTitle(QString("ip:%1  客户服务端端口:%2").arg(myip).arg(myport));
                        Port_number = myport;
                        istititleseted = true; //已经创建
                    }
                    if(ison==1)//在线用户
                    {
                        ui->cb_client_on->addItem(myname);
                        num_on ++;
                    }
                    else //离线
                    {
                        ui->cb_client_off->addItem(myname);
                        num_off ++;
                    }
                }
                ui->le_usernum_on->setText(QString("%1").arg(num_on));
                ui->le_usernum_off->setText(QString("%1").arg(num_off));
                ui->cb_client_off->setCurrentText(a);
                ui->cb_client_on->setCurrentText(b);
            }
            else
            {
                ui->le_usernum_on->setText(QString("0"));
                ui->le_usernum_off->setText(QString("0"));
            }

            if(!isoffline)//未加载离线信息
            {
                isoffline = true; //只需要连接服务器一次的时候请求
                tcpSocket->write(QString("Offline message##%1").arg(name).toUtf8()); //请求离线信息
                qDebug() << "Offline message##%1";

            }
            else
            {
                //do othing
            }
        }
        else if("offline message" == QString(buf).section("&&",0,0)) //离线消息处理
        {
            int count = QString(buf).section("&&",1,1).toInt();

            for(int indexofm=2; indexofm<count+2; indexofm++)
            {
                QString m = QString(buf).section("&&",indexofm,indexofm);
                QString sendername = QString(m).section("##",0,0);
                QString message = QString(m).section("##",1,1);
                QString recvname = QString(m).section("##",2,2);
                ui->textBrowser->append(sendername.append(QString(" to ")).
                                        append(recvname).append(QString(":  ")).append(message)); //消息显示格式！
            }
        }
        else if("##permission for login" == QString(buf)) //接收到允许登录
        {
            timer->stop();
            LoginDialog *dlg = new LoginDialog(); //登录界面
            dlg->exec();
            isquestionreturned = false; //问题未传回
            qDebug() << "发送登录消息";
            ui->frame_message->setEnabled(false); //用户不能发送消息
            if(loginmessage != "")
            {
                tcpSocket->write(loginmessage.toUtf8());//发送登录信息
                ui->frame_message->setEnabled(false); //用户不能发送消息
                mode = Login; //登录
            }
            else
            {
                tcpSocket->write("login failed"); //断开连接
            }
        }
        else //处理普通消息 dingding##hello##yaya
        {
            QString sendername = QString(buf).section("##",0,0);
            QString message = QString(buf).section("##",1,1);
            QString recvname = QString(buf).section("##",2,2);
            ui->textBrowser->append("--------------" + QTime::currentTime().toString("hh:mm:ss") + "--------------");
            ui->textBrowser->append(QString("<font color=black>%1</font><font color=pink> to </font><font color=green>%2</font> : <font color=blue>%3</font>").arg(sendername).arg(recvname).
                    arg(message)); //显示对方的信息消息显示格式！
        }

    });
}
ClientWidget::~ClientWidget()
{
    for(int i=0; i<M; i++)
    {
        if(v[i])
        {
            delete v[i];
            v[i] =NULL;
        }
    }
    tcpSocket->close();
    delete ui;
}

void ClientWidget::on_buttonConnect_clicked() //打开服务器
{
    QString ip = ui->lineEditIp->text();
    qint16 port = ui->lineEditPort->text().toInt();
    tcpSocket->connectToHost(QHostAddress(ip),port);
    tcpSocket->write("##request for login");//发送请求
    timer->start(100); //0.1秒
    qDebug() << "##request for login";
}

void ClientWidget::connect_failure()
{
    QMessageBox::information(this,"错误","未连接服务器或者服务器未打开", QMessageBox::Yes);
    timer->stop();
}

void ClientWidget::on_buttonClose_clicked()
{
    for (int i=0; i<mysize; i++) //服务器连接关闭
    {
        delete v[i];//清除所有的指针空间
        v[i] = NULL;
    }
    mysize = 0;
    if(tcpSocket->isOpen())
        tcpSocket->disconnectFromHost();
}


void ClientWidget::on_cb_client_off_currentIndexChanged(int index)
{
    if(index != 0) //不是无
    {
        ui->frame_client_on->setEnabled(false); //在线客户区不能选择
        ui->cb_client_on->setCurrentIndex(0); //回到0
    }
    else
    {
        ui->frame_client_on->setEnabled(true);
    }
}

void ClientWidget::on_cb_client_on_currentIndexChanged(int index)
{
    if(index != 0)//不是无
    {
        if(ui->cb_client_on->currentText() == ui->le_username->text())
        {
            ui->cb_client_on->setCurrentIndex(0);
        }
        else
        {
            ui->frame_client_off->setEnabled(false); //离线客户不能选择
            ui->cb_client_off->setCurrentIndex(0); //回到0
            for(int i=0; i<mysize; i++)
            {
                if(v[i]->username == ui->cb_client_on->currentText())
                {
                    ui->lineEditIp->setText(v[i]->ip);
                    ui->lineEditPort->setText(QString("%1").arg(v[i]->port)); //获得他的服务器端的port
                }
            }
        }

    }
    else
    {
        ui->frame_client_off->setEnabled(true); //如果index==0 离线客户区可以编辑
    }
}

void ClientWidget::on_bt_connect_client_clicked() //连接客户
{
    if(ui->cb_client_on->currentIndex() != 0)
    {
        for(int i=0; i<mysize; i++)
        {
            if(v[i]->username == ui->cb_client_on->currentText()) //找到对方的监听端口,对方的ip和port
            {
                if(v[i]->hasbeenConnected)
                {
                    QMessageBox::information(this,"提示", "已经连接上了!");
                    return; //直接退出
                }
            }
        }
        QString contact = QString("%1##request for contact##%2").arg(name).arg(ui->cb_client_on->currentText()); //用户名发送过去
        tcpSocket->write(contact.toUtf8());
        mode = Client;
    }
}

void ClientWidget::on_bt_message_send_clicked()
{
    if(ui->le_message->text().trimmed() != "") //消息框不能为空字符
    {
        QString sendername = name;
        QString recvname = "";
        if(ui->cb_client_off->currentIndex() != 0)
        {
            recvname = ui->cb_client_off->currentText();
        }
        else if (ui->cb_client_on->currentIndex() != 0)
        {
            recvname = ui->cb_client_on->currentText();
        }
        else //都是无
        {
            ui->textBrowser->append("请选择有效发送对象!");
            return;
        }
        QString sendmessage = sendername.append(QString("##%1##").arg(ui->le_message->text()).append(recvname));
        tcpSocket->write(sendmessage.toUtf8()); //发送信息
        qDebug() << "server send message!";
        QString mymessage = QString("<font color=green>%1</font><font color=pink> to </font><font color=black>%2</font> : <font color=blue>%3</font>").arg(name).arg(recvname).
                arg(ui->le_message->text()); //显示我的信息
        ui->textBrowser->append("--------------" + QTime::currentTime().toString("hh:mm:ss") + "--------------");
        ui->textBrowser->append(mymessage);
        ui->le_message->clear(); //发送完清空le
    }
}
