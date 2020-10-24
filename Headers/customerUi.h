#ifndef CUSTOMERUI_H_INCLUDED
#define CUSTOMERUI_H_INCLUDED

#include <QMainWindow>
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

class CustomerUi : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomerUi(QWidget *parent = nullptr, CustomerList *c = new CustomerList);
    ~CustomerUi();

private slots:
    //Funcion añadir cliente
    void on_addCustomer_clicked();
    //Funcion borrar todo
    void on_deleteList_clicked();
    //Funcion para identificar si se va a eliminar o editar cliente
    void on_customerTable_cellClicked(int row, int column);

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
