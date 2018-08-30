/********************************************************************************
** Form generated from reading UI file 'clientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientwidget
{
public:
    QFrame *frame;
    QFrame *frame_ip;
    QLabel *label_3;
    QLineEdit *lineEditIp;
    QLineEdit *lineEditPort;
    QLabel *label_2;
    QPushButton *buttonConnect;
    QLabel *label;
    QPushButton *bt_file_send;
    QFrame *frame_client_on;
    QComboBox *cb_client_on;
    QLineEdit *le_usernum_on;
    QPushButton *bt_connect_client;
    QPushButton *bt_disconnect_client;
    QFrame *frame_message;
    QTextBrowser *textBrowser;
    QPushButton *bt_message_send;
    QLineEdit *le_message;
    QFrame *frame_client_off;
    QComboBox *cb_client_off;
    QLineEdit *le_usernum_off;
    QFrame *frame_state;
    QLineEdit *le_state;
    QLineEdit *le_username;
    QLabel *label_5;
    QPushButton *buttonClose;
    QLabel *label_6;
    QLabel *label_9;
    QLineEdit *le_file_permission;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QWidget *clientwidget)
    {
        if (clientwidget->objectName().isEmpty())
            clientwidget->setObjectName(QStringLiteral("clientwidget"));
        clientwidget->resize(828, 530);
        clientwidget->setAutoFillBackground(false);
        clientwidget->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(clientwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 831, 531));
        frame->setStyleSheet(QStringLiteral("#frame {background-image: url(:/new/prefix1/image/back.jpg);}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_ip = new QFrame(frame);
        frame_ip->setObjectName(QStringLiteral("frame_ip"));
        frame_ip->setGeometry(QRect(240, 10, 231, 111));
        frame_ip->setFrameShape(QFrame::StyledPanel);
        frame_ip->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_ip);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 80, 72, 15));
        lineEditIp = new QLineEdit(frame_ip);
        lineEditIp->setObjectName(QStringLiteral("lineEditIp"));
        lineEditIp->setGeometry(QRect(70, 10, 151, 21));
        lineEditPort = new QLineEdit(frame_ip);
        lineEditPort->setObjectName(QStringLiteral("lineEditPort"));
        lineEditPort->setGeometry(QRect(70, 80, 151, 21));
        label_2 = new QLabel(frame_ip);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 31, 21));
        buttonConnect = new QPushButton(frame_ip);
        buttonConnect->setObjectName(QStringLiteral("buttonConnect"));
        buttonConnect->setGeometry(QRect(100, 40, 91, 31));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 290, 101, 41));
        label->setStyleSheet(QStringLiteral("font: 75 18pt \"Agency FB\";"));
        bt_file_send = new QPushButton(frame);
        bt_file_send->setObjectName(QStringLiteral("bt_file_send"));
        bt_file_send->setGeometry(QRect(660, 480, 93, 28));
        frame_client_on = new QFrame(frame);
        frame_client_on->setObjectName(QStringLiteral("frame_client_on"));
        frame_client_on->setGeometry(QRect(110, 10, 101, 131));
        frame_client_on->setFrameShape(QFrame::StyledPanel);
        frame_client_on->setFrameShadow(QFrame::Raised);
        cb_client_on = new QComboBox(frame_client_on);
        cb_client_on->setObjectName(QStringLiteral("cb_client_on"));
        cb_client_on->setGeometry(QRect(0, 30, 101, 21));
        le_usernum_on = new QLineEdit(frame_client_on);
        le_usernum_on->setObjectName(QStringLiteral("le_usernum_on"));
        le_usernum_on->setEnabled(false);
        le_usernum_on->setGeometry(QRect(0, 0, 101, 21));
        bt_connect_client = new QPushButton(frame_client_on);
        bt_connect_client->setObjectName(QStringLiteral("bt_connect_client"));
        bt_connect_client->setGeometry(QRect(0, 60, 101, 31));
        bt_disconnect_client = new QPushButton(frame_client_on);
        bt_disconnect_client->setObjectName(QStringLiteral("bt_disconnect_client"));
        bt_disconnect_client->setGeometry(QRect(0, 100, 101, 31));
        frame_message = new QFrame(frame);
        frame_message->setObjectName(QStringLiteral("frame_message"));
        frame_message->setGeometry(QRect(400, 130, 391, 341));
        frame_message->setFrameShape(QFrame::StyledPanel);
        frame_message->setFrameShadow(QFrame::Raised);
        textBrowser = new QTextBrowser(frame_message);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 391, 291));
        textBrowser->setStyleSheet(QString::fromUtf8("selection-color: rgb(85, 255, 127);\n"
"background-image: url(:/new/prefix1/image/766971.jpg);\n"
"font: 12pt \"\346\245\267\344\275\223\";"));
        bt_message_send = new QPushButton(frame_message);
        bt_message_send->setObjectName(QStringLiteral("bt_message_send"));
        bt_message_send->setGeometry(QRect(260, 310, 93, 28));
        le_message = new QLineEdit(frame_message);
        le_message->setObjectName(QStringLiteral("le_message"));
        le_message->setGeometry(QRect(0, 310, 221, 31));
        frame_client_off = new QFrame(frame);
        frame_client_off->setObjectName(QStringLiteral("frame_client_off"));
        frame_client_off->setGeometry(QRect(110, 150, 101, 51));
        frame_client_off->setFrameShape(QFrame::StyledPanel);
        frame_client_off->setFrameShadow(QFrame::Raised);
        cb_client_off = new QComboBox(frame_client_off);
        cb_client_off->setObjectName(QStringLiteral("cb_client_off"));
        cb_client_off->setGeometry(QRect(0, 30, 101, 21));
        le_usernum_off = new QLineEdit(frame_client_off);
        le_usernum_off->setObjectName(QStringLiteral("le_usernum_off"));
        le_usernum_off->setEnabled(false);
        le_usernum_off->setGeometry(QRect(0, 0, 101, 21));
        frame_state = new QFrame(frame);
        frame_state->setObjectName(QStringLiteral("frame_state"));
        frame_state->setGeometry(QRect(470, 10, 351, 111));
        frame_state->setFrameShape(QFrame::StyledPanel);
        frame_state->setFrameShadow(QFrame::Raised);
        le_state = new QLineEdit(frame_state);
        le_state->setObjectName(QStringLiteral("le_state"));
        le_state->setEnabled(false);
        le_state->setGeometry(QRect(140, 10, 91, 21));
        le_username = new QLineEdit(frame_state);
        le_username->setObjectName(QStringLiteral("le_username"));
        le_username->setEnabled(false);
        le_username->setGeometry(QRect(140, 40, 91, 21));
        label_5 = new QLabel(frame_state);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 10, 111, 21));
        buttonClose = new QPushButton(frame_state);
        buttonClose->setObjectName(QStringLiteral("buttonClose"));
        buttonClose->setGeometry(QRect(240, 10, 111, 21));
        label_6 = new QLabel(frame_state);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 40, 72, 15));
        label_9 = new QLabel(frame_state);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(0, 70, 91, 16));
        le_file_permission = new QLineEdit(frame_state);
        le_file_permission->setObjectName(QStringLiteral("le_file_permission"));
        le_file_permission->setEnabled(false);
        le_file_permission->setGeometry(QRect(140, 70, 91, 21));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 10, 101, 20));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 150, 101, 20));
        frame_ip->raise();
        label->raise();
        bt_file_send->raise();
        frame_client_on->raise();
        frame_message->raise();
        frame_client_off->raise();
        frame_state->raise();
        label_7->raise();
        label_8->raise();
        label_8->raise();

        retranslateUi(clientwidget);

        QMetaObject::connectSlotsByName(clientwidget);
    } // setupUi

    void retranslateUi(QWidget *clientwidget)
    {
        clientwidget->setWindowTitle(QApplication::translate("clientwidget", "clientwidget", Q_NULLPTR));
        label_3->setText(QApplication::translate("clientwidget", "\347\253\257\345\217\243\345\217\267:", Q_NULLPTR));
        label_2->setText(QApplication::translate("clientwidget", "ip:", Q_NULLPTR));
        buttonConnect->setText(QApplication::translate("clientwidget", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        label->setText(QApplication::translate("clientwidget", "\345\256\242\346\210\267\347\253\257", Q_NULLPTR));
        bt_file_send->setText(QApplication::translate("clientwidget", "\345\217\221\351\200\201\346\226\207\344\273\266", Q_NULLPTR));
        cb_client_on->clear();
        cb_client_on->insertItems(0, QStringList()
         << QApplication::translate("clientwidget", "\357\274\210\346\227\240\357\274\211", Q_NULLPTR)
        );
        bt_connect_client->setText(QApplication::translate("clientwidget", "\350\277\236\346\216\245\345\234\250\347\272\277\347\224\250\346\210\267", Q_NULLPTR));
        bt_disconnect_client->setText(QApplication::translate("clientwidget", "\346\226\255\345\274\200\345\234\250\347\272\277\350\277\236\346\216\245", Q_NULLPTR));
        bt_message_send->setText(QApplication::translate("clientwidget", "\345\217\221\351\200\201\346\266\210\346\201\257", Q_NULLPTR));
        cb_client_off->clear();
        cb_client_off->insertItems(0, QStringList()
         << QApplication::translate("clientwidget", "\357\274\210\346\227\240\357\274\211", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("clientwidget", "\346\234\215\345\212\241\345\231\250\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        buttonClose->setText(QApplication::translate("clientwidget", "\346\226\255\345\274\200\346\234\215\345\212\241\345\231\250\350\277\236\346\216\245", Q_NULLPTR));
        label_6->setText(QApplication::translate("clientwidget", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("clientwidget", "\347\202\271\345\257\271\347\202\271\350\277\236\346\216\245\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("clientwidget", "\345\234\250\347\272\277\347\224\250\346\210\267\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("clientwidget", "\347\246\273\347\272\277\347\224\250\346\210\267\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class clientwidget: public Ui_clientwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
