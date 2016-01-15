#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QString getTaskText();

    QString getTaskDeadline();

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //void on_pushButton_clicked();

    void on_pushButton_released();

    void on_pushButton_2_clicked();

    void on_actionUpcoming_triggered();


    void on_actionPending_triggered();

    void on_actionCompleted_triggered();

    void on_actionExpired_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
