#include <iostream>
using namespace std;
#include <QtSql>
class client{
private:
    int number_of_table;
    string dish;
public:
    void new_client(QString name){
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/TOSHIBA/Documents/untitled/tables.sqlite");
        if (!db.open()) {
              qDebug() << "this is problem with bd";
        }
        QSqlQuery a_query;
        QString str;
            bool b;


            // DML
            QString str_insert = "INSERT INTO client (name) "
                    "VALUES ('%1');";
            str = str_insert.arg(name);
            b = a_query.exec(str);
            if (!b) {
                qDebug() << "Problem with insert";
            }
    }
    void client_table(QString number){
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/TOSHIBA/Documents/untitled/tables.sqlite");
        if (!db.open()) {
              qDebug() << "this is problem with bd";
        }
        QSqlQuery query;
        if(! query.exec("SELECT id FROM client;")){
                    qDebug() << "this is problem with select";
        };
        query.last();
        int id = query.value(0).toInt();

         QString u_query ="update client set number_table= %1 where id =  %2; ";
         QString u_query_updated = u_query.arg(number)
                 .arg(id);
         if(! query.exec(u_query_updated)){
             qDebug() << "this is problem with update";
         }
    }
   /* void Number_of_table(QString number){
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/TOSHIBA/Documents/untitled/tables.sqlite");
        if (!db.open()) {
              qDebug() << "this is problem with bd";
        }
        QSqlQuery query;
        if(! query.exec("SELECT id FROM client;")){
                    qDebug() << "this is problem with select";
        };
        query.last();
        int id = query.value(0).toInt();

         QString u_query ="update client set number_table= %1 where id =  %2; ";
         QString u_query_updated = u_query.arg(number)
                 .arg(id);
         if(! query.exec(u_query_updated)){
             qDebug() << "this is problem with update";
         }
    }*/
};
