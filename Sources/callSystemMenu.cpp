#include "Headers/callSystemMenu.h"
#include "ui_callSystemMenu.h"

CallSystemMenu::CallSystemMenu(QWidget *parent, AgentList* al) :
    QMainWindow(parent),
    ui(new Ui::CallSystemMenu),
    agentList(al)
{
    ui->setupUi(this);
    //Ajusta las columnas
    for(int i = 0; i < 8; i++)
        ui->agentTable->setColumnWidth(i, this->width()/8);
}

CallSystemMenu::~CallSystemMenu()
{
    delete ui;
}

void CallSystemMenu::on_addAgent_clicked()
{
    //Al cliquear nuevo agente se muestra el popup para generarlo
    this->newAgent.setAgentList(agentList);
    this->newAgent.exec();
    this->agentList = newAgent.getAgentList();
    this->fillAgentTable();
}

void CallSystemMenu::fillAgentTable()
{
    //Limpia la tabla
    ui->agentTable->setRowCount(0);
    //si la lista esta vacia no hace nada
    if(agentList->isEmpty())
        return;
    AgentNode* aux(this->agentList->getFirst()->getNextAgent());
    //Recorremos la lista
    while(aux != this->agentList->getFirst()){
        //convertimos sus datos a Qstring para ponerlos en la tabla
        QString employeeNum = QString::number(aux->getAgent().getEmployeeNum());
        QString name = QString::fromStdString(aux->getAgent().getName());
        QString field = QString::fromStdString(aux->getAgent().getField());
        QString ext = QString::number(aux->getAgent().getExtention());
        QString hours = QString::fromStdString(aux->getAgent().getHours());
        QString extraHours = QString::fromStdString(aux->getAgent().getExtraHours().getAsString());
        QString see = QString::fromStdString("Ver Clientes");
        QString del = QString::fromStdString("Eliminar");
        //Insertamos la fila
        ui->agentTable->insertRow ( ui->agentTable->rowCount() );
        //inserta el no de empleado
        ui->agentTable->setItem   ( ui->agentTable->rowCount()-1,
                                 0,
                                 new QTableWidgetItem(employeeNum));
        //inserta el nombre
        ui->agentTable->setItem   ( ui->agentTable->rowCount()-1,
                                 1,
                                 new QTableWidgetItem(name));
        //inserta la especialidad
        ui->agentTable->setItem   ( ui->agentTable->rowCount()-1,
                                 2,
                                 new QTableWidgetItem(field));
        //inserta la extension
        ui->agentTable->setItem   ( ui->agentTable->rowCount()-1,
                                 3,
                                 new QTableWidgetItem(ext));
        //inserta el horario
        ui->agentTable->setItem   ( ui->agentTable->rowCount()-1,
                                 4,
                                 new QTableWidgetItem(hours));
        //inserta las horas extra
        ui->agentTable->setItem   ( ui->agentTable->rowCount()-1,
                                 5,
                                 new QTableWidgetItem(extraHours));
        //inserta la opcion para ver clientes
        ui->agentTable->setItem   ( ui->agentTable->rowCount()-1,
                                 6,
                                 new QTableWidgetItem(see));
        //inserta la opcion eliminar
        ui->agentTable->setItem   ( ui->agentTable->rowCount()-1,
                                 7,
                                 new QTableWidgetItem(del));
    aux = aux->getNextAgent();
    }
}

void CallSystemMenu::on_pushButton_clicked()
{
    customerUi.show();
    this->close();
}
