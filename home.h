#ifndef HOME_H
#define HOME_H

#include <QDialog>

namespace Ui {
class home;
}

class home : public QDialog
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr);
    ~home();

private slots:
    void on_home_pushButton_clicked();

    void on_recipe_pushButton_2_clicked();

private:
    Ui::home *ui;
};

#endif // HOME_H
