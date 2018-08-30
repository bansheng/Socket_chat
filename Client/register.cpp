#include "register.h"
#include "ui_register.h"
#include <QTextStream>
#include <QMessageBox>
extern QString loginmessage; //发送给服务器的信息
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->Button_reg->setEnabled(false);
}

Register::~Register()
{
    delete ui;
}

void Register::on_Button_accept_clicked()
{
    ui->Button_reg->setText("注册");
    ui->Button_reg->setEnabled(true);
}

void Register::on_Button_reject_clicked()
{
    ui->Button_reg->setText("退出");
    ui->Button_reg->setEnabled(true);
}

void Register::on_Button_reg_clicked()
{
    if (ui->Button_reg->text() == "退出")  //退出
        close();
    else if(ui->le_user->text().trimmed() != "" && ui->le_password->text().trimmed() != "" && ui->le_question->text().trimmed() != "" && ui->le_answer->text().trimmed() != "" )
    {
        loginmessage = QString("register##%1##%2##%3##%4").arg(ui->le_user->text())
                .arg(ui->le_password->text()).arg(ui->le_question->text()).arg(ui->le_answer->text());
        close();
    }
    else
    {
        QMessageBox::warning(this, "Warning!", "任何一项不能为空", QMessageBox::Yes);
        ui->le_user->clear();
        ui->le_password->clear();
        ui->le_question->clear();
        ui->le_answer->clear();
        ui->le_user->setFocus();
    }
}
