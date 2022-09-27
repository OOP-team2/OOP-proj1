//
// Created by HoJoonEum on 2022/09/27.
//

#include "Plan.h"

Plan::Plan(Meal menu, int meal_type, Date date) {
    menu = menu;
    meal_type = meal_type;
    date = date;
}

int Plan::getDate() {
    return  date;
}

Meal Plan::getMeal() {
    return  menu;
}

int Plan::getMealType() {
    return meal_type;
}

void Plan::setDate(Date new_date) {
    date = new_date;
}

void Plan::setMealType(int new_meal_type) {
    meal_type = new_meal_type;
}

void Plan::setMeal(int meal) {
    menu = meal;
}

void Plan::showPlan() {
    return;
}