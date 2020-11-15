#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED

#include <iostream>
#include <string>

#include "customerList.h"
#include "duration.h"

class Agent{
    private:
        int employeeNum;
        std::string name;
        std::string field;
        int extention;
        Duration hourStart;
        Duration hourFinish;
        Duration extraHours;
        CustomerList* customers;
    public:
        Agent();
        Agent(const Agent&);
        Agent(const int, const std::string&, const std::string&, const int, const Duration, const Duration, const Duration, CustomerList*);
        ~Agent();

        int getEmployeeNum() const;
        std::string getName() const;
        std::string getField() const;
        int getExtention() const;
        Duration getHourStart() const;
        Duration getHourFinish() const;
        std::string getHours() const;
        Duration getExtraHours() const;
        CustomerList* getCustomers() const;
        void setEmployeeNum(const int&);
        void setName(const std::string&);
        void setField(const std::string&);
        void setExtention(const int&);
        void setHourStart(const Duration&);
        void setHourFinish(const Duration&);
        void setExtraHours(const Duration&);
        void setCustomers(CustomerList*);

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
