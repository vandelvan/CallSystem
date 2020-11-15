#include "Headers/agent.h"

using namespace std;

Agent::Agent() {
    this->customers = new CustomerList;
}

Agent::Agent(const Agent& a) : employeeNum(a.employeeNum), name(a.name), field(a.field), extention(a.extention), hourStart(a.hourStart), hourFinish(a.hourFinish), extraHours(a.extraHours), customers(a.customers){}

Agent::Agent(const int employeeNum, const string& name, const string& field, const int extention, const Duration hourStart, const Duration hourFinish, const Duration extraHours, CustomerList* customers)
{
    this->employeeNum = employeeNum;
    this->name = name;
    this->field = field;
    this->extention = extention;
    this->hourStart = hourStart;
    this->hourFinish = hourFinish;
    this->extraHours = extraHours;
    this->customers = customers;
}

Agent::~Agent(){}

int Agent::getEmployeeNum() const
{
    return this->employeeNum;
}

string Agent::getName() const
{
    return this->name;
}

string Agent::getField() const
{
    return this->field;
}

int Agent::getExtention() const
{
    return this->extention;
}

Duration Agent::getHourStart() const
{
    return this->hourStart;
}

Duration Agent::getHourFinish() const
{
    return this->hourFinish;
}

string Agent::getHours() const
{
    return this->hourStart.getAsString() + " - " + this->hourFinish.getAsString();
}

Duration Agent::getExtraHours() const
{
    return this->extraHours;
}

CustomerList* Agent::getCustomers() const
{
    return this->customers;
}

void Agent::setEmployeeNum(const int & employeeNum)
{
    this->employeeNum = employeeNum;
}

void Agent::setName(const std::string & name)
{
    this->name = name;
}

void Agent::setField(const string & field)
{
    this->field = field;
}

void Agent::setExtention(const int & extention)
{
    this->extention = extention;
}

void Agent::setHourStart(const Duration & hourStart)
{
    this->hourStart = hourStart;
}

void Agent::setHourFinish(const Duration & hourFinish)
{
    this->hourFinish = hourFinish;
}

void Agent::setExtraHours(const Duration & extraHours)
{
    this->extraHours = extraHours;
}

void Agent::setCustomers(CustomerList* customers)
{
    this->customers = customers;
}

Agent& Agent::operator=(const Agent & a)
{
    this->employeeNum = a.employeeNum;
    this->name = a.name;
    this->field = a.field;
    this->extention = a.extention;
    this->hourStart = a.hourStart;
    this->hourFinish = a.hourFinish;
    this->extraHours = a.extraHours;
    this->customers = a.customers;
    return *this;
}


bool Agent::operator==(const Agent & a) const
{
    return this->employeeNum == a.employeeNum;
}

bool Agent::operator!=(const Agent & a) const
{
    return this->employeeNum != a.employeeNum;
}

bool Agent::operator<(const Agent & a) const
{
    return this->employeeNum < a.employeeNum;
}


bool Agent::operator<=(const Agent & a) const
{
    return this->employeeNum <= a.employeeNum;
}

bool Agent::operator>(const Agent & a) const
{
    return this->employeeNum > a.employeeNum;
}

bool Agent::operator>=(const Agent & a) const
{
    return this->employeeNum >= a.employeeNum;
}
