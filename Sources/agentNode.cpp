#include "Headers/agentNode.h"

using namespace std;

AgentNode::AgentNode() : agent(nullptr), nextAgent(nullptr), prevAgent(nullptr) {}

AgentNode::AgentNode(const Agent& c) : agent(new Agent(c)), nextAgent(nullptr), prevAgent(nullptr) {}

AgentNode::~AgentNode(){
    delete this->agent;
}

Agent* AgentNode::getAgentPtr()
{
    return this->agent;
}

Agent AgentNode::getAgent()
{
    return *this->agent;
}

AgentNode* AgentNode::getNextAgent()
{
    return this->nextAgent;
}

AgentNode *AgentNode::getPrevAgent()
{
    return this->prevAgent;
}

void AgentNode::setAgentPtr(Agent * agent)
{
    this->agent = agent;
}

void AgentNode::setAgent(const Agent & agent)
{
    delete this->agent;

    this->agent = new Agent(agent);
}

void AgentNode::setNextAgentNode(AgentNode * next)
{
    this->nextAgent = next;
}

void AgentNode::setPrevAgentNode(AgentNode * prev)
{
    this->prevAgent = prev;
}
