#include <regex>
#include "Headers/duration.h"

using namespace std;

Duration::Duration()
{
    this->hour = 00;
    this->minutes = 00;
    this->seconds = 00;
}

Duration::Duration(const Duration& d) : hour(d.hour), minutes(d.minutes), seconds(d.seconds) {}

Duration::Duration(const string& duration)
{
    string durationAux = duration;
    string delimiter = ":";
    string hr = durationAux.substr(0, durationAux.find(delimiter));
    durationAux.erase(0, 3);
    string min = durationAux.substr(0, durationAux.find(delimiter));
    durationAux.erase(0, 3);
    string sec = durationAux;
    this->hour = stoi(hr);
    this->minutes = stoi(min);
    this->seconds = stoi(sec);
}

Duration::~Duration(){}

int Duration::getHour() const
{
    return this->hour;
}

int Duration::getMinutes() const
{
    return this->minutes;
}

int Duration::getSeconds() const
{
    return this->seconds;
}

string Duration::getAsString() const
{
    string duration;
    stringstream auxHour;
    //Agrega 0s a los enteros para hacerlos string
    auxHour << setw(2) << setfill('0') << this->hour;
    string hour = auxHour.str();
    stringstream auxMinutes;
    auxMinutes << setw(2) << setfill('0') << this->minutes;
    string minutes = auxMinutes.str();
    stringstream auxSeconds;
    auxSeconds << setw(2) << setfill('0') << this->seconds;
    string seconds = auxSeconds.str();
    duration = hour+":";
    duration += minutes+":";
    duration += seconds;
    return duration;
}

void Duration::setHour(const int& newHour)
{
    this->hour = newHour;
}
void Duration::setMinutes(const int & newMinutes)
{
    this->minutes = newMinutes;
}
void Duration::setSeconds(const int & newSeconds)
{
    this->seconds = newSeconds;
}

//Transforma fecha a entera para comparaciones
int Duration::toInt() const
{
    return this->hour+this->minutes+this->seconds;
}

Duration& Duration::operator=(const Duration & d)
{
    this->hour = d.hour;
    this->minutes = d.minutes;
    this->seconds = d.seconds;
    return *this;
}

bool Duration::operator==(const Duration & d) const
{
    return this->toInt() == d.toInt();
}

bool Duration::operator!=(const Duration & d) const
{
    return this->toInt() != d.toInt();
}

bool Duration::operator<(const Duration & d) const
{
    return this->toInt() < d.toInt();
}


bool Duration::operator<=(const Duration & d) const
{
    return this->toInt() <= d.toInt();
}

bool Duration::operator>(const Duration & d) const
{
    return this->toInt() > d.toInt();
}

bool Duration::operator>=(const Duration & d) const
{
    return this->toInt() >= d.toInt();
}

ostream& operator << (ostream& os, const Duration& d)
{
    os << d.getAsString();
    return os;
}

istream& operator >> (istream& is, Duration& d)
{
    string str;
    getline(is, str, ':');
    d.hour = atoi(str.c_str());
    getline(is, str, ':');
    d.minutes = atoi(str.c_str());
    getline(is, str);
    d.seconds = atoi(str.c_str());

    return is;
}
