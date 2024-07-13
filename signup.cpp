#include "signup.h"
#include "ui_signup.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTimer>

signup::signup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signup)
{
    ui->setupUi(this);
    setWindowTitle("RiceDirectPH Create an Account");
}

signup::~signup()
{
    delete ui;

}

void signup::on_cancel_pushButton_2_clicked()
{
    this->close();
}


void signup::on_signup_pushButton_clicked()
{
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
    }

    QSqlDatabase sqldb = QSqlDatabase::addDatabase("QSQLITE");
    sqldb.setDatabaseName("C:/Users/Perch/Desktop/SQLiteStudio/ricedb.sqlite");

    if (!sqldb.open()) {
        ui->signup_complete_label_2->setText("Failed to open database");
        return;
    }

    QString first_name = ui->fname_lineEdit->text();
    QString last_name = ui->lname_lineEdit_2->text();
    QString address = ui->address_lineEdit_3->text();
    QString email = ui->email_lineEdit_4->text();
    int age = ui->age_spinBox->value();
    QString password1 = ui->pass_lineEdit_6->text();
    QString password2 = ui->retype_lineEdit_7->text();  // Corrected assuming it’s a QLineEdit
    QString userType = ui->No_radioButton->isChecked() ? "customer" : "farmer";  // Handling user type based on radio button selection

    // Check if the passwords match
    if (password1 != password2) {
        ui->signup_complete_label_2->setText("Passwords do not match.");
        sqldb.close();
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO users (first_name, lastname, address, email, age, password, user_type) "
                  "VALUES (:first_name, :lastname, :address, :email, :age, :password, :user_type)");
    query.bindValue(":first_name", first_name);
    query.bindValue(":lastname", last_name);
    query.bindValue(":address", address);
    query.bindValue(":email", email);
    query.bindValue(":age", age);
    query.bindValue(":password", password1);  // Note: In a real application, store a hashed password!
    query.bindValue(":user_type", userType);

    if (query.exec()) {
        ui->signup_complete_label_2->setText("Signup successful!");
        QTimer::singleShot(300, this, [this]() {
        this->close();
        });
    } else {
        ui->signup_complete_label_2->setText("Signup failed: " + query.lastError().text());
    }

    sqldb.close();
}


void signup::on_No_radioButton_clicked()
{
    qDebug() << "Radio button clicked, status:";
}


