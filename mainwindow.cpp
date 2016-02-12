#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "tasklist.h"
#include<QTime>
#include<QDebug>
#include<QtSql>

qint8 getDaysLeft(QDateTime);
qint16 getHoursLeft(QDateTime);
qint32 getMinsLeft(QDateTime);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //connect to database
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:\\QtProject\\database\\taskDB.db");
    bool db_ok=db.open();
    if(db_ok){
        qDebug()<<"Database Connected";
    }

    QTime currentTime=QTime::currentTime();
    ui->setupUi(this);              //everything must be after setupUi
    QDate currentDate=ui->calendarWidget->selectedDate();
    ui->dateTimeEdit->setTime(currentTime);
    ui->dateTimeEdit->setDate(currentDate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_released()
{
    //prepare deadline in string
    QTime selectedTime=ui->dateTimeEdit->time();
    QDate selectedDate=ui->calendarWidget->selectedDate();

    //qDebug()<<time;
    //time left(hours)
    ui->dateTimeEdit->setTime(selectedTime);
    ui->dateTimeEdit->setDate(selectedDate);
    QDateTime selectedDateTime=ui->dateTimeEdit->dateTime();        //getting selected deadline
    ui->lcdNumber->display(getDaysLeft(selectedDateTime));
    ui->lcdNumber_2->display(getHoursLeft(selectedDateTime));
    ui->lcdNumber_3->display(getMinsLeft(selectedDateTime));
}

void MainWindow::on_pushButton_2_clicked()
{

     QString taskText=ui->plainTextEdit->toPlainText();
     QString deadline=ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");

     //insert into database
     if(taskText!=""){
     QSqlQuery addTaskQuery;
    addTaskQuery.prepare("INSERT INTO allTask(task,deadline) values(:task,:deadline)");
    addTaskQuery.bindValue(":task",taskText);
    addTaskQuery.bindValue(":deadline",deadline);
    if(addTaskQuery.exec()){
        Dialog addSuccess;
        addSuccess.showTaskText(taskText);
        addSuccess.showDeadline(deadline);
        addSuccess.exec();
    }
   }


}

//time left (days)
qint8 getDaysLeft(QDateTime selected){
    qint8 daysLeft;
    QDateTime current=QDateTime::currentDateTime();
    daysLeft=current.daysTo(selected);
    return daysLeft;
}

qint16 getHoursLeft(QDateTime selected){
     qint16 hoursLeft;
     QDateTime current=QDateTime::currentDateTime();
    hoursLeft=current.secsTo(selected)/(60*60);
    return hoursLeft;
}

qint32 getMinsLeft(QDateTime selected){
    qint32 minsLeft;
    QDateTime current=QDateTime::currentDateTime();

    minsLeft=current.secsTo(selected)/(60);
    return minsLeft;
}

//show task per type
void MainWindow::on_actionUpcoming_triggered()
{
    taskList list;
    list.setTitle("Upcoming Tasks");
    list.showUpcomingTask();
    list.exec();
}

void MainWindow::on_actionPending_triggered()
{
    taskList list;
    list.setTitle("Pending Tasks");
    list.exec();
}

void MainWindow::on_actionCompleted_triggered()
{
    taskList list;
    list.setTitle("Completed Tasks");
    list.exec();
}

void MainWindow::on_actionExpired_triggered()
{
    taskList list;
    list.setTitle("Expired Tasks");
    list.showExpiredTask();
    list.exec();
}
