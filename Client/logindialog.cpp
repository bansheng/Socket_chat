#include "logindialog.h"
#include "ui_logindialog.h"
#include "register.h"

extern bool isfind;
extern QString loginmessage; //发送给服务器的信息
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    connect(this, &LoginDialog::require_register, this,  &LoginDialog::open_register);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_login_pushButton_clicked()
{
    if (ui->user_lineEdit->text().trimmed() != "" &&
            ui->pwd_lineEdit->text() != "")
    {
        isfind = false;
        loginmessage = QString("login##%1##%2").arg(ui->user_lineEdit->text()).arg(ui->pwd_lineEdit->text());
        close();//都需要直接关闭这个窗口
    }
    else
    {
        QMessageBox::warning(this, "Warning!", "用户名或密码不为空", QMessageBox::Yes);
        ui->user_lineEdit->clear();
        ui->pwd_lineEdit->clear();
        ui->user_lineEdit->setFocus();
    }
}

void LoginDialog::on_register_pushButton_clicked()
{
    emit require_register();
}

void LoginDialog::open_register()
{
    isfind = false;
    Register * dlg = new Register();
    dlg->exec();
    close();//都需要直接关闭这个窗口
}

void LoginDialog::on_find_pushButton_clicked()
{
    if(ui->user_lineEdit->text().trimmed() != "")
    {
        isfind = true;
        loginmessage = QString("find##%1").arg(ui->user_lineEdit->text()); //找回密码
        close(); //都需要直接关闭这个窗口
    }
    else
    {
        QMessageBox::warning(this, "Warning!", "请输入用户名", QMessageBox::Yes);
        ui->user_lineEdit->clear();
        ui->user_lineEdit->setFocus();
    }
}
