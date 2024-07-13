#include "databasewindow.h"
#include "ui_databasewindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

databasewindow::databasewindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::databasewindow)
{
    ui->setupUi(this);
    setWindowTitle("RiceDirectPH Database");
}

databasewindow::~databasewindow()
{
    delete ui;
}

void databasewindow::on_check_pushButton_clicked()
{
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
    }

    QSqlDatabase sqldb = QSqlDatabase::addDatabase("QSQLITE");
    sqldb.setDatabaseName("C:/Users/Perch/Desktop/SQLiteStudio/ricedb.sqlite");

    if (!sqldb.open()) {
        ui->status_label->setText("Database is not connected");
    } else {
        ui->status_label->setText("Database is connected");
    }
}

void databasewindow::on_createtbl_pushButton_2_clicked()
{
    QSqlQuery query;
    bool success = query.exec("CREATE TABLE users ("
                              "user_id INTEGER PRIMARY KEY AUTOINCREMENT, "  // Note the change here for SQLite
                              "first_name VARCHAR(255), "
                              "lastname VARCHAR(255), "
                              "email VARCHAR(255), "
                              "age INTEGER, "
                              "address VARCHAR(255), "
                              "user_type TEXT CHECK(user_type IN ('customer', 'farmer')), "  // SQLite doesn't support ENUM
                              "password VARCHAR(255))");

    if (success) {
        ui->status_label->setText("Table is created");
    } else {
        ui->status_label->setText("Failed to create table: " + query.lastError().text());
    }

}


void databasewindow::on_pushButton_3_clicked()
{
    QSqlQuery query;
    bool success = query.exec("DROP TABLE users");

    if (success) {
        ui->status_label->setText("Table is dropped");
    } else {
        ui->status_label->setText("Failed to create table: " + query.lastError().text());
    }
}

