#ifndef NEWAGENT_H
#define NEWAGENT_H

#include <QDialog>
#include <iostream>
#include "agentList.h"
#include "agent.h"

namespace Ui {
class NewAgent;
}

class NewAgent : public QDialog
{
    Q_OBJECT

public:
    explicit NewAgent(QWidget *parent = nullptr, AgentList *al = new AgentList);
    ~NewAgent();
    AgentList* getAgentList();
    void setAgentList(AgentList*);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::NewAgent *ui;
    AgentList* agentList;
};

#endif // NEWAGENT_H
