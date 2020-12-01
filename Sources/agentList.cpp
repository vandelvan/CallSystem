#include "Headers/agentList.h"

using namespace std;

AgentList::AgentList() : agentNode(new AgentNode)
{
    agentNode->setNextAgentNode(agentNode);
    agentNode->setPrevAgentNode(agentNode);
}

AgentList::AgentList(const AgentList& a) : AgentList()
{
    copyAll(a);
}

AgentList::~AgentList()
{
    deleteAll();

    delete agentNode;
}

bool AgentList::isValidPos(AgentNode * a)
{
    AgentNode* aux(agentNode->getNextAgent());
    while (aux != agentNode) {
        if(aux == a)
            return true;
        aux = aux->getNextAgent();
    }
    return false;
}

bool AgentList::isEmpty()
{
    return agentNode->getNextAgent() == agentNode;
}

void AgentList::insertAgent(AgentNode * p, const Agent & a)
{
    if(p != nullptr and !isValidPos(p)){
        errorMsg.setText("Error al insertar agente");
        errorMsg.exec();
        return;
    }
    if(p == nullptr){
        p = this->agentNode;
    }
    AgentNode* aux(new AgentNode(a));
    aux->setPrevAgentNode(p);
    aux->setNextAgentNode(p->getNextAgent());

    p->getNextAgent()->setPrevAgentNode(aux);
    p->setNextAgentNode(aux);
}

AgentNode* AgentList::getPrevAgent(AgentNode * a)
{
    if(a == this->agentNode->getNextAgent() || !isValidPos(a))
        return nullptr;

    return a->getPrevAgent();
}

AgentNode* AgentList::getNextAgent(AgentNode * a)
{
    if(a == this->agentNode->getPrevAgent() || !isValidPos(a))
        return nullptr;

    return a->getNextAgent();
}

void AgentList::removeAgent(AgentNode * a)
{
    if(!isValidPos(a)){
        errorMsg.setText("Error al eliminar agente");
        errorMsg.exec();
        return;
    }
    a->getPrevAgent()->setNextAgentNode(a->getNextAgent());
    a->getNextAgent()->setPrevAgentNode(a->getPrevAgent());

    delete a;
}

AgentNode* AgentList::getAgentNode(const Agent & a)
{
    AgentNode* aux(this->agentNode->getNextAgent());

    while(aux != this->agentNode){
        if(aux->getAgent() == a)
            return aux;
        aux = aux->getNextAgent();
    }

    return nullptr;
}

void AgentList::deleteAll()
{
    AgentNode* aux;

    while(this->agentNode->getNextAgent() != this->agentNode){
        aux = this->agentNode->getNextAgent();
        this->agentNode->setNextAgentNode(aux->getNextAgent());

        delete aux;
    }
    this->agentNode->setPrevAgentNode(this->agentNode);
}

AgentNode *AgentList::getFirst()
{
    if(isEmpty())
        return nullptr;
    return this->agentNode->getNextAgent();
}

AgentNode* AgentList::getLast()
{
    if(isEmpty())
        return nullptr;
    return this->agentNode->getPrevAgent();
}

Agent AgentList::retreive(AgentNode * a)
{
    return a->getAgent();
}

void AgentList::copyAll(const AgentList& a)
{
    AgentNode* aux(a.agentNode->getNextAgent());
    AgentNode* newNode;

    while(aux != a.agentNode)
    {
        newNode = new AgentNode(aux->getAgent());
        if(newNode == nullptr){
            errorMsg.setText("Error al copiar lista");
            errorMsg.exec();
            return;
        }
        newNode->setPrevAgentNode(agentNode->getPrevAgent());
        newNode->setNextAgentNode(agentNode);

        agentNode->getPrevAgent()->setNextAgentNode(newNode);
        agentNode->setPrevAgentNode(newNode);

        aux = aux->getNextAgent();
    }
}

void AgentList::swapPtr(AgentNode* a, AgentNode* b)
{
    if(a != b)
    {
        Agent* aux(a->getAgentPtr());
        a->setAgentPtr(b->getAgentPtr());
        b->setAgentPtr(aux);
    }
}

void AgentList::orderByName()
{
    orderByName(getFirst(), getLast());
}

void AgentList::orderByName(AgentNode* left, AgentNode* right)
{
    if(left == right)
        return;
    if(left->getNextAgent() == right){   //Si solo son 2 nodos en la lista
        if(left->getAgent().getNameLower() > right->getAgent().getNameLower())    //compara sus nombres
            swapPtr(left, right);   //si el primero es mayor al ultimo los intercambia
        return;
    }

    AgentNode* i(left);
    AgentNode* j(right);

    while (i != j) {
        //mientras i sea menor al pivote derecho se itera i
        while (i != j and i->getAgent().getNameLower() <= right->getAgent().getNameLower()) {
            i = i->getNextAgent();
        }
        //mientras j sea mayor al pivote derecho se itera j
        while (i != j and j->getAgent().getNameLower() >= right->getAgent().getNameLower()) {
            j = j->getPrevAgent();
        }
        //intercambio cuando i es mayor al pivote derecho y j menor
        swapPtr(i,j);
    }

    swapPtr(i, right);

    //se comienza a acortar la seccion a ordenar recursivamente
    if(i != left)
        orderByName(left, i->getPrevAgent());
    if(i != right)
        orderByName(i->getNextAgent(), right);
}

