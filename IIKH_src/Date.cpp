//
// Created by HoJoonEum on 2022/09/27.
//

#include "iostream"
#include "Date.h"

Date::Date() {
    year = "0";
    month = "0";
    day = "0";
    annotation = "";
}

Date::Date(std::string new_year, std::string new_month, std::string new_day) {
    year = new_year;
    month = new_month;
    day = new_day;
}

Date::Date(std::string new_year, std::string new_month, std::string new_day, std::string new_annotation) {
    year = new_year;
    month = new_month;
    day = new_day;
    annotation = new_annotation;
}

std::string Date::getYear() {
    return year;
}

void Date::setYear(std::string new_year) {
    year = new_year;
}

std::string Date::getMonth() {
    return month;
}

void Date::setMonth(std::string new_month) {
    month = new_month;
}

std::string Date::getDay() {
    return day;
}

void Date::setDay(std::string new_day) {
    day = new_day;
}

std::string Date::getAnnotation() {
    return annotation;
}

void Date::setAnnotation(std::string new_annotation) {
    annotation = new_annotation;
}

std::string Date::toString() {
    std::string stringfied = "";
    stringfied += year;
    stringfied += '.';
    stringfied += month;
    stringfied += '.';
    stringfied += day;
    stringfied += '.';
    stringfied += annotation;
    return stringfied;
}

// function for show date info
void Date::showInfo() {
    std::cout << "This date info: " << year << month << day << '\n';
    std::cout << std::endl;
}

bool Date::isSame(Date other_date) {
    if (year == other_date.getYear() && month == other_date.getMonth() && day == other_date.getDay()) {
        return true;
    }
    else {
        return false;
    }
}

bool Date::isLesser(Date other_date) {
    if (year < other_date.getYear()) return true;
    if (year > other_date.getYear()) return false;
    if (month < other_date.getMonth()) return true;
    if (month > other_date.getMonth()) return false;
    if (day < other_date.getDay()) return true;
    else return false;
}