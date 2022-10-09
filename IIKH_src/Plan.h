//
// Created by HoJoonEum on 2022/09/27.
//

#ifndef OOP_PROJ1_PLAN_H
#define OOP_PROJ1_PLAN_H

#include "Meal.h"
#include "Date.h"
#include "SerializeHelper.h"
#include "iostream"

class Plan {
private:
    Meal meal = Meal();
    Date date = Date();
public:
    Plan(Date new_date, Meal new_meal);
    Date getDate();
    Meal getMeal();
    void setDate(Date new_date);
    void setMeal(Meal new_meal);
    void showInfo();
    bool isLesser(Plan other_plan);
    bool isSame(Plan other_plan);
    std::string toString();
};


#endif //OOP_PROJ1_PLAN_H
