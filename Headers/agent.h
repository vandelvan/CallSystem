#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED

#include <iostream>
#include <string>

#include "customerList.h"

class Agent{
    private:
        std::string name;
        std::string field;
        CustomerList customers;
    public:
        Agent();
        Agent(const Agent&);
        Agent(const std::string&, const std::string&);
        ~Agent();

        std::string getName() const;
        std::string getField() const;
        CustomerList getCustomers() const;
        void setName(const std::string&);
        void setField(const std::string&);
        void setCustomers(const CustomerList&);

        Agent& operator = (const Agent&);

        bool operator == (const Agent&) const;
        bool operator != (const Agent&) const;
        bool operator < (const Agent&) const;
        bool operator <= (const Agent&) const;
        bool operator > (const Agent&) const;
        bool operator >= (const Agent&) const;

        friend std::ostream& operator << (std::ostream, const Agent&);
        friend std::istream& operator >> (std::istream&, Agent&);
};

#endif