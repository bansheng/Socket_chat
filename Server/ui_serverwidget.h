/********************************************************************************
** Form generated from reading UI file 'serverwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWIDGET_H
#define UI_SERVERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serverwidget
{
public:
    QLabel *label;
    QTextEdit *textEdit;
    QPushButton *buttonChooseFile;
    QPushButton *butttonSendFile;

    void setupUi(QWidget *serverwidget)
    {
        if (serverwidget->objectName().isEmpty())
            serverwidget->setObjectName(QStringLiteral("serverwidget"));
        serverwidget->resize(657, 577);
        label = new QLabel(serverwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(240, 60, 141, 71));
        label->setStyleSheet(QStringLiteral("font: 75 14pt \"Agency FB\";"));
        textEdit = new QTextEdit(serverwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(120, 140, 391, 301));
        buttonChooseFile = new QPushButton(serverwidget);
        buttonChooseFile->setObjectName(QStringLiteral("buttonChooseFile"));
        buttonChooseFile->setGeometry(QRect(120, 490, 93, 28));
        butttonSendFile = new QPushButton(serverwidget);
        butttonSendFile->setObjectName(QStringLiteral("butttonSendFile"));
        butttonSendFile->setGeometry(QRect(420, 490, 93, 28));

        retranslateUi(serverwidget);

        QMetaObject::connectSlotsByName(serverwidget);
    } // setupUi

    void retranslateUi(QWidget *serverwidget)
    {
        serverwidget->setWindowTitle(QApplication::translate("serverwidget", "serverwidget", Q_NULLPTR));
        label->setText(QApplication::translate("serverwidget", "\346\234\215\345\212\241\345\231\250\347\253\257", Q_NULLPTR));
        buttonChooseFile->setText(QApplication::translate("serverwidget", "\351\200\211\346\213\251\346\226\207\344\273\266", Q_NULLPTR));
        butttonSendFile->setText(QApplication::translate("serverwidget", "\345\274\200\345\247\213\344\274\240\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class serverwidget: public Ui_serverwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWIDGET_H
