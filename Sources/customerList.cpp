#include "Headers/customerList.h"

using namespace std;

bool CustomerList::isValidPos(CustomerNode * c)
{
    CustomerNode* aux(customerNode);
    while (aux != nullptr) {
        if(aux == c)
            return true;
        aux = aux->getNextCustomer();
    }
    return false;
}

CustomerList::CustomerList() : customerNode(nullptr) {}

CustomerList::~CustomerList()
{
    deleteAll();
}

bool CustomerList::isEmpty()
{
    return customerNode == nullptr;
}


CustomerNode* CustomerList::getAnchor()
{
    return this->customerNode;
}

void CustomerList::insertCustomer(CustomerNode * p, const Customer & c)
{
    if(p != nullptr and !isValidPos(p))
        return;
    CustomerNode* aux(new CustomerNode(c));
    if(aux == nullptr)
        return;
    if(p == nullptr){
        aux->setCustomerNode(this->customerNode);
        this->customerNode = aux;
    }
    else{
        aux->setCustomerNode(p->getNextCustomer());
        p->setCustomerNode(aux);
    }
}


void CustomerList::insertOrdered(const Customer & c)
{
    CustomerNode* aux(customerNode);
    CustomerNode* p(nullptr);

    while(aux != nullptr and c > aux->getCustomer())
    {
        p = aux;
        aux = aux->getNextCustomer();
    }
    insertCustomer(p, c);
}

CustomerNode* CustomerList::getPrevCustomer(CustomerNode * c)
{
    if(c == this->customerNode || !isValidPos(c))
        return nullptr;

    CustomerNode* aux(this->customerNode);

    while(aux->getNextCustomer() != c)
        aux = aux->getNextCustomer();

    return aux;
}

void CustomerList::removeCustomer(CustomerNode * c)
{
    if(!isValidPos(c))
        return;

    if(c == this->customerNode)
        this->customerNode = c->getNextCustomer();
    else
        this->getPrevCustomer(c)->setCustomerNode(c->getNextCustomer());

    delete c;
}

CustomerNode* CustomerList::getCustomerNode(const Customer& c)
{
    CustomerNode* aux(this->customerNode);

    while(aux != nullptr && aux->getCustomer() != c)
        aux = aux->getNextCustomer();

    return aux;
}

void CustomerList::deleteAll()
{
    CustomerNode* aux(this->customerNode);

    while(aux != nullptr){
        this->removeCustomer(aux);
        aux = aux->getNextCustomer();
    }
}

CustomerList& CustomerList::operator=(const CustomerList& c)
{
    this->deleteAll();
    this->customerNode = c.customerNode;
    return *this;
}
