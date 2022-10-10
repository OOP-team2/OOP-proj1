#include "iostream"
#include "Date.h"

// initialize year, month, day, annotation
Date::Date() {
    year = "0";
    month = "0";
    day = "0";
    annotation = "";
}

// initialize year, month, day
Date::Date(std::string new_year, std::string new_month, std::string new_day) {
    year = new_year;
    month = new_month;
    day = new_day;
}

// initialize year, month, day, annotation
Date::Date(std::string new_year, std::string new_month, std::string new_day, std::string new_annotation) {
    year = new_year;
    month = new_month;
    day = new_day;
    annotation = new_annotation;
}

// returns year
std::string Date::getYear() {
    return year;
}

// set new value to year
void Date::setYear(std::string new_year) {
    year = new_year;
}

// returns month
std::string Date::getMonth() {
    return month;
}

// set new value to month
void Date::setMonth(std::string new_month) {
    month = new_month;
}

// returns day
std::string Date::getDay() {
    return day;
}

// set new value to day
void Date::setDay(std::string new_day) {
    day = new_day;
}

// returns annotation
std::string Date::getAnnotation() {
    return annotation;
}

// set new value to annotation
void Date::setAnnotation(std::string new_annotation) {
    annotation = new_annotation;
}

// returns string representation of Date
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

// print out information of Date
void Date::showInfo() {
    std::cout << "This date info: " << year << month << day << '\n';
    std::cout << std::endl;
}

// examine values of Date to check if same
bool Date::isSame(Date other_date) {
    if (year == other_date.getYear() && month == other_date.getMonth() && day == other_date.getDay()) {
        return true;
    }
    else {
        return false;
    }
}

// examine value of Date to check if less
bool Date::isLess(Date other_date) {
    if (year < other_date.getYear()) return true;
    if (year > other_date.getYear()) return false;
    if (month < other_date.getMonth()) return true;
    if (month > other_date.getMonth()) return false;
    if (day < other_date.getDay()) return true;
    else return false;
}