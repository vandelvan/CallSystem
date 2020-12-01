#ifndef AGENTLIST_H_INCLUDED
#define AGENTLIST_H_INCLUDED

#include <iostream>
#include <string>
#include <QMessageBox>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "agentNode.h"
#include "agent.h"

class AgentList{
    private:
        AgentNode* agentNode;
        QMessageBox errorMsg;


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
        void importList(const std::string&);
        void exportList(const std::string&);

        AgentList& operator = (const AgentList&);
};

#endif
