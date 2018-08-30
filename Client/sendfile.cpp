#include "sendfile.h"
#include "ui_sendfile.h"
#include <QMessageBox>
#include <QTime>

extern QString ip_recv; //接收者ip
extern bool issendorrecv; //从主文件中得到的参数 true为发送 false为接收


const int N=8; //设置每次大包 包含小包的数目
bool isrecved[N]; //接收端接收到的包的编号 1为收到 0为未收到
bool iswriten[N]; //接收端写入的已经写入的标志
bool isconfirmed[N]; //发送端接收到的包的编号 1为确认发送 0为未确认发送
bool isremade[N];    //标志这个包有没有重新做好接收端ip
QByteArray send_packages[N]; //发送端读取文件的缓冲区
QByteArray recv_packages[N]; //接收端写入文件的缓冲区
int count_send; //发送包的编号计数器
int count_recv; //接收包的编号计数器


int numofpackage; //要发送的包的数量
bool isover;    //全部发送完毕时为真
bool isallconfirmed;  //收到文件接收完全的标志
bool istail;     //接收到文件尾为真

const int outtime=100; //超时判定毫秒数，超过这个时间没有收到确认报文判定超时
const int package_size=1024; //单个包的大小/b

QTime sumtime; //发送总时间

QTime count_time_sender, count_time_recver; //传输速率计算， 经过时间，大于interval
int sec_sender, sec_recver; //计算这个速率变换间隔内发送的大包的数量
const int interval = 1000; //速率显示变换间隔，屏幕上测定速率时要求超过这个时间再变



Sendfile::Sendfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sendfile)
{
    ui->setupUi(this);
    ui->bt_exit->setEnabled(false);
    if(issendorrecv) //发送
    {
        // 发送方不需要绑定端口，只需要知道接收方的ip和端口进行发送
        udpSocketserver = new QUdpSocket(this);
        udpSocketserver->setSocketOption(
                           QAbstractSocket::ReceiveBufferSizeSocketOption,
                           1024*1024*100);
        connect(udpSocketserver, SIGNAL(readyRead()), this,SLOT(readPendingDatagrams_send()));
        ui->le_recv_ip->setText(ip_recv);
        ui->textBrowser->append(ip_recv);
    }
    else //接收
    {
        //接收方需要绑定ip和端口来让发送方知道要发送的目的地
        udpSocketclient = new QUdpSocket(this);
        udpSocketclient->setSocketOption(
                           QAbstractSocket::ReceiveBufferSizeSocketOption,
                           1024*1024*100);

        udpSocketclient->bind(recverPort); //绑定端口本机的ip 应该不需要绑定吧
        connect(udpSocketclient, SIGNAL(readyRead()), this,SLOT(readPendingDatagrams_recv()));
        ui->buttonChooseFile->hide();
        ui->butttonSendFile->hide();
        ui->label_process->setText("接收进度:"); //接收进度
        ui->le_name->setText("正在等待发送");
        ui->label_recvip->hide();
        ui->le_recv_ip->hide();
    }
    if(ip_recv == "")
    {
        QMessageBox::information(NULL,"错误","接收端ip为空!");
        close();
    }
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &sendData); //超时设置
}

Sendfile::~Sendfile()
{
    if(udpSocketclient)
    {
        udpSocketclient->close();
        delete udpSocketclient;
        udpSocketclient = NULL;
    }
    if(udpSocketserver)
    {
        udpSocketserver->close();
        delete udpSocketserver;
        udpSocketserver = NULL;
    }
    delete ui;
}

void Sendfile::on_buttonChooseFile_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"open","../");
    if(false == filePath.isEmpty()){    //路径有效
        ui->butttonSendFile->setEnabled(true);
        ui->buttonChooseFile->setEnabled(false); //不能再选
        fileNamesend.clear();
        //获取文件信息：名字、大小
        QFileInfo info(filePath);
        fileNamesend = info.fileName();
        ui->le_name->setText(fileNamesend);
        fileSizesend = info.size();
        ui->le_size->setText(QString::number(fileSizesend/1024/1024) + "MB");
        sendSize = 0;   //已经发送文件大小

        //以只读方式打开文件
        filesend.setFileName(filePath);
        if(false == filesend.open(QIODevice::ReadOnly)){
            ui->textBrowser->append("只读方式打开文件失败");
        }
        //提示已经打开的文件路径
        ui->textBrowser->append(filePath);

        //构建要发送的文件的头信息
        filesend_information = QString("##%1##%2").arg(fileNamesend).arg(fileSizesend);
        ui->progressBar->setMaximum(fileSizesend);
        ui->progressBar->setMinimum(0);
        ui->progressBar->setValue(0);

        //可以发送
        ui->buttonChooseFile->setEnabled(false);  //只能选择一次
        ui->butttonSendFile->setEnabled(true);
    }
    else{
        ui->textBrowser->append("选择文件路径无效");
    }
}

