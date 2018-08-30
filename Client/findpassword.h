#ifndef FINDPASSWORD_H
#define FINDPASSWORD_H

#include <QDialog>

namespace Ui {
class findpassword;
}

class findpassword : public QDialog
{
    Q_OBJECT

public:
    explicit findpassword(QWidget *parent = 0);
    ~findpassword();

private slots:
    void on_le_answer_textChanged(const QString &arg1);

    void on_bt_find_clicked();

private:
    Ui::findpassword *ui;
};

#endif // FINDPASSWORD_H
