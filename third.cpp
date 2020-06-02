#include "third.h"
#include "ui_third.h"
#include"check.h"
#include"waiter.cpp"
#include"client.cpp"
third::third(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::third)
{
    ui->setupUi(this);
    restorant my;
    table  tables[6];
     my.FreeTables(tables);
     for(int i=0; i < 5; i++){
     if (tables[i].StatusOfTable() == 1){
    ui->listWidget->addItem(" номер столика: "+tables[i].NumberOfTable()+"кількість місць: "+tables[i].NumberOfPlace());
     }
}
    new_check = new Check();
     connect(new_check, &Check::end,this,&third::show);
}

third::~third()
{
    delete ui;
}

void third::on_pushButton_clicked()
{
    restorant my;
    QString a = ui->listWidget->currentItem()->text();
    QString number = a.mid(16,1);
    my.ChangeStatus(number,0);
   client my_client;
   // my_client.Number_of_table(a.mid(16,1));
   my_client.client_table(number);
    new_check->show();
    this->close();
}
/*void third::on_pushButton_clicked()
{
    this->close();      // Закрываем окно
    emit desicion(); // И вызываем сигнал на открытие главного окна
}*/

void third::on_checkBox_clicked()
{
    //pass;
}
