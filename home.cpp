#include "home.h"
#include "ui_home.h"

home::home(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::home)
{
    ui->setupUi(this);
    setWindowTitle("RiceDirectPH Home");
}

home::~home()
{
    delete ui;
}

void home::on_home_pushButton_clicked()
{

}


void home::on_recipe_pushButton_2_clicked()
{

}

