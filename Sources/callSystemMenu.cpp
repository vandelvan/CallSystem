#include "Headers/callSystemMenu.h"
#include "ui_callSystemMenu.h"

CallSystemMenu::CallSystemMenu(QWidget *parent, AgentList* al) :
    QMainWindow(parent),
    ui(new Ui::CallSystemMenu),
    agentList(al)
{
    ui->setupUi(this);
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
    if(agentList->isEmpty())
        return;
    AgentNode* aux(this->agentList->getAnchor());
    while(aux != nullptr){
        QString name = QString::fromStdString(aux->getAgent().getName());
        QString field = QString::fromStdString(aux->getAgent().getField());
//        QString name = QString::fromStdString(aux->getAgent().getName());
        ui->agentTable->insertRow ( ui->agentTable->rowCount() );
        ui->agentTable->setItem   ( ui->agentTable->rowCount()-1,
                                 0,
                                 new QTableWidgetItem(name));
        ui->agentTable->setItem   ( ui->agentTable->rowCount()-1,
                                 1,
                                 new QTableWidgetItem(field));

//        ui->agentTable->setItem   ( ui->agentTable->rowCount()-1,
//                                 "nombre",
//                                 new QTableWidgetItem(aux->getAgent().getName()));
    aux = aux->getNextAgent();
    }
}

void CallSystemMenu::on_pushButton_clicked()
{
    customerUi.show();
    this->close();
}
