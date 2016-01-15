#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showTaskText(QString text){
    ui->label_2->setText(text);
}

void Dialog::showDeadline(QString text){
    ui->label_4->setText(text);
}

void Dialog::on_pushButton_clicked()
{
    this->close();
}
