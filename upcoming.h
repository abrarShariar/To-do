#ifndef UPCOMING_H
#define UPCOMING_H

#include <QMainWindow>

namespace Ui {
class upcoming;
}

class upcoming : public QMainWindow
{
    Q_OBJECT

public:
    explicit upcoming(QWidget *parent = 0);
    ~upcoming();

private:
    Ui::upcoming *ui;
};

#endif // UPCOMING_H
