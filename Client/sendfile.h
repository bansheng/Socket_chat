#ifndef SENDFILE_H
#define SENDFILE_H

#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QUdpSocket>
#include <QTimer>

namespace Ui {
class Sendfile;
}

class Sendfile : public QDialog
{
    Q_OBJECT

public:
    explicit Sendfile(QWidget *parent = 0);
    ~Sendfile();

private slots:
    void on_buttonChooseFile_clicked();

    void on_butttonSendFile_clicked();

    void sendData();

    void readPendingDatagrams_send();

    void readPendingDatagrams_recv();

    void on_bt_exit_clicked();

private:
    Ui::Sendfile *ui;
    QUdpSocket* udpSocketserver;      //socket
    QUdpSocket* udpSocketclient;      //socket
    QFile filesend;             //文件对象
    QString filesend_information; //发送文件头中的文件基本信息
    QFile filerecv;
    QString fileNamesend;       //文件名字
    QString filenamerecv;
    qint64 fileSizesend;        //文件大小
    qint64 fileSizerecv;     //接收文件大小
    qint64 recvSize;        //已经接收大小
    qint64 sendSize;        //已经发送大小
    QTimer* timer;          //倒计时器，测定超时
    QHostAddress recverhost;
    quint16 recverPort = 12580;
//    QHostAddress senderhost;
//    quint16 senderPort;
    bool isfirst; //文件已经接收完毕,第一次收到重复的包，需要提示，后面不再提示收到重复的包
};

#endif // SENDFILE_H
