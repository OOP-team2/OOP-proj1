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
    MealType meal_type;
    Date date;
public:
    Plan(Meal new_menu, MealType new_meal_type, Date new_date);
    Date getDate();
    Meal getMeal();
    MealType getMealType();
    void setDate(Date new_date);
    void setMealType(MealType new_meal_type);
    void setMeal(Meal new_menu);
    void showPlan();
    bool operator== (Plan otherPlan);
};


#endif //OOP_PROJ1_PLAN_H
