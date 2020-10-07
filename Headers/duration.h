#ifndef DURATION_H_INCLUDED
#define DURATION_H_INCLUDED

#include <iostream>
#include <string>

class Duration{
    private:
        int hour;
        int minutes;
        int seconds;

        bool isValid(const std::string&);
        int toInt() const;
    public:
        Duration();
        Duration(const Duration&);
        Duration(const std::string&);
        ~Duration();
        int getHour() const;
        int getMinutes() const;
        int getSeconds() const;
        std::string getAsString() const;
        void setHour(const int&);
        void setMinutes(const int&);
        void setSeconds(const int&);

        Duration& operator = (const Duration&);

        bool operator == (const Duration&) const;
        bool operator != (const Duration&) const;
        bool operator < (const Duration&) const;
        bool operator <= (const Duration&) const;
        bool operator > (const Duration&) const;
        bool operator >= (const Duration&) const;

        friend std::ostream& operator << (std::ostream, const Duration&);
        friend std::istream& operator >> (std::istream&, Duration&);
};

#endif
