#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "home.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_database_pushButton_clicked();

    void on_create_pushButton_3_clicked();

    void on_login_pushButton_clicked();

    void on_guest_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    home *Home;
};
#endif // MAINWINDOW_H
