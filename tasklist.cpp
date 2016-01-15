#include "tasklist.h"
#include "ui_tasklist.h"
#include<QtSql>

taskList::taskList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::taskList)
{
    ui->setupUi(this);
    //connect to database
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:\\QtProject\\database\\taskDB.db");
    bool db_ok=db.open();
    if(db_ok){
        qDebug()<<"Database Connected";
    }
}

taskList::~taskList()
{
    delete ui;
}

void taskList::setTitle(QString title){
    ui->label->setText(title);
}

void taskList::showUpcomingTask(){

    QDateTime current=QDateTime::currentDateTime();
    QSqlQuery query;
    query.prepare("SELECT * FROM allTask WHERE deadline>:current");
    query.bindValue(":current",current);

    qDebug()<<query.exec();

    int taskFieldNo=query.record().indexOf("task");
    int deadlineFieldNo=query.record().indexOf("deadline");
    int indexFieldNo=query.record().indexOf("id");
    while(query.next()){
        QString task=query.value(taskFieldNo).toString();
        QString deadline=query.value(deadlineFieldNo).toString();
        QString id=query.value(indexFieldNo).toString();
        ui->textBrowser->append(id+". "+task+"\n"+deadline+"\n\n");
    }
}

void taskList::showExpiredTask()
{
    QDateTime current=QDateTime::currentDateTime();
    QSqlQuery query;
    query.prepare("SELECT * FROM allTask WHERE deadline<=:current");
    query.bindValue(":current",current);

    qDebug()<<query.exec();

    int taskFieldNo=query.record().indexOf("task");
    int deadlineFieldNo=query.record().indexOf("deadline");
    int indexFieldNo=query.record().indexOf("id");
    while(query.next()){
        QString task=query.value(taskFieldNo).toString();
        QString deadline=query.value(deadlineFieldNo).toString();
        QString id=query.value(indexFieldNo).toString();
        ui->textBrowser->append(id+". "+task+"\n"+deadline+"\n\n");
    }
}
