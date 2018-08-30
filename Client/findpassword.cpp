#include "findpassword.h"
#include "ui_findpassword.h"
#include <QMessageBox>
extern QString myquestion;
extern QString myanswer;
findpassword::findpassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::findpassword)
{
    ui->setupUi(this);
    ui->bt_find->setEnabled(false);
    ui->le_question->setText(myquestion);
}

findpassword::~findpassword()
{
    delete ui;
}

void findpassword::on_le_answer_textChanged(const QString &arg1)
{
    if(arg1.trimmed()=="")
    {
        QMessageBox::warning(this, "Warning!", "答案不为空！", QMessageBox::Yes);
    }
    else
        ui->bt_find->setEnabled(true);
}

void findpassword::on_bt_find_clicked()
{
    myanswer = QString("answer##%1").arg(ui->le_answer->text());
    close();
}

