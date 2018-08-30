#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QTimer>

const int M=20;

namespace Ui {
class server;
}

class server : public QWidget
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = 0);
    ~server();
    void userload();
    void handlemessage(QString myname, QTcpSocket *a);
    void userstateupdate();

private slots:
    void on_bt_save_clicked();

private:
    Ui::server *ui;
    QTcpServer * tcpServer; //监听
    QTcpSocket * tcpSocket[M]; //通信
    QTimer timer;           //定时器
};

#endif // SERVER_H
