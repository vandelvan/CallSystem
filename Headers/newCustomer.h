#ifndef NEWCUSTOMER_H
#define NEWCUSTOMER_H

#include <QDialog>
#include <iostream>
#include "customerList.h"
#include "customer.h"

namespace Ui {
class NewCustomer;
}

class NewCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit NewCustomer(QWidget *parent = nullptr, CustomerList *cl = new CustomerList);
    ~NewCustomer();
    void setCustomerList(CustomerList*);
    CustomerList* getCustomerList();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::NewCustomer *ui;
    CustomerList* customerList;
};

#endif // NEWCUSTOMER_H
