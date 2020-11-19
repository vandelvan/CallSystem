#include "Headers/callSystemMenu.h"
#include "ui_callSystemMenu.h"


using namespace std;

CallSystemMenu::CallSystemMenu(QWidget *parent, AgentList* al) :
    QMainWindow(parent),
    ui(new Ui::CallSystemMenu),
    agentList(al)
{
    ui->setupUi(this);
    //Ajusta las columnas
    for(int i = 0; i < 9; i++)
        ui->agentTable->setColumnWidth(i, this->width()/9);
    //Listener para cuando cliquea la cabecera de la columna y se reordene la lista
    auto header = ui->agentTable->horizontalHeader();
    connect(header, &QHeaderView::sectionClicked, [this](int headerCol){
        switch (headerCol) {
            case 1: //columna de nombre cliqueada
                agentList->orderByName();   //ordena por nombre
                fillAgentTable();   //actualiza la tabla
                break;
            case 2: //columna de especialidad cliqueada
                agentList->orderByField();  //ordena por especialidad
                fillAgentTable();   //actualiza la tabla
                break;
            default:
                break;
        }
    });
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
    AgentNode* aux(this->agentList->getFirst());
    //Recorremos la lista
    while(aux != this->agentList->getFirst()->getPrevAgent()){
        //convertimos sus datos a Qstring para ponerlos en la tabla
        QString employeeNum = QString::number(aux->getAgent().getEmployeeNum());
        QString name = QString::fromStdString(aux->getAgent().getName());
        QString field = QString::fromStdString(aux->getAgent().getField());
        QString ext = QString::number(aux->getAgent().getExtention());
        QString hours = QString::fromStdString(aux->getAgent().getHours());
        QString extraHours = QString::fromStdString(aux->getAgent().getExtraHours().getAsString());
        QString see = QString::fromStdString("Ver Clientes");
        QString edit = QString::fromStdString("Editar");
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
        //inserta la opcion para editar al agente
        ui->agentTable->setItem   ( ui->agentTable->rowCount()-1,
                                  7,
                                  new QTableWidgetItem(edit));
        //inserta la opcion eliminar
        ui->agentTable->setItem   ( ui->agentTable->rowCount()-1,
                                 8,
                                 new QTableWidgetItem(del));
    aux = aux->getNextAgent();
    }
}

//Funcion para eliminar todo
void CallSystemMenu::on_deleteList_clicked()
{
    this->confirmDeleteAllAgents.setAgentList(this->agentList);
    this->confirmDeleteAllAgents.exec();
    this->agentList = this->confirmDeleteAllAgents.getAgentList();
    fillAgentTable();
}

//Acciones Editar/Eliminar al cliquear la tabla
void CallSystemMenu::on_agentTable_cellClicked(int row, int column)
{
    if(column == 6)
    {
        int empNum = ui->agentTable->model()->index(row,0).data().toString().toInt();
        Agent attendedBy;
        attendedBy.setEmployeeNum(empNum);
        attendedBy = agentList->getAgentNode(attendedBy)->getAgent();
        customerUi.setAgentNameAndField(attendedBy.getName(),attendedBy.getField());
        customerUi.setCustomerList(attendedBy.getCustomers());
        customerUi.exec();
        agentList->getAgentNode(attendedBy)->getAgent().setCustomers(customerUi.getCustomerList());
    }


    if(column == 7)
        editAgent(row);

    if(column == 8)
        deleteAgent(row);
}

//Funcion para eliminar un agente
void CallSystemMenu::deleteAgent(const int row)
{
    //se toma el agente a eliminar por su numero de empleado
    Agent toDelete;
    int empNum = ui->agentTable->model()->index(row,0).data().toString().toInt();
    toDelete.setEmployeeNum(empNum);
    //se asigna a la confirmacion y se muestra
    this->confirmDeleteAgent.setAgentList(this->agentList);
    this->confirmDeleteAgent.setAgent(toDelete);
    this->confirmDeleteAgent.exec();
    //tras terminar el registro se asigna la lista con el agregado a esta lista
    this->agentList = this->confirmDeleteAgent.getAgentList();
    //Se llena la tabla
    this->fillAgentTable();
}
void CallSystemMenu::editAgent(const int row)
{
    //se toma el agente a editar por su numero de empleado
    Agent toEdit;
    int empNum = ui->agentTable->model()->index(row,0).data().toString().toInt();
    toEdit.setEmployeeNum(empNum);
    //se asigna a la confirmacion y se muestra
    this->newAgent.setAgentList(agentList);
    this->newAgent.setEditAgent(toEdit);
    this->newAgent.exec();
    //tras terminar el registro se actualiza la lista y la tabla
    this->agentList = this->newAgent.getAgentList();
    this->fillAgentTable();
}

void CallSystemMenu::on_searchAgent_clicked()
{
    //Manda la lista de agentes para la busqueda
    searchAgent.setAgentList(agentList);
    searchAgent.exec();
    //Recibe la lista de agentes modificada
    this->agentList = searchAgent.getAgentList();
    //Llena nuevamente la tabla
    this->fillAgentTable();
}
