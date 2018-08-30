/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_server
{
public:
    QLabel *label;
    QTextBrowser *textBrowser;
    QFrame *frame_client_on;
    QLineEdit *le_usernum_on;
    QLabel *label_7;
    QTextBrowser *tb_on;
    QFrame *frame_client_off;
    QLabel *label_8;
    QLineEdit *le_usernum_off;
    QTextBrowser *tb_off;
    QPushButton *bt_save;

    void setupUi(QWidget *server)
    {
        if (server->objectName().isEmpty())
            server->setObjectName(QStringLiteral("server"));
        server->resize(725, 475);
        server->setStyleSheet(QStringLiteral("#server {background-image: url(:/new/prefix1/image/1106022.jpg);}"));
        label = new QLabel(server);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(290, 20, 91, 31));
        label->setStyleSheet(QStringLiteral("font: 75 14pt \"Agency FB\";"));
        textBrowser = new QTextBrowser(server);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 70, 281, 291));
        frame_client_on = new QFrame(server);
        frame_client_on->setObjectName(QStringLiteral("frame_client_on"));
        frame_client_on->setGeometry(QRect(290, 70, 211, 291));
        frame_client_on->setFrameShape(QFrame::StyledPanel);
        frame_client_on->setFrameShadow(QFrame::Raised);
        le_usernum_on = new QLineEdit(frame_client_on);
        le_usernum_on->setObjectName(QStringLiteral("le_usernum_on"));
        le_usernum_on->setEnabled(false);
        le_usernum_on->setGeometry(QRect(110, 10, 81, 21));
        label_7 = new QLabel(frame_client_on);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 10, 101, 20));
        tb_on = new QTextBrowser(frame_client_on);
        tb_on->setObjectName(QStringLiteral("tb_on"));
        tb_on->setGeometry(QRect(10, 50, 171, 211));
        frame_client_off = new QFrame(server);
        frame_client_off->setObjectName(QStringLiteral("frame_client_off"));
        frame_client_off->setGeometry(QRect(510, 70, 211, 291));
        frame_client_off->setFrameShape(QFrame::StyledPanel);
        frame_client_off->setFrameShadow(QFrame::Raised);
        label_8 = new QLabel(frame_client_off);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(1, 10, 101, 20));
        le_usernum_off = new QLineEdit(frame_client_off);
        le_usernum_off->setObjectName(QStringLiteral("le_usernum_off"));
        le_usernum_off->setEnabled(false);
        le_usernum_off->setGeometry(QRect(110, 10, 81, 21));
        tb_off = new QTextBrowser(frame_client_off);
        tb_off->setObjectName(QStringLiteral("tb_off"));
        tb_off->setGeometry(QRect(10, 50, 171, 211));
        bt_save = new QPushButton(server);
        bt_save->setObjectName(QStringLiteral("bt_save"));
        bt_save->setGeometry(QRect(310, 400, 93, 28));

        retranslateUi(server);

        QMetaObject::connectSlotsByName(server);
    } // setupUi

    void retranslateUi(QWidget *server)
    {
        server->setWindowTitle(QApplication::translate("server", "server", Q_NULLPTR));
        label->setText(QApplication::translate("server", "\346\234\215\345\212\241\345\231\250\347\253\257", Q_NULLPTR));
        label_7->setText(QApplication::translate("server", "\345\234\250\347\272\277\347\224\250\346\210\267\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("server", "\347\246\273\347\272\277\347\224\250\346\210\267\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        bt_save->setText(QApplication::translate("server", "\344\277\235\345\255\230\347\224\250\346\210\267\344\277\241\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class server: public Ui_server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
