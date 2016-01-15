#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include<QTime>
#include<QDebug>

qint8 getDaysLeft(QDateTime);
qint16 getHoursLeft(QDateTime);
qint32 getMinsLeft(QDateTime);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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
    //show notification window
    Dialog addTaskNotify;
    addTaskNotify.exec();
}

QString MainWindow::getTaskText(){
    QString taskText=ui->plainTextEdit->toPlainText();
    return taskText;
}

QString MainWindow::getTaskDeadline(){
    QString deadline=ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    return deadline;
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


