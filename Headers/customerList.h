#ifndef CUSTOMERLIST_H_INCLUDED
#define CUSTOMERLIST_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>

#include "customerNode.h"
#include "customer.h"
#include "errorMsg.h"

class CustomerList{
    private:
        CustomerNode* customerNode;
        ErrorMsg errorMsg;
    public:
        CustomerList();
        CustomerList(CustomerNode*);
        ~CustomerList();
        bool isValidPos(CustomerNode*);
        bool isEmpty();
        void insertCustomer(CustomerNode*, const Customer&);
        void insertOrdered(const Customer&);
        void removeCustomer(CustomerNode*);
        void deleteAll();
        CustomerNode* getAnchor();
        CustomerNode* getCustomerNode(const Customer&);
        CustomerNode* getNextCustomer(CustomerNode*);
        CustomerNode* getPrevCustomer(CustomerNode*);
        void setCustomer(const Customer&);
        void setCustomerNode(CustomerNode*);
        void importList(const std::string&);
        void exportList(const std::string&);

        CustomerList& operator = (const CustomerList&);
};

#endif
