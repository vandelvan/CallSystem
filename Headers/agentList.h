#ifndef AGENTLIST_H_INCLUDED
#define AGENTLIST_H_INCLUDED

#include <iostream>
#include <string>

#include "agentNode.h"
#include "agent.h"

class AgentList{
    private:
        AgentNode* agentNode;
        
        void orderByName();
        void orderByField();
    public:
        AgentList();
        AgentList(const AgentList&);

        ~AgentList();

        bool isEmpty();
        void insertAgent(AgentNode*, const Agent&);
        void removeAgent(AgentNode*);
        AgentNode* getAgentNode(const Agent&);
        AgentNode* getNextAgent(AgentNode*);
        AgentNode* getPrevAgent(AgentNode*);
        void setAgent(const Agent&);
        void setAgentNode(AgentNode*);
        AgentList exportList() const;
        bool importList(const AgentList&);

        AgentList& operator = (const AgentList&);
};

#endif