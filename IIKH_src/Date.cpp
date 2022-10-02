//
// Created by HoJoonEum on 2022/09/27.
//

#include "Date.h"

Date::Date() {
    year = 0;
    month = 0;
    day = 0;
    comment = "";
}
Date::Date(int new_year, int new_month, int new_day, std::string new_comment) {
    year = new_year;
    month = new_month;
    day = new_day;
    comment = new_comment;
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

std::string Date::getComment() {
    return comment;
}

void Date::setComment(std::string new_comment) {
    comment = new_comment;
}

bool Date::operator==(Date otherDate) {
    if (year == otherDate.getYear() && month == otherDate.getMonth() && day == otherDate.getDay()) {
        return true;
    }
    else {
        return false;
    }
}