#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    //QTime currentTime=QTime::currentTime();


    QTime selectedTime=ui->dateTimeEdit->time();
    QDate selectedDate=ui->calendarWidget->selectedDate();

    //qDebug()<<time;
    //time left(hours)
    ui->dateTimeEdit->setTime(selectedTime);
    ui->dateTimeEdit->setDate(selectedDate);
    QDateTime selectedDateTime=ui->dateTimeEdit->dateTime();
    ui->lcdNumber->display(getDaysLeft(selectedDateTime));
    ui->lcdNumber_2->display(getHoursLeft(selectedDateTime));
    ui->lcdNumber_3->display(getMinsLeft(selectedDateTime));
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
