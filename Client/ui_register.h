/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QSplitter *splitter_3;
    QSplitter *splitter_5;
    QRadioButton *Button_accept;
    QRadioButton *Button_reject;
    QPushButton *Button_reg;
    QTextBrowser *text_note;
    QFrame *verticalFrame1;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *verticalFrame;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *le_user;
    QLineEdit *le_password;
    QLineEdit *le_question;
    QLineEdit *le_answer;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(538, 398);
        splitter_3 = new QSplitter(Register);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(190, 250, 125, 70));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter_3->sizePolicy().hasHeightForWidth());
        splitter_3->setSizePolicy(sizePolicy);
        splitter_3->setMinimumSize(QSize(125, 70));
        splitter_3->setMaximumSize(QSize(125, 71));
        splitter_3->setAutoFillBackground(true);
        splitter_3->setStyleSheet(QStringLiteral(""));
        splitter_3->setOrientation(Qt::Vertical);
        splitter_5 = new QSplitter(splitter_3);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setMinimumSize(QSize(125, 30));
        splitter_5->setOrientation(Qt::Horizontal);
        Button_accept = new QRadioButton(splitter_5);
        Button_accept->setObjectName(QStringLiteral("Button_accept"));
        sizePolicy.setHeightForWidth(Button_accept->sizePolicy().hasHeightForWidth());
        Button_accept->setSizePolicy(sizePolicy);
        Button_accept->setMinimumSize(QSize(60, 30));
        Button_accept->setMaximumSize(QSize(60, 30));
        Button_accept->setStyleSheet(QStringLiteral(""));
        splitter_5->addWidget(Button_accept);
        Button_reject = new QRadioButton(splitter_5);
        Button_reject->setObjectName(QStringLiteral("Button_reject"));
        sizePolicy.setHeightForWidth(Button_reject->sizePolicy().hasHeightForWidth());
        Button_reject->setSizePolicy(sizePolicy);
        Button_reject->setMinimumSize(QSize(60, 30));
        Button_reject->setMaximumSize(QSize(60, 30));
        splitter_5->addWidget(Button_reject);
        splitter_3->addWidget(splitter_5);
        Button_reg = new QPushButton(splitter_3);
        Button_reg->setObjectName(QStringLiteral("Button_reg"));
        sizePolicy.setHeightForWidth(Button_reg->sizePolicy().hasHeightForWidth());
        Button_reg->setSizePolicy(sizePolicy);
        Button_reg->setMinimumSize(QSize(84, 35));
        Button_reg->setMaximumSize(QSize(125, 35));
        Button_reg->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        splitter_3->addWidget(Button_reg);
        text_note = new QTextBrowser(Register);
        text_note->setObjectName(QStringLiteral("text_note"));
        text_note->setGeometry(QRect(300, 50, 211, 151));
        text_note->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\347\255\211\347\272\277 Light\";"));
        verticalFrame1 = new QFrame(Register);
        verticalFrame1->setObjectName(QStringLiteral("verticalFrame1"));
        verticalFrame1->setGeometry(QRect(30, 50, 81, 161));
        verticalLayout = new QVBoxLayout(verticalFrame1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(verticalFrame1);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(verticalFrame1);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalFrame1);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(verticalFrame1);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        verticalFrame = new QFrame(Register);
        verticalFrame->setObjectName(QStringLiteral("verticalFrame"));
        verticalFrame->setGeometry(QRect(120, 50, 151, 161));
        verticalLayout_2 = new QVBoxLayout(verticalFrame);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        le_user = new QLineEdit(verticalFrame);
        le_user->setObjectName(QStringLiteral("le_user"));

        verticalLayout_2->addWidget(le_user);

        le_password = new QLineEdit(verticalFrame);
        le_password->setObjectName(QStringLiteral("le_password"));
        le_password->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(le_password);

        le_question = new QLineEdit(verticalFrame);
        le_question->setObjectName(QStringLiteral("le_question"));

        verticalLayout_2->addWidget(le_question);

        le_answer = new QLineEdit(verticalFrame);
        le_answer->setObjectName(QStringLiteral("le_answer"));

        verticalLayout_2->addWidget(le_answer);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", Q_NULLPTR));
        Button_accept->setText(QApplication::translate("Register", "\345\220\214\346\204\217", Q_NULLPTR));
        Button_reject->setText(QApplication::translate("Register", "\346\213\222\347\273\235", Q_NULLPTR));
        Button_reg->setText(QApplication::translate("Register", "\346\263\250\345\206\214", Q_NULLPTR));
        text_note->setHtml(QApplication::translate("Register", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\347\255\211\347\272\277 Light'; font-size:11pt; font-weight:24; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:9pt; font-weight:400;\">\346\263\250\345\206\214\351\241\273\347\237\245\357\274\232</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:9pt; font-weight:400;\">\345\220\214\345\255\246\346\202\250\345\245\275\357\274\201\346\254\242\350\277\216\345\212\240\345\205\245\345\222\232\345\222\232\343\200\202</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-"
                        "top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:9pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:9pt; font-weight:400;\">\344\273\245\344\270\212\344\276\277\346\230\257\346\202\250\351\234\200\350\246\201\351\201\265\345\276\252\347\232\204\344\275\277\347\224\250\350\247\204\345\210\231\357\274\214\345\220\214\346\204\217\346\235\241\346\226\207\357\274\214\346\211\215\345\217\257\347\273\247\347\273\255\346\263\250\345\206\214\357\274\201</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("Register", "\345\257\206\347\240\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("Register", "\345\257\206\347\240\201\351\227\256\351\242\230", Q_NULLPTR));
        label_4->setText(QApplication::translate("Register", "\345\257\206\347\240\201\347\255\224\346\241\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
