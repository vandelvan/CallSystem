#ifndef CALLSYSTEMMENU_H_INCLUDED
#define CALLSYSTEMMENU_H_INCLUDED

#include <iostream>
#include <string>

//Headers necesarios:
#include "agentList.h"

class CallSystemMenu {
    private:
        AgentList* agentList;

        //Funcion para mostrar la pantalla principal
        void splashScreen();
        //Funcion para mostrar el inicio de secretaria
        void start();
        //Funcion para mostrar y administrar el listado de agentes
        void agentControl();

    public:
        CallSystemMenu(AgentList*);
};

#endif
