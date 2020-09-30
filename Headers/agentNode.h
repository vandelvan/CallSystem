#ifndef AGENTNODE_H_INCLUDED
#define AGENTNODE_H_INCLUDED

#include <iostream>
#include <string>

#include "agent.h"
class AgentNode{
    private:
        Agent agent;
        AgentNode* nextAgent;
    public:
        AgentNode();
        AgentNode(const Agent&);
        ~AgentNode();
        Agent getAgent() const;
        AgentNode* getNextAgent();
        void setAgent(const Agent&);
        void setAgentNode(AgentNode*);
};

#endif