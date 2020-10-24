#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Date{
    private:
        int day;
        int month;
        int year;
        int hour;
        int minutes;

        int toInt() const;
    public:
        Date();
        Date(const Date&);
        Date(const std::string&);
        ~Date();
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        int getHour() const;
        int getMinutes() const;
        std::string getAsString() const;
        void setDay(const int&);
        void setMonth(const int&);
        void setYear(const int&);
        void setHour(const int&);
        void setMinutes(const int&);

        Date& operator = (const Date&);

        bool operator == (const Date&) const;
        bool operator != (const Date&) const;
        bool operator < (const Date&) const;
        bool operator <= (const Date&) const;
        bool operator > (const Date&) const;
        bool operator >= (const Date&) const;

        friend std::ostream& operator << (std::ostream, const Date&);
        friend std::istream& operator >> (std::istream&, Date&);
};

#endif
