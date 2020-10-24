#ifndef CONFIRMDELETE_H
#define CONFIRMDELETE_H

#include <QDialog>
#include "customerList.h"

namespace Ui {
class ConfirmDelete;
}

class ConfirmDelete : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmDelete(QWidget *parent = nullptr, CustomerList* cl = new CustomerList);
    ~ConfirmDelete();
    void setCustomerList(CustomerList*);
    CustomerList* getCustomerList();
    void setCustomer(Customer);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ConfirmDelete *ui;
    CustomerList* customerList;
    CustomerNode* toDelete;
};

#endif // CONFIRMDELETE_H
