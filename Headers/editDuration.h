#ifndef EDITDURATION_H
#define EDITDURATION_H

#include <QDialog>
#include "customerList.h"

namespace Ui {
class EditDuration;
}

class EditDuration : public QDialog
{
    Q_OBJECT

public:
    explicit EditDuration(QWidget *parent = nullptr);
    ~EditDuration();
    Customer getCustomer();
    void setCustomer(Customer);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::EditDuration *ui;
    Customer toEdit;
};

#endif // EDITDURATION_H
