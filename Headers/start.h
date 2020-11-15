#ifndef START_H
#define START_H

#include <QMainWindow>
#include "callSystemMenu.h"

namespace Ui {
class Start;
}

class Start : public QMainWindow
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = nullptr);
    ~Start();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

private:
    Ui::Start *ui;
    CallSystemMenu menu;
};

#endif // START_H
