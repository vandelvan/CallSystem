#include "Headers/customerNode.h"

using namespace std;

CustomerNode::CustomerNode() : nextCustomer(nullptr) {}

CustomerNode::CustomerNode(const Customer& c) : customer(c), nextCustomer(nullptr) {}

CustomerNode::~CustomerNode(){}


Customer CustomerNode::getCustomer() const
{
    return this->customer;
}

CustomerNode* CustomerNode::getNextCustomer()
{
    return this->nextCustomer;
}

void CustomerNode::setCustomer(const Customer & customer)
{
    this->customer = customer;
}

void CustomerNode::setCustomerNode(CustomerNode * next)
{
    this->nextCustomer = next;
}
