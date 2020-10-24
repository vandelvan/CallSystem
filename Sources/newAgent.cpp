#include "Headers/newAgent.h"
#include "ui_newAgent.h"

using namespace std;
NewAgent::NewAgent(QWidget *parent, AgentList* al) :
    QDialog(parent),
    ui(new Ui::NewAgent),
    agentList(al)
{
    ui->setupUi(this);
}

NewAgent::~NewAgent()
{
    delete ui;
}

AgentList* NewAgent::getAgentList()
{
    return this->agentList;
}

void NewAgent::setAgentList(AgentList* al)
{
    this->agentList = al;
}

void NewAgent::on_buttonBox_accepted()
{
    Agent newAgent;
    AgentNode* pos;
    //tomamos el nombre del nuevo agente
    newAgent.setName(ui->agentName->text().toStdString());
    //Y su especialidad
    newAgent.setField(ui->agentField->currentText().toStdString());
//    AgentNode node(newAgent);
    CustomerList cl;
    newAgent.setCustomers(cl);
    pos = agentList->getAgentNode(newAgent);
    if(pos != nullptr){
        throw "Ya existe";
        return;
    }
    agentList->insertAgent(pos,newAgent);
}
