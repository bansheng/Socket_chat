/********************************************************************************
** Form generated from reading UI file 'findpassword.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDPASSWORD_H
#define UI_FINDPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_findpassword
{
public:
    QPushButton *bt_find;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *le_question;
    QLineEdit *le_answer;

    void setupUi(QDialog *findpassword)
    {
        if (findpassword->objectName().isEmpty())
            findpassword->setObjectName(QStringLiteral("findpassword"));
        findpassword->resize(465, 358);
        bt_find = new QPushButton(findpassword);
        bt_find->setObjectName(QStringLiteral("bt_find"));
        bt_find->setGeometry(QRect(260, 230, 93, 28));
        label = new QLabel(findpassword);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 90, 72, 15));
        label_2 = new QLabel(findpassword);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 160, 72, 15));
        le_question = new QLineEdit(findpassword);
        le_question->setObjectName(QStringLiteral("le_question"));
        le_question->setEnabled(false);
        le_question->setGeometry(QRect(160, 90, 201, 21));
        le_answer = new QLineEdit(findpassword);
        le_answer->setObjectName(QStringLiteral("le_answer"));
        le_answer->setGeometry(QRect(160, 150, 201, 21));

        retranslateUi(findpassword);

        QMetaObject::connectSlotsByName(findpassword);
    } // setupUi

    void retranslateUi(QDialog *findpassword)
    {
        findpassword->setWindowTitle(QApplication::translate("findpassword", "Dialog", Q_NULLPTR));
        bt_find->setText(QApplication::translate("findpassword", "\346\211\276\345\233\236\345\257\206\347\240\201", Q_NULLPTR));
        label->setText(QApplication::translate("findpassword", "\345\257\206\347\240\201\351\227\256\351\242\230:", Q_NULLPTR));
        label_2->setText(QApplication::translate("findpassword", "\345\257\206\347\240\201\347\255\224\346\241\210\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class findpassword: public Ui_findpassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDPASSWORD_H
