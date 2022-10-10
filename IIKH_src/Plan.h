#ifndef OOP_PROJ1_PLAN_H
#define OOP_PROJ1_PLAN_H

#include "Meal.h"
#include "Date.h"
#include "iostream"

// Class for plan 
class Plan {
private:
    // variable for a meal of a plan
    Meal meal = Meal();
    // variable for a date of a plan
    Date date = Date();
public:
    // constructor with parameters(Date, Meal)
    Plan(Date new_date, Meal new_meal);
    // function to get date
    Date getDate();
    // function to set new date
    void setDate(Date new_date);
    // function to get meal
    Meal getMeal();
    // function to set new meal
    void setMeal(Meal new_meal);
    // function to show information of a plan
    void showInfo();
    // function to check if same plan
    bool isSame(Plan other_plan);
    // function to check if less plan
    bool isLess(Plan other_plan);
    // function to get string representation of a plan
    std::string toString();
};


#endif //OOP_PROJ1_PLAN_H