void Sendfile::on_butttonSendFile_clicked()
{
    ui->butttonSendFile->setEnabled(false);//不能再发,注意此时只能关闭，完成后不能进行任何操作
    //发送按钮已经点击，发送过程中不能再点击，恢复按钮初始化


    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!注意了
    udpSocketserver->writeDatagram(QString("filehead%1").arg(filesend_information).toUtf8(), QHostAddress(ip_recv), recverPort);
    //发送头请求


//    qDebug() << "filehead" << filesend_information;
}

void Sendfile::sendData()
{
    for(int i=0; i<numofpackage; i++)
    {
        if(!isconfirmed[i]) //未收到确认
        {
            udpSocketserver->writeDatagram(send_packages[i], QHostAddress(ip_recv), recverPort);
            //发送未确认的包
        }
    }
}


void Sendfile::readPendingDatagrams_send()
{
    while (udpSocketserver->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocketserver->pendingDatagramSize());
        recverhost.clear(); //清除主机之前信息
        udpSocketserver->readDatagram(datagram.data(), datagram.size(), &recverhost, &recverPort); //获得要接收文件的主机信息
        if("##filehead recved" == datagram) //
        {
            ui->textBrowser->append("文件头接收到");
            count_send = 0;  //大包编号重置
            isover = false;
            isallconfirmed = false;
            count_time_sender.start(); //获得当前时间，制作大包之前
            sumtime.start(); //开始，制作大包之前
            sec_sender = 0; //设置计数器
            //制作大包
            for(int i=0; i<N; i++)
            {
                isconfirmed[i] = false; //设置未确认
            }
            int num = 0; //制作包的内部编号
            while(!filesend.atEnd() && num<N) {
                QByteArray line(filesend.read(package_size));
                send_packages[num].clear();
                send_packages[num].append(QString("%1&#&#%2&#&#").arg(count_send).arg(num)); //包头
                send_packages[num].append(line);
                isremade[num] = false; //此时没有被重新写入
                udpSocketserver->writeDatagram(send_packages[num], QHostAddress(ip_recv), recverPort); //边写边发送

                num++;//0-7
//                qDebug()<< "send over!"<< count_send  << num << line.size();
                if(line.size() <package_size){
                    filesend.close();
//                    isover = true; //全部发送完毕
                    break;
                }
            }
            numofpackage = num;
            timer->start(outtime); //超过outtimems重传
        }
        else if("##file open failed"== datagram)
        {
            filesend.close();
            ui->textBrowser->append("文件头错误");
            ui->bt_exit->setEnabled(true);
            return;
        }
        else if("##file recved"== datagram) //收到完全确认
        {
            isallconfirmed = true;
            ui->progressBar->setValue(fileSizesend);
            timer->stop(); //计时器重置
            delete timer; //删除计数器
            ui->bt_exit->setEnabled(true);
            ui->textBrowser->append("传输完毕，对方已经全部确认接收!");
            //计算总时间
            int sum = sumtime.elapsed();
            int sum_s = sum/1000; //1000毫秒
            long int speedsum = (fileSizesend*1000/sum)/1024; //kb/s
            if(sum_s >= 60)
            {
                int sum_m = sum_s/60; //取整
                sum_s = sum_s%60; //取余
                QMessageBox::warning(this,"传输完成",QString("共花费时间%1分钟%2秒,平均速度%3 kb/s").arg(sum_m).arg(sum_s).arg(speedsum),QMessageBox::Yes);
                close();
            }
            else
            {
                QMessageBox::warning(this,"传输完成",QString("共花费时间%1秒,平均速度%2 kb/s").arg(sum_s).arg(speedsum),QMessageBox::Yes);
            }
            close();
        }
        else if(!isallconfirmed) //未收到完全确认
        {

            int confirmnum = QString(datagram).toInt();
//            qDebug() << "收到确认：" << count_send << confirmnum << "  本分组需要确认的个数:" << numofpackage;
            if(isconfirmed[confirmnum] == false)//如果为未确认的
            {
                isconfirmed[confirmnum] = true; //确认收到
                int make = 0;
                while (isremade[make] && make<N) { //找到第一个未被重做的,已经被重做的跳过
                    make++;
                }
                while(!isremade[make] && isconfirmed[make] &&make<N && !isover) //已经被确认没有被重新写入
                {
                    if(!filesend.atEnd())
                    {
                        QByteArray line(filesend.read(package_size));
                        send_packages[make].clear();
//                        qDebug() << "已经制作：" << count_send+1 << make;
                        send_packages[make].append(QString("%1&#&#%2&#&#").arg(count_send+1).arg(make)); //包头
                        send_packages[make].append(line);
                        isremade[make] = true; //未被重做
                        make++;
                        if(line.size() <package_size){
                            isover = true;
                            filesend.close();
                            break;
                        }
                    }
                }
            }
            else //已经确认过的
            {
                return; //重复确认不需要处理
            }
            bool ispass = true;
            for(int i=0; i<numofpackage; i++)
            {
                if(!isconfirmed[i]) //只要有一个未确认
                {
                    ispass = false;
                    break;
                }
            }
            if(ispass) //全部确认
            {
//                qDebug() << "分组全部确认!" << count_send;
                count_send++; //序号加1
                ui->progressBar->setValue(count_send*N*package_size);
                int cts =count_time_sender.elapsed();
                if( cts > interval) //显示文件速率
                {
                    count_time_sender.start();//更新
//                    qDebug() << "更新时间，文件速率变换时间间隔:毫秒" << cts;
                    double speed =  ((sec_sender+1)*N*package_size*1000/cts/1024);
                    ui->le_speed->setText(QString("%1 kb/s").arg(speed)); //设置速度
                    sec_sender = 0;
                }
                else
                {
                    sec_sender++;
                }
//                qDebug() << "更新时间完成";
                //发送大包, 变更nop
                int mynum =0 ;
                while(isremade[mynum] && mynum<N)
                {
                    isconfirmed[mynum] = false; //设置未确认
                    mynum++;
                }
                numofpackage = mynum; //获得此时被重做成功的包
                for(int i=0; i<mynum; i++)
                {
                    isremade[i] = false; //此时没有被重新写入
//                    qDebug() << "已经发送" << QString(send_packages[i]).section("&#&#",0,0)  << QString(send_packages[i]).section("&#&#",1,1) << send_packages[i].size();
                    udpSocketserver->writeDatagram(send_packages[i], QHostAddress(ip_recv), recverPort); //边写边发送
                }
                timer->start(outtime);//超过outtimems重传
            }
            else//有未确认的
            {
                //等待超时
                timer->start(outtime);//超过outtimems重传
            }
        }
    }
}

