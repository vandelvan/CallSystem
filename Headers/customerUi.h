#ifndef CUSTOMERUI_H_INCLUDED
#define CUSTOMERUI_H_INCLUDED

#include <QDialog>
#include <iostream>
//Headers necesarios:
#include "customerList.h"
//GUIs
#include "newCustomer.h"
#include "confirmDelete.h"
#include "confirmDeleteAll.h"
#include "editDuration.h"

namespace Ui {
class CustomerUi;
}

class CustomerUi : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerUi(QWidget *parent = nullptr, CustomerList *c = new CustomerList);
    ~CustomerUi();

    //Funcion para mostrar el agente que atendio
    void setAgentNameAndField(std::string, std::string);

    void setCustomerList(CustomerList*);
    CustomerList* getCustomerList();

private slots:
    //Funcion añadir cliente
    void on_addCustomer_clicked();
    //Funcion borrar todo
    void on_deleteList_clicked();
    //Funcion para identificar si se va a eliminar o editar cliente
    void on_customerTable_cellClicked(int row, int column);

    void on_back_clicked();

private:
    Ui::CustomerUi *ui;
    CustomerList* customerList;
    //GUIs
    NewCustomer newCustomer;
    ConfirmDelete confirmDelete;
    ConfirmDeleteAll confirmDeleteAll;
    EditDuration editDuration;
    //Funcion para llenar tabla
    void fillCustomerTable();
    //Funcion para eliminar cliente
    void deleteCustomer(const int row);
    //Funcion para editar cliente
    void editCustomer(const int row);
};

#endif // CUSTOMERUI_H
