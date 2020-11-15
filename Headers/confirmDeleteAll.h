#ifndef CONFIRMDELETEALL_H
#define CONFIRMDELETEALL_H

#include <QDialog>
#include "customerList.h"

namespace Ui {
class ConfirmDeleteAll;
}

class ConfirmDeleteAll : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmDeleteAll(QWidget *parent = nullptr, CustomerList* cl = new CustomerList);
    ~ConfirmDeleteAll();
    void setCustomerList(CustomerList*);
    CustomerList* getCustomerList();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ConfirmDeleteAll *ui;
    CustomerList* customerList;
};

#endif // CONFIRMDELETEALL_H
