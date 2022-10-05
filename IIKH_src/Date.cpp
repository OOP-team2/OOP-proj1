//
// Created by HoJoonEum on 2022/09/27.
//

#include "iostream"
#include "Date.h"

Date::Date() {
    year = 0;
    month = 0;
    day = 0;
}
Date::Date(int new_year, int new_month, int new_day) {
    year = new_year;
    month = new_month;
    day = new_day;
}

int Date::getYear() {
    return year;
}

void Date::setYear(int new_year) {
    year = new_year;
}

int Date::getMonth() {
    return month;
}

void Date::setMonth(int new_month) {
    month = new_month;
}

int Date::getDay() {
    return day;
}

void Date::setDay(int new_day) {
    day = new_day;
}

// function for show date info
void Date::showInfo() {
    std::cout << "This date info: " << year << month << day << '\n';
    std::cout << std::endl;
}

bool Date::operator==(Date other_date) {
    if (year == other_date.getYear() && month == other_date.getMonth() && day == other_date.getDay()) {
        return true;
    }
    else {
        return false;
    }
}

bool Date::operator<(Date other_date) {
    if (year < other_date.getYear()) return true;
    if (year > other_date.getYear()) return false;
    if (month < other_date.getMonth()) return true;
    if (month > other_date.getMonth()) return false;
    if (day < other_date.getDay()) return true;
    else return false;
}