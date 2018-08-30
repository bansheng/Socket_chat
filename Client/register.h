#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();



private slots:

    void on_Button_accept_clicked();

    void on_Button_reject_clicked();

    void on_Button_reg_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
