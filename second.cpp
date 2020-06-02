#include "second.h"
#include "ui_second.h"
#include"third.h"

second::second(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::second)
{
    ui->setupUi(this);

    new_third= new third();
    connect(new_third, &third::desicion,this,&second::show);


}

second::~second()
{
    delete ui;
}



void second::on_pushButton_clicked()
{
    new_third->show();
    this->close();
}
