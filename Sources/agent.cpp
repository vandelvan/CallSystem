#include "Headers/agent.h"

using namespace std;

Agent::Agent() {}

Agent::Agent(const Agent& a) : name(a.name), field(a.field), customers(a.customers){}

Agent::Agent(const string& name, const string& field, const CustomerList& customers)
{
    this->name = name;
    this->field = field;
    this->customers = customers;
}

Agent::~Agent(){}

string Agent::getName() const
{
    return this->name;
}

string Agent::getField() const
{
    return this->field;
}

CustomerList Agent::getCustomers() const
{
    return this->customers;
}

void Agent::setName(const std::string & name)
{
    this->name = name;
}

void Agent::setField(const string & field)
{
    this->field = field;
}

void Agent::setCustomers(const CustomerList & customers)
{
    this->customers = customers;
}

Agent& Agent::operator=(const Agent & a)
{
    this->name = a.name;
    this->field = a.field;
    this->customers = a.customers;
    return *this;
}
/*PROBABLEMENTE CAMBIARAN LOS OPERADORES*/
bool Agent::operator==(const Agent & a) const
{
    return this->name == a.name;
}

bool Agent::operator!=(const Agent & a) const
{
    return this->name != a.name;
}

bool Agent::operator<(const Agent & a) const
{
    return this->name < a.name;
}


bool Agent::operator<=(const Agent & a) const
{
    return this->name <= a.name;
}

bool Agent::operator>(const Agent & a) const
{
    return this->name > a.name;
}

bool Agent::operator>=(const Agent & a) const
{
    return this->name >= a.name;
}

ostream& operator << (ostream& os, const Agent& a)
{
    os << a.getName() << endl;
    os << a.getField() << endl;
    //os << a.getCustomers().;
    return os;
}

istream& operator >> (istream& is, Agent& a)
{
    getline(is, a.name);
    is >> a.field;
    //is >> a.customers;

    return is;
}
