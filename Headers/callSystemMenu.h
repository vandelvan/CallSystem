#ifndef CALLSYSTEMMENU_H_INCLUDED
#define CALLSYSTEMMENU_H_INCLUDED

#include <QMainWindow>
//Headers necesarios:
#include "agentList.h"
//GUIs
#include "newAgent.h"
#include "customerUi.h"

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

    void on_pushButton_clicked();

private:
    Ui::CallSystemMenu *ui;
    AgentList* agentList;
    //GUIs
    NewAgent newAgent;
    CustomerUi customerUi;

    //Funcion para llenar tabla
    void fillAgentTable();
};

#endif // CALLSYSTEMMENU_H
