#include "mainwindow.h"
#include <QApplication>
#include<QGraphicsScene>
#include"waiter.cpp"


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    QGraphicsScene* scene = new QGraphicsScene (0,0,300,300,&w);
    scene->setForegroundBrush(QColor(255, 255, 255, 127));

    w.show();
    return a.exec();
}
