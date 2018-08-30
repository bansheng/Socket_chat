#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QTimer>

#define BUF_SIZE 1024*4

namespace Ui {
class clientwidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = 0);
    ~ClientWidget();

private slots:
    void on_buttonConnect_clicked();

    void on_buttonClose_clicked();


    void on_cb_client_off_currentIndexChanged(int index);

    void on_cb_client_on_currentIndexChanged(int index);

    void on_bt_message_send_clicked();

    void on_bt_connect_client_clicked();

    void on_bt_disconnect_client_clicked();

    void on_bt_file_send_clicked();

    void connect_failure();

private:
    Ui::clientwidget *ui;
    QTcpServer * tcpServer; //监听
    QTcpSocket * tcpSocket; //通信
    QTcpSocket * tcpSocket_client; //客户机通讯

    QTimer* timer;           //定时器
};

#endif // CLIENTWIDGET_H
