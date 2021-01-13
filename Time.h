//
// Created by Abdusalam Yabrak on 2021-01-05.
//

#ifndef EXTENTOR_TIME_H
#define EXTENTOR_TIME_H


#include <string>

class Time {
public:
    Time();

    Time(int h, int m, int s);

    Time(const std::string &time);

    Time &operator+=(int seconds);

    Time &operator++();

    friend int operator-(const Time &t1, const Time &t2);

    friend std::ostream &operator<<(std::ostream &os, const Time &t);

    int getHours() const;

    int getMinutes() const;

    int getSeconds() const;


private:
    int hours;
    int minutes;
    int seconds;

    int toSeconds() const;

    void toHMS(int seconds);

};


#endif //EXTENTOR_TIME_H
