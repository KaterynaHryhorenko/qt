#include <iostream>
#include <QtSql>
using namespace std;

class table {
private:
   QString number;

    bool status;
    QString numberOfPlaces;
public:
    //setter
    void getCharachteritics(QString num, QString size, bool stat) {
        numberOfPlaces = size;
        number = num;
        status= stat;
    }
    //getter
    QString NumberOfTable() {
        return number;
    }
    bool StatusOfTable() {
        return status;
    }
    QString NumberOfPlace() {
        return numberOfPlaces;
    }
};



class restorant {
private:
    string place;
protected:
    table* tables = new table[21];
public:
    void setPlaces() {
        place = 'a';
    }
    void GetTables(table tables) {
        /*for (int i = 1; i <= 5; i++)
            tables.getCharachteritics(i);*/
    }
    void SetTables() {
        delete[] tables;
    }
    void FreeTables(table tables[6]) {
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/TOSHIBA/Documents/untitled/tables.sqlite");
        if (!db.open()) {
              qDebug() << "this is problem with bd";
        }
        QSqlQuery query;
       if(! query.exec("SELECT number,number_of_places,status FROM tables;")){
                   qDebug() << "this is problem with select";
       };


    int i=0;
        while (query.next()) {
            QString number = query.value(0).toString();
            QString places = query.value(1).toString();
            bool status = query.value(2).toInt();
            tables[i].getCharachteritics(number,places,status);
            i++;
        }

    }
    void ChangeStatus(QString number, bool new_status) {
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/TOSHIBA/Documents/untitled/tables.sqlite");
        if (!db.open()) {
              qDebug() << "this is problem with bd";
        }

        QString query ="update tables set status = %1 where number = %2;";
        QString query_inserted = query.arg(new_status)
                .arg(number);
        QSqlQuery a_query;
        if(! a_query.exec(query_inserted)){
            qDebug() <<"Something wrong ";
        };
    }
    string GetPlace() {
        return place;
    }
    table* Tables(){
        return tables;
    }
};

class waiter {
private:
    table* tables[6];
protected:
    restorant my_restoran;

public:

    void  add_item() {
        int num_p;//number places
        int num_t;//number table

    }
    int give_cheque() {//do work
        // client need eat
        //vector client dishes(){}?
        // wile menu doesnt end if vector_order[name] == vector_menu[name]
        return 0;
    }
    void delete_item() {

    }
};
