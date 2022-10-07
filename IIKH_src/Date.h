//
// Created by HoJoonEum on 2022/09/27.
//
#ifndef OOP_PROJ1_DATE_H
#define OOP_PROJ1_DATE_H

#include "string"

class Date {
private:
    int year;
    int month;
    int day;
    std::string annotation;
public:
    Date();
    Date(int new_year, int new_month, int new_day, std::string new_annotation);
    int getYear();
    void setYear(int new_year);
    int getMonth();
    void setMonth(int new_month);
    int getDay();
    void setDay(int new_day);
    std::string getAnnotation();
    void setAnnotation(std::string new_annotation);
    void showInfo();

    bool operator== (Date other_date);
    bool operator< (Date other_date);
};


#endif //OOP_PROJ1_DATE_H
