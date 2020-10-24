#include <time.h>
#include "Headers/date.h"

using namespace std;

Date::Date()
{
    char d[2];
    char m[2];
    char Y[4];
    char I[2];
    char M[2];
    time_t rawtime;
    tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    //Tomamos dia mes y año inicial
    strftime(d,80,"%d",timeinfo);
    strftime(m,80,"%m",timeinfo);
    strftime(Y,80,"%Y",timeinfo);
    strftime(I,80,"%I",timeinfo);
    strftime(M,80,"%M",timeinfo);
    //Guardados como enteros
    this->day = atoi(d);
    this->month = atoi(m);
    this->year = atoi(Y);
    this->hour = atoi(I);
    this->minutes = atoi(M);
}

Date::Date(const Date & d) : day(d.day), month(d.month), year(d.year), hour(d.hour), minutes(d.minutes){}

Date::Date(const string & date)
{
    string dateAux = date;
    string delimiter = ".";
    string dia = dateAux.substr(0, dateAux.find(delimiter));
    dateAux.erase(0, 3);
    string mes = dateAux.substr(0, dateAux.find(delimiter));
    dateAux.erase(0, 3);
    string year = dateAux.substr(0, dateAux.find(delimiter));
    this->day = stoi(dia);
    this->month = stoi(mes);
    this->year = stoi(year);
    //el restante es el tiempo
    string time = dateAux.erase(0,5);
    delimiter = ":";
    string hr = time.substr(0, time.find(delimiter));
    time.erase(0, 3);
    string mn = time;
    this->hour = stoi(hr);
    this->minutes = stoi(mn);
}

Date::~Date(){}

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
int Date::getHour() const
{
    return this->hour;
}
int Date::getMinutes() const
{
    return this->minutes;
}

string Date::getAsString() const
{
    string date;
    stringstream auxDay;
    stringstream auxMonth;
    stringstream auxYear;
    stringstream auxHour;
    stringstream auxMinute;
    //se agregan los 0s restantes
    auxDay << setw(2) << setfill('0') << this->day;
    string day = auxDay.str();
    auxMonth << setw(2) << setfill('0') << this->month;
    string month = auxMonth.str();
    auxYear << setw(4) << setfill('0') << this->year;
    string year = auxYear.str();
    auxHour << setw(2) << setfill('0') << this->hour;
    string hour = auxHour.str();
    auxMinute << setw(2) << setfill('0') << this->minutes;
    string minutes = auxMinute.str();
    date = day+"/";
    date += month+"/";
    date += year+ " ";
    date += hour+ ":";
    date += minutes;
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
void Date::setHour(const int& newHour)
{
    this->hour = newHour;
}
void Date::setMinutes(const int& newMinutes)
{
    this->minutes = newMinutes;
}

//Transforma fecha a entera para comparaciones
int Date::toInt() const
{
    return this->day+this->month+this->year+this->hour+this->minutes;
}

Date& Date::operator=(const Date & d)
{
    this->day = d.day;
    this->month = d.month;
    this->year = d.year;
    this->hour = d.hour;
    this->minutes = d.minutes;
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
