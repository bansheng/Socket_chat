/********************************************************************************
** Form generated from reading UI file 'sendfile.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDFILE_H
#define UI_SENDFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Sendfile
{
public:
    QFrame *frame_file;
    QPushButton *butttonSendFile;
    QProgressBar *progressBar;
    QPushButton *buttonChooseFile;
    QLabel *label_process;
    QLineEdit *le_name;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *le_size;
    QTextBrowser *textBrowser;
    QPushButton *bt_exit;
    QLabel *label_recvip;
    QLineEdit *le_recv_ip;
    QLabel *label_3;
    QLineEdit *le_speed;

    void setupUi(QDialog *Sendfile)
    {
        if (Sendfile->objectName().isEmpty())
            Sendfile->setObjectName(QStringLiteral("Sendfile"));
        Sendfile->resize(486, 439);
        frame_file = new QFrame(Sendfile);
        frame_file->setObjectName(QStringLiteral("frame_file"));
        frame_file->setGeometry(QRect(50, 110, 361, 91));
        frame_file->setFrameShape(QFrame::StyledPanel);
        frame_file->setFrameShadow(QFrame::Raised);
        butttonSendFile = new QPushButton(frame_file);
        butttonSendFile->setObjectName(QStringLiteral("butttonSendFile"));
        butttonSendFile->setGeometry(QRect(210, 10, 93, 28));
        progressBar = new QProgressBar(frame_file);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(110, 60, 241, 21));
        progressBar->setValue(0);
        buttonChooseFile = new QPushButton(frame_file);
        buttonChooseFile->setObjectName(QStringLiteral("buttonChooseFile"));
        buttonChooseFile->setGeometry(QRect(30, 10, 93, 28));
        label_process = new QLabel(frame_file);
        label_process->setObjectName(QStringLiteral("label_process"));
        label_process->setGeometry(QRect(0, 60, 72, 15));
        le_name = new QLineEdit(Sendfile);
        le_name->setObjectName(QStringLiteral("le_name"));
        le_name->setEnabled(false);
        le_name->setGeometry(QRect(140, 20, 241, 21));
        label = new QLabel(Sendfile);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 20, 72, 15));
        label_2 = new QLabel(Sendfile);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 50, 101, 21));
        le_size = new QLineEdit(Sendfile);
        le_size->setObjectName(QStringLiteral("le_size"));
        le_size->setEnabled(false);
        le_size->setGeometry(QRect(140, 50, 113, 21));
        textBrowser = new QTextBrowser(Sendfile);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(50, 210, 361, 191));
        bt_exit = new QPushButton(Sendfile);
        bt_exit->setObjectName(QStringLiteral("bt_exit"));
        bt_exit->setGeometry(QRect(350, 410, 93, 28));
        label_recvip = new QLabel(Sendfile);
        label_recvip->setObjectName(QStringLiteral("label_recvip"));
        label_recvip->setGeometry(QRect(40, 80, 81, 16));
        le_recv_ip = new QLineEdit(Sendfile);
        le_recv_ip->setObjectName(QStringLiteral("le_recv_ip"));
        le_recv_ip->setEnabled(false);
        le_recv_ip->setGeometry(QRect(140, 80, 113, 21));
        label_3 = new QLabel(Sendfile);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(340, 50, 111, 31));
        le_speed = new QLineEdit(Sendfile);
        le_speed->setObjectName(QStringLiteral("le_speed"));
        le_speed->setEnabled(false);
        le_speed->setGeometry(QRect(330, 80, 113, 21));

        retranslateUi(Sendfile);

        QMetaObject::connectSlotsByName(Sendfile);
    } // setupUi

    void retranslateUi(QDialog *Sendfile)
    {
        Sendfile->setWindowTitle(QApplication::translate("Sendfile", "Dialog", Q_NULLPTR));
        butttonSendFile->setText(QApplication::translate("Sendfile", "\345\274\200\345\247\213\344\274\240\351\200\201", Q_NULLPTR));
        buttonChooseFile->setText(QApplication::translate("Sendfile", "\351\200\211\346\213\251\346\226\207\344\273\266", Q_NULLPTR));
        label_process->setText(QApplication::translate("Sendfile", "\345\217\221\351\200\201\350\277\233\345\272\246\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("Sendfile", "\346\226\207\344\273\266\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Sendfile", "\346\226\207\344\273\266\346\200\273\345\244\247\345\260\217\357\274\232", Q_NULLPTR));
        le_size->setText(QApplication::translate("Sendfile", "0", Q_NULLPTR));
        bt_exit->setText(QApplication::translate("Sendfile", "\351\200\200\345\207\272", Q_NULLPTR));
        label_recvip->setText(QApplication::translate("Sendfile", "\347\233\256\347\232\204\344\270\273\346\234\272ip\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Sendfile", "\346\226\207\344\273\266\344\274\240\350\276\223\351\200\237\347\216\207:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Sendfile: public Ui_Sendfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDFILE_H
