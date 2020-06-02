#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "second.h"
#include"client.cpp"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // QString a = ui->lineEdit->text();
    smenu = new second();
    connect(smenu, &second::menu,this,&MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   QString name = ui->lineEdit->text();
   client newClient;
   newClient.new_client(name);
   smenu->show();
   this->close();
}


