#ifndef OOP_PROJ1_DATE_H
#define OOP_PROJ1_DATE_H

#include "string"

// class for a Date
class Date {
private:
    // string variable for a year
    std::string year;
    // string variable for a month
    std::string month;
    // string variable for a day
    std::string day;
    // string variable for an annotation
    std::string annotation;
public:
    // default constructor for Date
    Date();
    // constructor with parameters: year, month, day
    Date(std::string new_year, std::string new_month, std::string new_day);
    // constructor with parameters: year, month, day, annotation
    Date(std::string new_year, std::string new_month, std::string new_day, std::string new_annotation);
    // function to get year 
    std::string getYear();
    // function to set year
    void setYear(std::string new_year);
    // function to get month
    std::string getMonth();
    // function to set month
    void setMonth(std::string new_month);
    // function to get day
    std::string getDay();
    // function to set day
    void setDay(std::string new_day);
    // function to get annotation
    std::string getAnnotation();
    // function to set annotation
    void setAnnotation(std::string new_annotation);
    // function to get string representation of Date
    std::string toString();
    // function to print out information of Date
    void showInfo();
    // function to check if same date
    bool isSame(Date other_date);
    // function to check if less date
    bool isLess(Date other_date);
};


#endif //OOP_PROJ1_DATE_H
