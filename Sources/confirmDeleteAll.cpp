#include "Headers/confirmDeleteAll.h"
#include "ui_confirmDeleteAll.h"

ConfirmDeleteAll::ConfirmDeleteAll(QWidget *parent, CustomerList* cl) :
    QDialog(parent),
    ui(new Ui::ConfirmDeleteAll),
    customerList(cl)
{
    ui->setupUi(this);
}

ConfirmDeleteAll::~ConfirmDeleteAll()
{
    delete ui;
}


void ConfirmDeleteAll::setCustomerList(CustomerList* cl)
{
    this->customerList = cl;
}

CustomerList* ConfirmDeleteAll::getCustomerList()
{
    return this->customerList;
}

void ConfirmDeleteAll::on_buttonBox_accepted()
{
    this->customerList->deleteAll();
}
