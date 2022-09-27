//
// Created by HoJoonEum on 2022/09/27.
//

#include "Plan.h"
#include "Date.h"

Plan::Plan(Meal new_menu, int new_meal_type, Date new_date) {
    menu = new_menu;
    meal_type = new_meal_type;
    date = new_date;
}

Date Plan::getDate() {
    return date;
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

void Plan::setMeal(int new_menu) {
    menu = new_menu;
}

void Plan::showPlan() {
    return;
}