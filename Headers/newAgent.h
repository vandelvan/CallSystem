#ifndef NEWAGENT_H
#define NEWAGENT_H

#include <QDialog>
#include <iostream>
#include <QMessageBox>
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
    void setEditAgent(Agent);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::NewAgent *ui;
    AgentList* agentList;
    QMessageBox errorMsg;
    Agent toEdit;
    bool edit;

    void clearFields();
};

#endif // NEWAGENT_H
