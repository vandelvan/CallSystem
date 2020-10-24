#include "Headers/confirmDelete.h"
#include "ui_confirmDelete.h"

ConfirmDelete::ConfirmDelete(QWidget *parent, CustomerList* cl) :
    QDialog(parent),
    ui(new Ui::ConfirmDelete),
    customerList(cl)
{
    ui->setupUi(this);
}

ConfirmDelete::~ConfirmDelete()
{
    delete ui;
}

void ConfirmDelete::setCustomer(Customer toDel)
{
    QString name;
    this->toDelete = this->customerList->getCustomerNode(toDel);
    name = QString::fromStdString(this->toDelete->getCustomer().getName());
    this->ui->customerName->setText(name);
}


void ConfirmDelete::setCustomerList(CustomerList* cl)
{
    this->customerList = cl;
}

CustomerList* ConfirmDelete::getCustomerList()
{
    return this->customerList;
}

void ConfirmDelete::on_buttonBox_accepted()
{
    this->customerList->removeCustomer(this->toDelete);
}
