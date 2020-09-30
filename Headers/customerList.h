#ifndef CUSTOMERLIST_H_INCLUDED
#define CUSTOMERLIST_H_INCLUDED

#include <iostream>
#include <string>

#include "customerNode.h"
#include "customer.h"

class CustomerList{
    private:
        CustomerNode* customerNode;
    public:
        CustomerList();
        CustomerList(CustomerNode*);
        ~CustomerList();
        bool isEmpty();
        void insertCustomer(CustomerNode*, const Customer&);
        void removeCustomer(CustomerNode*);
        CustomerNode* getCustomerNode(CustomerNode*);
        CustomerNode* getNextCustomer(CustomerNode*);
        CustomerNode* getPrevCustomer(CustomerNode*);
        void setCustomer(const Customer&);
        void setCustomerNode(CustomerNode*);
        CustomerList exportList() const;
        bool importList(const CustomerList&);

        CustomerList& operator = (const CustomerList&);
};

#endif