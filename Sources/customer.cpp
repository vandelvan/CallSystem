#include "Headers/customer.h"

using namespace std;

Customer::Customer() {}

Customer::Customer(const Customer& c) : name(c.name), date(c.date), duration(c.duration){}

Customer::Customer(const string& name, const Date& date, const Duration& duration)
{
    this->name = name;
    this->date = date;
    this->duration = duration;
}

Customer::~Customer(){}

string Customer::getName() const
{
    return this->name;
}

Date Customer::getDate() const
{
    return this->date;
}

Duration Customer::getDuration() const
{
    return this->duration;
}

void Customer::setName(const std::string & name)
{
    this->name = name;
}

void Customer::setDate(const Date & date)
{
    this->date = date;
}

void Customer::setDuration(const Duration & duration)
{
    this->duration = duration;
}

Customer& Customer::operator=(const Customer & c)
{
    this->name = c.name;
    this->date = c.date;
    this->duration = c.duration;
    return *this;
}

bool Customer::operator==(const Customer & c) const
{
    return this->name == c.name && this->date == c.date && this->duration == c.duration;
}

bool Customer::operator!=(const Customer & c) const
{
    return this->name != c.name || this->date != c.date || this->duration != c.duration;
}

bool Customer::operator<(const Customer & c) const
{
    return this->date < c.date;
}


bool Customer::operator<=(const Customer & c) const
{
    return this->date <= c.date;
}

bool Customer::operator>(const Customer & c) const
{
    return this->date > c.date;
}

bool Customer::operator>=(const Customer & c) const
{
    return this->date >= c.date;
}

ostream& operator << (ostream& os, const Customer& c)
{
    os << c.getName() << endl;
    os << c.getDate().getAsString() << endl;
    os << c.getDuration().getAsString();
    return os;
}

istream& operator >> (istream& is, Customer& c)
{
    getline(is, c.name);
    is >> c.date;
    is >> c.duration;

    return is;
}
