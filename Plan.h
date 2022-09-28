//
// Created by HoJoonEum on 2022/09/27.
//

#ifndef OOP_PROJ1_PLAN_H
#define OOP_PROJ1_PLAN_H

#include "Meal.h"
#include "Date.h"

class Plan {
private:
    Meal menu;
    int meal_type;
public:
    Plan(Meal new_menu, int new_meal_type, Date new_date);
    Date getDate();
    Meal getMeal();
    int getMealType();
    void setDate(Date new_date);
    void setMealType(int new_meal_type);
    void setMeal(Meal new_menu);
    void showPlan();
};


#endif //OOP_PROJ1_PLAN_H
