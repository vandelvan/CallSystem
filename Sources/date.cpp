#include <regex>
#include <time.h>
#include "Headers/date.h"

using namespace std;

Date::Date()
{
    char d[2];
    char m[2];
    char Y[4];
    time_t rawtime;
    tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    //Tomamos dia mes y año inicial
    strftime(d,80,"%d",timeinfo);
    strftime(m,80,"%m",timeinfo);
    strftime(Y,80,"%Y",timeinfo);
    //Guardados como enteros
    this->day = stoi(d);
    this->month = stoi(m);
    this->year = stoi(Y);
}

Date::Date(const Date & d) : day(d.day), month(d.month), year(d.year){}

Date::Date(const string & date)
{
    if(this->isValid(date))
    {
        string delimiter = "/";
        string dia = date.substr(0, date.find(delimiter));
        string mes = date.substr(1, date.find(delimiter));
        string year = date.substr(2, date.find(delimiter));
        this->day = stoi(dia);
        this->month = stoi(mes);
        this->year = stoi(year);
    }
}

Date::~Date(){}

bool Date::isValid(string date)
{
    bool valid;
    //Expresion regular que valida si el string viene como una fecha, con 2 digitos/2 digitos/4 digitos
    valid = regex_match(date,regex("(\\d\\d\\/\\d\\d\\/\\d\\d\\d\\d)"));
    //Si coincide con la expresion regular
    if(valid)
    {
        string delimiter = "/";
        //Separa dia mes y anio del string recibido
        int dayStr = stoi(date.substr(0, date.find(delimiter)));
        int monthStr = stoi(date.substr(1, date.find(delimiter)));
        int yearStr = stoi(date.substr(2, date.find(delimiter)));
        //Verifica todos los casos posibles para meses y sus dias
        switch (monthStr)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(dayStr <= 0 || dayStr > 31)
                    valid = false;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(dayStr <= 0 || dayStr > 30)
                    valid = false;
                break;
            case 2:
                if(this->isLeap(yearStr))
                {
                    if(dayStr <= 0 || dayStr > 29)
                        valid = false;
                }
                else
                    if(dayStr <= 0 || dayStr > 28)
                        valid = false;
                break;
            //Si no es ningun mes valido
            default:
                valid = false;
                break;
        }
    }
    return valid;
}

bool Date::isLeap(int yearStr)
{
    if(yearStr % 4 == 0)
    {
        if(yearStr % 100 == 0)
        {
            if(yearStr % 400 == 0)
            {
                //El anio es bisiesto
                return true;
            }
        }
    }
    return false;
}

int Date::getDay() const
{
    return this->day;
}

int Date::getMonth() const
{
    return this->month;
}

int Date::getYear() const
{
    return this->year;
}

string Date::getAsString() const
{
    string date;
    date = to_string(this->day)+"/";
    date += to_string(this->month)+"/";
    date += to_string(this->year);
    return date;
}

void Date::setDay(const int& newDay)
{
    this->day = newDay;
}
void Date::setMonth(const int& newMonth)
{
    this->month = newMonth;
}
void Date::setYear(const int& newYear)
{
    this->year = newYear;
}

//Transforma fecha a entera para comparaciones
int Date::toInt() const
{
    return this->day+this->month+this->year;
}

Date& Date::operator=(const Date & d)
{
    this->day = d.day;
    this->month = d.month;
    this->year = d.year;
    return *this;
}

bool Date::operator==(const Date & d) const
{
    return this->toInt() == d.toInt();
}

bool Date::operator!=(const Date & d) const
{
    return this->toInt() != d.toInt();
}

bool Date::operator<(const Date & d) const
{
    return this->toInt() < d.toInt();
}


bool Date::operator<=(const Date & d) const
{
    return this->toInt() <= d.toInt();
}

bool Date::operator>(const Date & d) const
{
    return this->toInt() > d.toInt();
}

bool Date::operator>=(const Date & d) const
{
    return this->toInt() >= d.toInt();
}

ostream& operator << (ostream& os, const Date& d)
{
    os << d.getAsString();
    return os;
}

istream& operator >> (istream& is, Date& d)
{
    string str;
    getline(is, str, '/');
    d.day = atoi(str.c_str());
    getline(is, str, '/');
    d.month = atoi(str.c_str());
    getline(is, str);
    d.year = atoi(str.c_str());

    return is;
}
