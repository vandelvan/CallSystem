#include "Headers/agentList.h"

using namespace std;

AgentList::AgentList() : agentNode(new AgentNode)
{
    agentNode->setNextAgentNode(agentNode);
    agentNode->setPrevAgentNode(agentNode);
}

AgentList::~AgentList()
{
    deleteAll();
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
    if(p != nullptr and !isValidPos(p))
        return;
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
        this->getPrevAgent(a)->setNextAgentNode(a->getNextAgent());

    delete a;
}

AgentNode* AgentList::getAgentNode(const Agent & a)
{
    AgentNode* aux(this->agentNode->getNextAgent());

    while(aux != this->agentNode && aux->getAgent() != a)
        aux = aux->getNextAgent();

    return aux;
}

void AgentList::deleteAll()
{
    AgentNode* aux(this->agentNode->getNextAgent());

    while(aux != this->agentNode){
        this->removeAgent(aux);
        aux = aux->getNextAgent();
    }
}

AgentNode *AgentList::getFirst()
{
    return this->agentNode;
}


