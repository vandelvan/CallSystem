#include "Headers/editDuration.h"
#include "ui_editDuration.h"

using namespace std;
EditDuration::EditDuration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDuration)
{
    ui->setupUi(this);
}

EditDuration::~EditDuration()
{
    delete ui;
}

void EditDuration::setCustomer(Customer toEdit)
{
    QString name;
    this->toEdit = toEdit;
    name = QString::fromStdString(this->toEdit.getName());
    this->ui->customerName->setText(name);
    QString oldDuration;
    //Se asigna por default la duracion anterior
    oldDuration = QString::fromStdString(this->toEdit.getDuration().getAsString());
    this->ui->newDuration->setTime(QTime::fromString(oldDuration));
}

Customer EditDuration::getCustomer()
{
    return this->toEdit;
}

void EditDuration::on_buttonBox_accepted()
{
    QString format = "dd.MM.yyyy hh:mm";
    string durationStr;
    format = "hh:mm:ss";
    durationStr = ui->newDuration->time().toString(format).toStdString();
    Duration duration(durationStr);
    this->toEdit.setDuration(duration);
}
