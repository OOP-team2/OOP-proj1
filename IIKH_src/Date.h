//
// Created by HoJoonEum on 2022/09/27.
//

#include <string>
#ifndef OOP_PROJ1_DATE_H
#define OOP_PROJ1_DATE_H

#include "string"

class Date {
private:
    int year;
    int month;
    int day;
    std::string comment;
public:
    Date();
    Date(int new_year, int new_month, int new_day, std::string new_comment);
    int getYear();
    void setYear(int new_year);
    int getMonth();
    void setMonth(int new_month);
    int getDay();
    void setDay(int new_day);
    std::string getComment();
    void setComment(std::string new_comment);

    bool operator== (Date otherDate);
};


#endif //OOP_PROJ1_DATE_H
