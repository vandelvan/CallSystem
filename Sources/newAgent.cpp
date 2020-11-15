#include "Headers/newAgent.h"
#include "ui_newAgent.h"

using namespace std;
NewAgent::NewAgent(QWidget *parent, AgentList* al) :
    QDialog(parent),
    ui(new Ui::NewAgent),
    agentList(al)
{
    this->edit = false;
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

void NewAgent::clearFields()
{
    const QTime emptyTime(12,0,0,0);
    const QTime emptyExtra(0,0,0,0);
    ui->employeeNum->setValue(0);
    ui->agentName->setText("");
    ui->agentField->setCurrentIndex(0);
    ui->extNum->setValue(0);
    ui->startHour->setTime(emptyTime);
    ui->finishHour->setTime(emptyTime);
    ui->extraHours->setTime(emptyExtra);
}

void NewAgent::setEditAgent(Agent toEdit)
{
    AgentNode* getEdit = agentList->getAgentNode(toEdit);
    //se recuperan todos los valores anteriores
    toEdit = getEdit->getAgent();
    //Se ponen los valores anteriores
    QString name;
    QString startHr;
    QString finishHr;
    QString extraHr;
    this->toEdit = toEdit;
    name = QString::fromStdString(this->toEdit.getName());
    this->ui->employeeNum->setValue(this->toEdit.getEmployeeNum());
    this->ui->agentName->setText(name);
    this->ui->agentField->setCurrentIndex(this->ui->agentField->findData(QString::fromStdString(this->toEdit.getField()), Qt::DisplayRole));
    ui->extNum->setValue(this->toEdit.getExtention());
    startHr = QString::fromStdString(this->toEdit.getHourStart().getAsString());
    finishHr = QString::fromStdString(this->toEdit.getHourFinish().getAsString());
    extraHr = QString::fromStdString(this->toEdit.getExtraHours().getAsString());
    this->ui->startHour->setTime(QTime::fromString(startHr));
    this->ui->finishHour->setTime(QTime::fromString(finishHr));
    this->ui->extraHours->setTime(QTime::fromString(extraHr));
    this->edit = true; //Se activa el booleano para habilitar la edicion
}

void NewAgent::on_buttonBox_accepted()
{
    Agent newAgent;
    //asigna el numero de empleado
    newAgent.setEmployeeNum(ui->employeeNum->text().toInt());
    //verificamos que aun no exista desde que se registra el numero de empleado a menos que se esté editando
    AgentNode* pos = agentList->getAgentNode(newAgent);
    if(pos != nullptr && !edit){
        errorMsg.setMessage("Numero de empleado en uso!");
        errorMsg.exec();
        return;
    }
    //asigna el nombre
    newAgent.setName(ui->agentName->text().toStdString());
    //asigna la especialidad
    newAgent.setField(ui->agentField->currentText().toStdString());
    //asigna la extension
    newAgent.setExtention(ui->extNum->text().toInt());
    //asigna las horas de inicio y fin usando duration
    string startStr;
    string finishStr;
    string extraStr;
    QString format = "hh:mm:ss";
    startStr = ui->startHour->time().toString(format).toStdString();
    finishStr = ui->finishHour->time().toString(format).toStdString();
    extraStr = ui->extraHours->time().toString(format).toStdString();
    Duration startHour(startStr);
    Duration finishHour(finishStr);
    Duration extraHour(extraStr);
    newAgent.setHourStart(startHour);
    newAgent.setHourFinish(finishHour);
    newAgent.setExtraHours(extraHour);
    //Si se va a editar se reemplaza el nodo con el nuevo de lo contrario se inserta al final
    edit ? agentList->getAgentNode(toEdit)->setAgent(newAgent) : agentList->insertAgent(agentList->getLast(),newAgent);
    //volvemos a poner el booleano de edicion en falso
    edit = false;
    //Limpiamos los campos
    clearFields();
}

void NewAgent::on_buttonBox_rejected()
{
    edit = false;
    clearFields();
}
