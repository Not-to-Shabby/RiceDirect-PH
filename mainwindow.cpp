#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>
#include "databasewindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "signup.h"
#include "home.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("D:/QT Project/RiceDirect/Rice Logo(3).png");
    ui->logo_label->setPixmap(pix.scaled(500,480,Qt::KeepAspectRatio));
    setWindowTitle("RiceDirectPH Login");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_database_pushButton_clicked()
{
    databasewindow database;
    database.setModal(true);
    database.exec();
}


void MainWindow::on_create_pushButton_3_clicked()
{
    signup signup;
    signup.setModal(true);
    signup.exec();
}


void MainWindow::on_login_pushButton_clicked()
{
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
    }

    QSqlDatabase sqldb = QSqlDatabase::addDatabase("QSQLITE");
    sqldb.setDatabaseName("C:/Users/Perch/Desktop/SQLiteStudio/ricedb.sqlite");

    if (!sqldb.open()) {
        ui->status_label_2->setText("Failed to open database");
        return;
    }

    QString email = ui->email_lineEdit->text();
    QString password = ui->password_lineEdit_2->text();

    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE email = :email");
    query.bindValue(":email", email);

    if (!query.exec()) {
        ui->status_label_2->setText("Query execution failed: " + query.lastError().text());
        return;
    }

    if (query.next()) {
        QString storedPassword = query.value(0).toString();

        // Check if the entered password matches the stored password
        if (password == storedPassword) {
            ui->status_label_2->setText("Login successful. You are now logged in.");
            QTimer::singleShot(300, this, [this]() {  // Delay for 0.3 seconds
                this->hide();  // Hide the login window after the delay
                Home = new home(this);  // Ensure Home is managed properly to avoid memory leaks
                Home->show();  // Show the home window
            });
            // Additional logic for successful login can be added here, like opening a new window
        } else {
            ui->status_label_2->setText("Incorrect password.");
        }
    } else {
        ui->status_label_2->setText("No user found with the given email.");
    }
}


void MainWindow::on_guest_pushButton_4_clicked()
{
    this->hide();  // Hide the login window after the delay
    Home = new home(this);  // Ensure Home is managed properly to avoid memory leaks
    Home->show();
}

