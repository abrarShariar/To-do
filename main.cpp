#include "mainwindow.h"
#include <QApplication>
#include<QtSql>


int main(int argc, char *argv[])
{
    //connect to database
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:\\QtProject\\database\\taskDB");
    bool db_ok=db.open();
    if(!db_ok){
        qDebug()<<"Database Connection Error";
    }


    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("My To-do app");


    //getting task text
    QString taskText=w.getTaskText();
    //gettinh task deadline
    QString taskDeadline=w.getTaskDeadline();

    //debug
    qDebug()<<taskText<<" "<<taskDeadline;


    w.show();
    return a.exec();
}