void AgentList::orderByField()
{
    orderByField(getFirst(), getLast());
}

void AgentList::exportList(const string & fileName)
{
    QFile file;
    file.setFileName(QString::fromStdString(fileName));
    if(!file.open(QIODevice::WriteOnly)){
        errorMsg.setText(QString::fromStdString("Error al guardar "+ fileName+ "!"));
        errorMsg.exec();
        return;
    }
    AgentNode* aux(agentNode->getNextAgent());
    //Arreglo para almacenar a todos los clientes
    QJsonArray agentsJson;
    while (aux != agentNode) {
        //Objeto para almacenar datos de clientes
        QJsonObject agentData;
        Agent a = aux->getAgent();
        agentData["agentEmpNum"] = a.getEmployeeNum();
        agentData["agentName"] = QString::fromStdString(a.getName());
        agentData["agentField"] = QString::fromStdString(a.getField());
        agentData["agentExt"] = a.getExtention();
        agentData["agentStHr"] = QString::fromStdString(a.getHourStart().getAsString());
        agentData["agentFnHr"] = QString::fromStdString(a.getHourFinish().getAsString());
        agentData["agentExtra"] = QString::fromStdString(a.getExtraHours().getAsString());
        agentData["agentCustomers"] = a.getCustomers()->listToJson();
        //Se agrega el cliente al arreglo
        agentsJson.append(agentData);
        //se itera la lista
        aux = aux->getNextAgent();
    }
    //se lee el objeto en un byteArray
    QByteArray byteArray;
    byteArray = QJsonDocument(agentsJson).toJson();
    //Se guarda en el archivo
    file.write(byteArray);
    file.close();
    errorMsg.setText(QString::fromStdString("Exportado con exito en: " + fileName));
    errorMsg.exec();
}

void AgentList::importList(const string & fileName)
{
    QFile file(QString::fromStdString(fileName));

    if(!file.open(QIODevice::ReadOnly)){    //Si no se puede abre
        errorMsg.setText(QString::fromStdString("Error al abrir "+ fileName + "!"));
        errorMsg.exec();
        return;
    }

    QByteArray byteArray;
    byteArray = file.readAll(); //toma el contenido del json
    file.close();   //cierra el archivo

    QJsonParseError parseError;
    QJsonDocument jsonDoc;
    //crea un jsonDocument con el texto obtenido
    jsonDoc = QJsonDocument::fromJson(byteArray, &parseError);
    //Si existe algun error al leer el json
    if(parseError.error != QJsonParseError::NoError){
        errorMsg.setText(QString::fromStdString("Error al leer "+ fileName + "!"));
        errorMsg.exec();
        return;
    }
    //Pasa el documento a jsonArray para su manipulacion
    QJsonArray jsonArray;
    jsonArray = jsonDoc.array();
    //Se itera a traves del documento
    foreach (const QJsonValue & value, jsonArray) {
        QJsonObject obj = value.toObject();
        Agent newAgent;
        newAgent.setEmployeeNum(obj["agentEmpNum"].toInt());
        newAgent.setName(obj["agentName"].toString().toStdString());
        newAgent.setField(obj["agentField"].toString().toStdString());
        newAgent.setExtention(obj["agentExt"].toInt());
        newAgent.setHourStart(Duration(obj["agentStHr"].toString().toStdString()));
        newAgent.setHourFinish(Duration(obj["agentFnHr"].toString().toStdString()));
        newAgent.setExtraHours(Duration(obj["agentExtra"].toString().toStdString()));
        newAgent.getCustomers()->jsonToList(obj["agentCustomers"].toArray());
        //solo inserta al agente si no existe ya
        if(this->getAgentNode(newAgent) == nullptr)
            insertAgent(getLast(),newAgent);
    }
    errorMsg.setText("Importado con exito!");
    errorMsg.exec();
}

void AgentList::orderByField(AgentNode* left, AgentNode* right)
{
    if(left == right)
        return;
    if(left->getNextAgent() == right){   //Si solo son 2 nodos en la lista
        if(left->getAgent().getField() > right->getAgent().getField())    //compara sus nombres
            swapPtr(left, right);   //si el primero es mayor al ultimo los intercambia
        return;
    }

    AgentNode* i(left);
    AgentNode* j(right);

    while (i != j) {
        //mientras i sea menor al pivote derecho se itera i
        while (i != j and i->getAgent().getField() <= right->getAgent().getField()) {
            i = i->getNextAgent();
        }
        //mientras j sea mayor al pivote derecho se itera j
        while (i != j and j->getAgent().getField() >= right->getAgent().getField()) {
            j = j->getPrevAgent();
        }
        //intercambio cuando i es mayor al pivote derecho y j menor
        swapPtr(i,j);
    }

    swapPtr(i, right);

    //se comienza a acortar la seccion a ordenar recursivamente
    if(i != left)
        orderByField(left, i->getPrevAgent());
    if(i != right)
        orderByField(i->getNextAgent(), right);
}

AgentList& AgentList::operator=(const AgentList & a)
{
    deleteAll();
    copyAll(a);

    return *this;
}
