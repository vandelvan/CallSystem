#include "Headers/newCustomer.h"
#include "ui_newCustomer.h"
using namespace std;
NewCustomer::NewCustomer(QWidget *parent, CustomerList* cl) :
    QDialog(parent),
    ui(new Ui::NewCustomer),
    customerList(cl)
{
    ui->setupUi(this);
    QDateTime current = QDateTime::currentDateTime();
    //inicializamos con la fecha actual
    ui->callDate->setDateTime(current);
}

NewCustomer::~NewCustomer()
{
    delete ui;
}

void NewCustomer::setCustomerList(CustomerList* cl)
{
    this->customerList = cl;
}

CustomerList* NewCustomer::getCustomerList()
{
    return this->customerList;
}

void NewCustomer::clearFields()
{
    QDateTime current = QDateTime::currentDateTime();
    const QTime emptyDuration(0,0,0,0);
    ui->customerName->setText("");
    ui->callDate->setDateTime(current);
    ui->callDuration->setTime(emptyDuration);
}

void NewCustomer::on_buttonBox_accepted()
{
    Customer newCustomer;
    CustomerNode* pos;
    //tomamos el nombre del nuevo customer
    newCustomer.setName(ui->customerName->text().toStdString());
    QString format = "dd.MM.yyyy hh:mm";
    string dateStr = ui->callDate->dateTime().toString(format).toStdString();
    Date date(dateStr);
    newCustomer.setDate(date);
    string durationStr;
    format = "hh:mm:ss";
    durationStr = ui->callDuration->time().toString(format).toStdString();
    Duration duration(durationStr);
    newCustomer.setDuration(duration);
    pos = customerList->getCustomerNode(newCustomer);
    if(pos != nullptr){
        errorMsg.setMessage("Cliente previamente registrado!");
        errorMsg.exec();
        return;
    }
    customerList->insertOrdered(newCustomer);
    //Se limpian los campos
    clearFields();
}
