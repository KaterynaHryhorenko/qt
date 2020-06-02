#ifndef SECOND_H
#define SECOND_H

#include <QMainWindow>

#include"third.h"

namespace Ui {
class second;
}

class second : public QMainWindow
{
    Q_OBJECT

public:
    explicit second(QWidget *parent = nullptr);
    ~second();

signals:
    void menu();

private slots:
    // Слот-обработчик нажатия кнопки
     void on_pushButton_clicked();

private:
    Ui::second *ui;
    third * new_third;
};

#endif // SECOND_H
