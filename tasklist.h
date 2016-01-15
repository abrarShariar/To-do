#ifndef TASKLIST_H
#define TASKLIST_H

#include <QDialog>


namespace Ui {
class taskList;
}

class taskList : public QDialog
{
    Q_OBJECT

public:
    //set title specific to task type
    void setTitle(QString title);
    //show tasks from datadase
    void showUpcomingTask();
    void showExpiredTask();

    explicit taskList(QWidget *parent = 0);
    ~taskList();

private:
    Ui::taskList *ui;
};

#endif // TASKLIST_H
