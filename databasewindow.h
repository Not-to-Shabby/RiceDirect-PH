#ifndef DATABASEWINDOW_H
#define DATABASEWINDOW_H

#include <QDialog>

namespace Ui {
class databasewindow;
}

class databasewindow : public QDialog
{
    Q_OBJECT

public:
    explicit databasewindow(QWidget *parent = nullptr);
    ~databasewindow();

private slots:
    void on_check_pushButton_clicked();

    void on_createtbl_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::databasewindow *ui;
};

#endif // DATABASEWINDOW_H
