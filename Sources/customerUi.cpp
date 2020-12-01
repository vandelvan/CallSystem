#include "Headers/customerUi.h"
#include "ui_customerUi.h"
#include <QDebug>

using namespace std;

CustomerUi::CustomerUi(QWidget *parent, CustomerList* cl) :
    QDialog(parent),
    ui(new Ui::CustomerUi),
    customerList(cl)
{
    ui->setupUi(this);
    //Ajusta las columnas
    for(int i = 0; i < 5; i++)
        ui->customerTable->setColumnWidth(i, this->width()/5);
    this->fillCustomerTable();
}

CustomerUi::~CustomerUi()
{
    delete ui;
}

void CustomerUi::setAgentNameAndField(string name, string field)
{
    ui->attendedBy->setText(QString::fromStdString(name));
    ui->attendedField->setText(QString::fromStdString(field));
}

void CustomerUi::setCustomerList(CustomerList* cl)
{
    this->customerList = cl;
    this->fillCustomerTable();
}

CustomerList* CustomerUi::getCustomerList()
{
    return this->customerList;
}

void CustomerUi::on_addCustomer_clicked()
{
    //Al cliquear nuevo customer se muestra el popup para generarlo
    this->newCustomer.setCustomerList(customerList);
    this->newCustomer.exec();
    //tras terminar el registro se asigna la lista con el agregado a esta lista
    this->customerList = this->newCustomer.getCustomerList();
    //Se llena la tabla
    this->fillCustomerTable();
}

void CustomerUi::fillCustomerTable()
{
    //Limpia la tabla
    ui->customerTable->setRowCount(0);
    //si la lista esta vacia no hace nada
    if(customerList->isEmpty())
        return;
    CustomerNode* aux(this->customerList->getAnchor());
    //recorre la lista y llena la tabla
    while(aux != nullptr){
        QString name = QString::fromStdString(aux->getCustomer().getName());
        QString date = QString::fromStdString(aux->getCustomer().getDate().getAsString());
        QString hour = QString::fromStdString(aux->getCustomer().getDuration().getAsString());
        QString edit = QString::fromStdString("Editar");
        QString del = QString::fromStdString("Eliminar");
        //Agrega fila
        ui->customerTable->insertRow ( ui->customerTable->rowCount() );
        //Pone el nombre
        ui->customerTable->setItem   ( ui->customerTable->rowCount()-1,
                                 0,
                                 new QTableWidgetItem(name));
        //Pone la fecha de atencion
        ui->customerTable->setItem   ( ui->customerTable->rowCount()-1,
                                 1,
                                 new QTableWidgetItem(date));
        //Pone la duracion de la llamada
        ui->customerTable->setItem   ( ui->customerTable->rowCount()-1,
                                 2,
                                 new QTableWidgetItem(hour));
        //Pone la opcion de edicion
        ui->customerTable->setItem   ( ui->customerTable->rowCount()-1,
                                 3,
                                 new QTableWidgetItem(edit));
        //Pone la opcion de eliminar
        ui->customerTable->setItem   ( ui->customerTable->rowCount()-1,
                                 4,
                                 new QTableWidgetItem(del));
    aux = aux->getNextCustomer();
    }
}


//Funcion para eliminar todo
void CustomerUi::on_deleteList_clicked()
{
    this->confirmDeleteAll.setCustomerList(this->customerList);
    this->confirmDeleteAll.exec();
    this->customerList = this->confirmDeleteAll.getCustomerList();
    fillCustomerTable();
}

//Acciones Editar/Eliminar al cliquear la tabla
void CustomerUi::on_customerTable_cellClicked(int row, int column)
{
    if(column == 3)
        editCustomer(row);

    if(column == 4)
        deleteCustomer(row);
}

//Funcion para eliminar cliente
void CustomerUi::deleteCustomer(const int row)
{
    //se toma el cliente a eliminar
    Customer toDelete;
    string name = ui->customerTable->model()->index(row,0).data().toString().toStdString();
    string dateStr = ui->customerTable->model()->index(row,1).data().toString().toStdString();
    string durationStr = ui->customerTable->model()->index(row,2).data().toString().toStdString();
    Date date(dateStr);
    Duration duration(durationStr);
    toDelete.setName(name);
    toDelete.setDate(date);
    toDelete.setDuration(duration);
    //se asigna a la confirmacion y se muestra
    this->confirmDelete.setCustomerList(this->customerList);
    this->confirmDelete.setCustomer(toDelete);
    this->confirmDelete.exec();
    //tras terminar el registro se asigna la lista con el agregado a esta lista
    this->customerList = this->confirmDelete.getCustomerList();
    //Se llena la tabla
    this->fillCustomerTable();
}
void CustomerUi::editCustomer(const int row)
{
    //se toma el cliente a editar
    Customer toEdit;
    string name = ui->customerTable->model()->index(row,0).data().toString().toStdString();
    string dateStr = ui->customerTable->model()->index(row,1).data().toString().toStdString();
    string durationStr = ui->customerTable->model()->index(row,2).data().toString().toStdString();
    Date date(dateStr);
    Duration duration(durationStr);
    toEdit.setName(name);
    toEdit.setDate(date);
    toEdit.setDuration(duration);
    //se asigna a la confirmacion y se muestra
    this->editDuration.setCustomer(toEdit);
    this->editDuration.exec();
    //tras terminar el registro se asigna la lista con la nueva duracion
    this->customerList->getCustomerNode(toEdit)->setCustomer(this->editDuration.getCustomer());
    //Se llena la tabla
    this->fillCustomerTable();
}

void CustomerUi::on_back_clicked()
{
    this->close();
}

void CustomerUi::on_importList_clicked()
{
    string fileName = QFileDialog::getOpenFileName(this, tr("Abrir JSON con clientes"), "~/", tr("*.json")).toStdString();
    this->customerList->importList(fileName);
    this->fillCustomerTable();
}

void CustomerUi::on_exportList_clicked()
{
    string fileName = QFileDialog::getSaveFileName(this, tr("Guardar JSON con clientes como"), "~/clientes.json", tr("*.json")).toStdString();
    this->customerList->exportList(fileName);
}
