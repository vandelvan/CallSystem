#ifndef CUSTOMERNODE_H_INCLUDED
#define CUSTOMERNODE_H_INCLUDED

#include <iostream>
#include <string>

#include "customer.h"
class CustomerNode{
    private:
        Customer customer;
        CustomerNode* nextCustomer;
    public:
        CustomerNode();
        CustomerNode(const Customer&);
        ~CustomerNode();

        Customer getCustomer() const;
        CustomerNode* getNextCustomer();
        void setCustomer(const Customer&);
        void setCustomerNode(CustomerNode*);
};

#endif