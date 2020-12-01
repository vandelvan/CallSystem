#ifndef CALLSYSTEMMENU_H_INCLUDED
#define CALLSYSTEMMENU_H_INCLUDED

#include <QMainWindow>
//Headers necesarios:
#include "agentList.h"
//GUIs
#include "newAgent.h"
#include "customerUi.h"
#include "confirmDeleteAgent.h"
#include "confirmDeleteAllAgents.h"
#include "searchAgent.h"

namespace Ui {
class CallSystemMenu;
}

class CallSystemMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit CallSystemMenu(QWidget *parent = nullptr, AgentList *al = new AgentList);
    ~CallSystemMenu();

private slots:
    void on_addAgent_clicked();

    void on_deleteList_clicked();

    void on_agentTable_cellClicked(int row, int column);

    void on_searchAgent_clicked();

    void on_importList_clicked();

    void on_exportList_clicked();

private:
    Ui::CallSystemMenu *ui;
    AgentList* agentList;
    //GUIs
    NewAgent newAgent;
    CustomerUi customerUi;
    ConfirmDeleteAgent confirmDeleteAgent;
    ConfirmDeleteAllAgents confirmDeleteAllAgents;
    SearchAgent searchAgent;

    //Funcion para llenar tabla
    void fillAgentTable();
    void editAgent(const int);
    void deleteAgent(const int);
};

#endif // CALLSYSTEMMENU_H
