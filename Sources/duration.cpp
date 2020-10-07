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
    if(this->isValid(duration))
    {
        string delimiter = ":";
        string hr = duration.substr(0, duration.find(delimiter));
        string min = duration.substr(1, duration.find(delimiter));
        string sec = duration.substr(2, duration.find(delimiter));
        this->hour = stoi(hr);
        this->minutes = stoi(min);
        this->seconds = stoi(sec);
    }
}

Duration::~Duration(){}

bool Duration::isValid(const string& duration)
{
    bool valid;
    //Expresion regular que valida si el string viene como hr:mi:se
    valid = regex_match(duration,regex("(\\d\\d\\:\\d\\d\\:\\d\\d)"));
    //Si coincide con la expresion regular
    if(valid)
    {
        string delimiter = ":";
        //Separa minuto y segundo del string recibido
        int minStr = stoi(duration.substr(1, duration.find(delimiter)));
        int secStr = stoi(duration.substr(2, duration.find(delimiter)));
        if(minStr > 59 || secStr > 59)
            valid = false;

    }
    return valid;
}

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
    duration = to_string(this->hour)+":";
    duration += to_string(this->minutes)+":";
    duration += to_string(this->seconds);
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
