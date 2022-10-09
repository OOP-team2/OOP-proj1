//
// Created by HoJoonEum on 2022/09/27.
//
#ifndef OOP_PROJ1_DATE_H
#define OOP_PROJ1_DATE_H

#include "string"

class Date {
private:
    std::string year;
    std::string month;
    std::string day;
    std::string annotation;
public:
    Date();
    Date(std::string new_year, std::string new_month, std::string new_day);
    Date(std::string new_year, std::string new_month, std::string new_day, std::string new_annotation);
    std::string getYear();
    void setYear(std::string new_year);
    std::string getMonth();
    void setMonth(std::string new_month);
    std::string getDay();
    void setDay(std::string new_day);
    std::string getAnnotation();
    void setAnnotation(std::string new_annotation);
    std::string toString();
    void showInfo();

    bool isSame(Date other_date);
    bool isLesser(Date other_date);
};


#endif //OOP_PROJ1_DATE_H
