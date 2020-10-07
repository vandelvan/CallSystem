#include "Headers/agentNode.h"

using namespace std;

AgentNode::AgentNode() : nextAgent(nullptr) {}

AgentNode::AgentNode(const Agent& c) : agent(c), nextAgent(nullptr) {}

AgentNode::~AgentNode(){}

Agent AgentNode::getAgent() const
{
    return this->agent;
}

AgentNode* AgentNode::getNextAgent()
{
    return this->nextAgent;
}

void AgentNode::setAgent(const Agent & agent)
{
    this->agent = agent;
}

void AgentNode::setAgentNode(AgentNode * next)
{
    this->nextAgent = next;
}
