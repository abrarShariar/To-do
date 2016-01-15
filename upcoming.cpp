#include "upcoming.h"
#include "ui_upcoming.h"

upcoming::upcoming(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::upcoming)
{
    ui->setupUi(this);
}

upcoming::~upcoming()
{
    delete ui;
}