void Sendfile::readPendingDatagrams_recv() //接收
{
    while (udpSocketclient->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocketclient->pendingDatagramSize());
        QHostAddress senderhost;
        quint16 senderPort;
        udpSocketclient->readDatagram(datagram.data(), datagram.size(), &senderhost, &senderPort);

        if("filehead" == QString(datagram).section("##",0,0)) // filehead##文件名##文件大小
        {
//            qDebug() << "收到请求";
            QString path = QFileDialog::getExistingDirectory(NULL,"保存文件","../");
            filenamerecv = path.append("/").append(QString(datagram).section("##",1,1));
            fileSizerecv = QString(datagram).section("##",2,2).toInt();
            ui->le_name->setText(QString(datagram).section("##",1,1));
            ui->le_size->setText(QString::number(fileSizerecv/1024/1024) + "MB");
            filerecv.setFileName( filenamerecv );
            count_recv = 0; //重置接收端序号
            istail = false; //未到文件尾
            for(int i=0; i<N; i++)//初始化接收端
            {
                isrecved[i] = false;
                iswriten[i] = false;
                recv_packages[i].clear();
            }
            isfirst = false; //一次就好
            count_time_recver.start(); //获得当前时间
            sumtime.start();  //获得时间
            sec_recver = 0;
            ui->progressBar->setMaximum(fileSizerecv);
            ui->progressBar->setMinimum(0);
            ui->progressBar->setValue(0);
            if (!filerecv.open(QIODevice::WriteOnly)) //打开要保存的文件
            {
                udpSocketclient->writeDatagram("##file open failed",senderhost ,senderPort);
                return;
            }
            else
            {
                udpSocketclient->writeDatagram("##filehead recved",senderhost ,senderPort);
            }
        }
        else//文件写入部分
        {
            if(!istail) //未写完还需要读入
            {
//                qDebug() << "文件读入";
//                qDebug() << "目前期望收到的大包编号:" << count_recv << "读入数据大小:" << datagram.size();
                QString buf = QString(datagram); //取到数据
                int numofbig = buf.section("&#&#",0,0).toInt();
                int numofsmall = buf.section("&#&#",1,1).toInt();
//                qDebug() << "文件序号确认:" << numofbig << numofsmall; //打印数据
                if(numofbig != count_recv) //收到大包编号不属于当前要处理的不处理
                {
                    //文件顺序不对不处理
                }
                else
                {
                    if(!isrecved[numofsmall]) //未确认收到
                    {
//                            recv_packages[numofsmall].clear();
                        int x = buf.section("&#&#",0,0).size();
                        int y = buf.section("&#&#",1,1).size();
                        recv_packages[numofsmall] =datagram.mid(x+y+8, package_size); //存入缓冲区
                        isrecved[numofsmall] = true; //修改为确认收到
                        udpSocketclient->writeDatagram(QString("%1").arg(numofsmall).toUtf8(),senderhost ,senderPort); //发送 "1 "
//                        qDebug() << "缓冲区数据下标和大小:" << numofsmall << recv_packages[numofsmall].size();
                        int m = 0;
                        while(iswriten[m] && m < N) //找到一个还没写入的下标
                        {
                            m++;
                        }
//                        qDebug() << "还没写入的下标m:" << m;
                        for(int i=m; i<N; i++) //写入所有后面的已经收到但是未写入的包
                        {
                            if(isrecved[i]) //已经收到但是未写入
                            {
                                filerecv.write(recv_packages[i], recv_packages[i].size());
                                iswriten[i] = true; //确认写入标志
//                                qDebug() << "被写入的子包的下标和大小:" << i << recv_packages[i].size();
                                if(recv_packages[i].size() < package_size)
                                {
                                    //写入数据小于package_size，到了文件尾
                                    istail = true;
                                }
                                if(i==N-1) //写入了大包的最后一个小包
                                {
//                                    qDebug() << "写入了大包的最后一个小包,更新速率和进度";
                                    count_recv++;
                                    ui->progressBar->setValue(count_recv*N*package_size);
                                    int ctr =count_time_recver.elapsed();
                                    if(ctr > interval) //速率显示
                                    {
                                        count_time_recver.start();//更新
                                        double speed =  ((sec_recver+1)*N*package_size*1000/ctr/1024);
                                        ui->le_speed->setText(QString("%1 kb/s").arg(speed)); //设置速度
                                        sec_recver = 0;
                                    }
                                    else
                                    {
                                        sec_recver++;
                                    }
                                    for(int i=0; i<N; i++)//初始化接收端
                                    {
                                        isrecved[i] = false;
                                        iswriten[i] = false;
                                        recv_packages[i].clear();
                                    }
                                }
                            }
                            else //未收到不写入
                            {
                                break;
                            }
                        }

                        if(istail)//文件全部收到写入
                        {
                            udpSocketclient->writeDatagram("##file recved",senderhost ,senderPort);
                            ui->progressBar->setValue(fileSizerecv);
                            filerecv.close(); //关闭写入文件
                            ui->textBrowser->append("传输完毕");
                            ui->bt_exit->setEnabled(true);
                            isfirst = true;
                            //计算总时间
                            int sum = sumtime.msecsTo(QTime::currentTime());
                            int sum_s = sum/1000; //1000毫秒
                            long int speedsum = (fileSizerecv*1000/sum)/1024;
                            if(sum_s >= 60)
                            {
                                int sum_m = sum_s/60; //取整
                                sum_s = sum_s%60; //取余
                                QMessageBox::warning(this,"传输完成",QString("共花费时间%1分钟%2秒,平均速率%3 kb/s").arg(sum_m).arg(sum_s).arg(speedsum),QMessageBox::Yes);
                            }
                            else
                            {
                                QMessageBox::warning(this,"传输完成",QString("共花费时间%1秒,平均速率%2 kb/s").arg(sum_s).arg(speedsum),QMessageBox::Yes);
                            }
                            close();
                        }

                    }
                    else
                    {
                        udpSocketclient->writeDatagram(QString("%1").arg(numofsmall).toUtf8(),senderhost ,senderPort); //发送 "1 "
//                        qDebug() << "这个包已经收到过了:" << numofbig << numofsmall;
                    }
                }
            }
            else
            {
                if(isfirst)
                {
                    ui->textBrowser->append("文件已经写完了");
                    isfirst = false;
                }
//                qDebug() << "文件接收完成,已经关闭";
            }
        }
    }
}

void Sendfile::on_bt_exit_clicked()
{
    if(udpSocketclient)
    {
        udpSocketclient->close();
        delete udpSocketclient;
        udpSocketclient = NULL;
    }
    if(udpSocketserver)
    {
        udpSocketserver->close();
        delete udpSocketserver;
        udpSocketserver = NULL;
    }
    close();
}
