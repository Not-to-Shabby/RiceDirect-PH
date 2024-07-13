#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>

namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_cancel_pushButton_2_clicked();

    void on_signup_pushButton_clicked();

    void on_No_radioButton_clicked();

private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
