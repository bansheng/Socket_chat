/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *label_3;
    QSplitter *splitter;
    QLabel *label_2;
    QLabel *label;
    QSplitter *splitter_2;
    QLineEdit *user_lineEdit;
    QLineEdit *pwd_lineEdit;
    QPushButton *login_pushButton;
    QPushButton *register_pushButton;
    QPushButton *find_pushButton;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(465, 323);
        label_3 = new QLabel(LoginDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 40, 221, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 25 14pt \"\347\255\211\347\272\277 Light\";"));
        label_3->setAlignment(Qt::AlignCenter);
        splitter = new QSplitter(LoginDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(91, 89, 51, 81));
        splitter->setOrientation(Qt::Vertical);
        label_2 = new QLabel(splitter);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\347\255\211\347\272\277 Light\";"));
        splitter->addWidget(label_2);
        label = new QLabel(splitter);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\347\255\211\347\272\277 Light\";"));
        splitter->addWidget(label);
        splitter_2 = new QSplitter(LoginDialog);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(140, 90, 231, 81));
        splitter_2->setOrientation(Qt::Vertical);
        user_lineEdit = new QLineEdit(splitter_2);
        user_lineEdit->setObjectName(QStringLiteral("user_lineEdit"));
        user_lineEdit->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\347\255\211\347\272\277 Light\";"));
        splitter_2->addWidget(user_lineEdit);
        pwd_lineEdit = new QLineEdit(splitter_2);
        pwd_lineEdit->setObjectName(QStringLiteral("pwd_lineEdit"));
        pwd_lineEdit->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\347\255\211\347\272\277 Light\";"));
        pwd_lineEdit->setEchoMode(QLineEdit::Password);
        splitter_2->addWidget(pwd_lineEdit);
        login_pushButton = new QPushButton(LoginDialog);
        login_pushButton->setObjectName(QStringLiteral("login_pushButton"));
        login_pushButton->setGeometry(QRect(60, 190, 101, 51));
        login_pushButton->setStyleSheet(QStringLiteral(""));
        register_pushButton = new QPushButton(LoginDialog);
        register_pushButton->setObjectName(QStringLiteral("register_pushButton"));
        register_pushButton->setGeometry(QRect(180, 190, 111, 51));
        register_pushButton->setStyleSheet(QStringLiteral(""));
        find_pushButton = new QPushButton(LoginDialog);
        find_pushButton->setObjectName(QStringLiteral("find_pushButton"));
        find_pushButton->setGeometry(QRect(310, 190, 111, 51));
        find_pushButton->setStyleSheet(QStringLiteral(""));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("LoginDialog", "\346\254\242\350\277\216\344\275\277\347\224\250\345\222\232\345\222\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoginDialog", "\350\264\246\346\210\267", Q_NULLPTR));
        label->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201", Q_NULLPTR));
        user_lineEdit->setPlaceholderText(QApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", Q_NULLPTR));
        pwd_lineEdit->setPlaceholderText(QApplication::translate("LoginDialog", "\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        login_pushButton->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", Q_NULLPTR));
        register_pushButton->setText(QApplication::translate("LoginDialog", "\346\263\250\345\206\214", Q_NULLPTR));
        find_pushButton->setText(QApplication::translate("LoginDialog", "\346\211\276\345\233\236\345\257\206\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
