//
// Created by Abdusalam Yabrak on 2021-01-05.
//

#include "Time.h"
#include "ctime"
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include "iostream"

Time::Time() {
    time_t timer = time(nullptr);
    tm *localTime = localtime(&timer);
    hours = localTime->tm_hour;
    minutes = localTime->tm_min;
    seconds = localTime->tm_sec;
}

Time::Time(int h, int m, int s) : hours{h}, minutes{m}, seconds{s} {}

Time::Time(const std::string &time) {
    // hh:mm:ss
    hours = std::stoi(time.substr(0, 2));
    minutes = std::stoi(time.substr(3, 5));
    seconds = std::stoi(time.substr(6));

    std::istringstream iss(time);
    iss >> hours;
    iss.ignore(1);
    iss >> minutes;
    iss.ignore(1);
    iss >> seconds;
}

int Time::getHours() const {
    return hours;
}

int Time::getMinutes() const {
    return minutes;
}

int Time::getSeconds() const {
    return seconds;
}

void Time::toHMS(int secs) {
    seconds = secs % 60;
    secs = secs / 60;
    minutes = secs % 60;
    hours = secs / 60;
}

std::ostream &operator<<(std::ostream &ostream, Time &time) {
    ostream << std::setw(2) << std::setfill('0') << time.getHours() << ":";
    ostream << std::setw(2) << std::setfill('0') << time.getMinutes() << ":";
    ostream << std::setw(2) << std::setfill('0') << time.getSeconds() << "\n";
    return ostream;
}

/*
Time::Time &operator+=(int seconds) {
    int h = seconds % 3600 > 0 ? seconds / 3600 : 0;
    return;
}*/
