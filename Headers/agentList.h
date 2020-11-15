#ifndef AGENTLIST_H_INCLUDED
#define AGENTLIST_H_INCLUDED

#include <iostream>
#include <string>

#include "agentNode.h"
#include "agent.h"
#include "errorMsg.h"

class AgentList{
    private:
        AgentNode* agentNode;
        ErrorMsg errorMsg;


        bool isValidPos(AgentNode*);
        void copyAll(const AgentList&);
        void swapPtr(AgentNode*, AgentNode*);
        void orderByName(AgentNode*, AgentNode*);
        void orderByField(AgentNode*, AgentNode*);
    public:
        AgentList();
        AgentList(const AgentList&);

        ~AgentList();

        bool isEmpty();
        void insertAgent(AgentNode*, const Agent&);
        void removeAgent(AgentNode*);
        void deleteAll();
        AgentNode* getFirst();
        AgentNode* getLast();
        AgentNode* getAgentNode(const Agent&);
        AgentNode* getNextAgent(AgentNode*);
        AgentNode* getPrevAgent(AgentNode*);
        Agent retreive(AgentNode*);
        void orderByName();
        void orderByField();
        AgentList exportList() const;
        bool importList(const AgentList&);

        AgentList& operator = (const AgentList&);
};

#endif
