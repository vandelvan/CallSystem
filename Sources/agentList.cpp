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
    if(!isValidPos(a))
        return;
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
        if(newNode == nullptr)
            return;
        newNode->setPrevAgentNode(agentNode->getPrevAgent());
        newNode->setNextAgentNode(agentNode);

        agentNode->getPrevAgent()->setNextAgentNode(newNode);
        agentNode->setPrevAgentNode(newNode);

        aux = aux->getNextAgent();
    }
}

AgentList& AgentList::operator=(const AgentList & a)
{
    deleteAll();
    copyAll(a);

    return *this;
}
