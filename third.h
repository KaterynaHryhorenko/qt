#ifndef THIRD_H
#define THIRD_H

#include <QMainWindow>

#include "check.h"

namespace Ui {
class third;
}

class third : public QMainWindow
{
    Q_OBJECT

public:
    explicit third(QWidget *parent = nullptr);
    ~third();
signals:
    void desicion();
private slots:
    // Слот-обработчик нажатия кнопки
    void on_pushButton_clicked();
    void on_checkBox_clicked();

private:
    Ui::third *ui;
    Check *new_check;
};

#endif // THIRD_H
