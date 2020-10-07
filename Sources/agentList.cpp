#include "Headers/agentList.h"

using namespace std;

bool AgentList::isValidPos(AgentNode * a)
{
    AgentNode* aux(agentNode);
    while (aux != nullptr) {
        if(aux == a)
            return true;
        aux = aux->getNextAgent();
    }
    return false;
}

AgentList::AgentList() : agentNode(nullptr) {}

AgentList::~AgentList()
{
    deleteAll();
}

bool AgentList::isEmpty()
{
    return agentNode == nullptr;
}

void AgentList::insertAgent(AgentNode * p, const Agent & a)
{
    if(!isValidPos(p))
        return;
    AgentNode* aux(new AgentNode(a));
    if(p == nullptr){
        aux->setAgentNode(this->agentNode);
        this->agentNode = aux;
    }
    else{
        aux->setAgentNode(p->getNextAgent());
        p->setAgentNode(aux);
    }
}

AgentNode* AgentList::getPrevAgent(AgentNode * a)
{
    if(a == this->agentNode || !isValidPos(a))
        return nullptr;

    AgentNode* aux(this->agentNode);

    while(aux->getNextAgent() != a)
        aux = aux->getNextAgent();

    return aux;
}

void AgentList::removeAgent(AgentNode * a)
{
    if(!isValidPos(a))
        return;

    if(a == this->agentNode)
        this->agentNode = a->getNextAgent();
    else
        this->getPrevAgent(a)->setAgentNode(a->getNextAgent());

    delete a;
}

AgentNode* AgentList::getAgentNode(const Agent & a)
{
    AgentNode* aux(this->agentNode);

    while(aux != nullptr && aux->getAgent() != a)
        aux = aux->getNextAgent();

    return aux;
}

void AgentList::deleteAll()
{
    AgentNode* aux(this->agentNode);

    while(aux != nullptr){
        this->removeAgent(aux);
        aux = aux->getNextAgent();
    }
}


