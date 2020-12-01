#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <iostream>
#include <string>

#include "date.h"
#include "duration.h"

class Customer{
    private:
        std::string name;
        Date date;
        Duration duration;
    public:
        Customer();
        Customer(const Customer&);
        Customer(const std::string&, const Date&, const Duration&);
        ~Customer();
        std::string getName() const;
        Date getDate() const;
        Duration getDuration() const;
        void setName(const std::string&);
        void setDate(const Date&);
        void setDuration(const Duration&);

        Customer& operator = (const Customer&);

        bool operator == (const Customer&) const;
        bool operator != (const Customer&) const;
        bool operator < (const Customer&) const;
        bool operator <= (const Customer&) const;
        bool operator > (const Customer&) const;
        bool operator >= (const Customer&) const;
        
};

#endif
