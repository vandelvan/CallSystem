#ifndef AGENTNODE_H_INCLUDED
#define AGENTNODE_H_INCLUDED

#include <iostream>
#include <string>

#include "agent.h"
class AgentNode{
    private:
        Agent* agent;
        AgentNode* nextAgent;
        AgentNode* prevAgent;
    public:
        AgentNode();
        AgentNode(const Agent&);
        ~AgentNode();
        Agent* getAgentPtr();
        Agent getAgent();
        AgentNode* getNextAgent();
        AgentNode* getPrevAgent();
        void setAgentPtr(Agent*);
        void setAgent(const Agent&);
        void setNextAgentNode(AgentNode*);
        void setPrevAgentNode(AgentNode*);
};

#endif
