//
// Created by HoJoonEum on 2022/09/27.
//

#include "Plan.h"
#include "Date.h"
#include "Meal.h"

Plan::Plan(Meal new_menu, MealType new_meal_type, Date new_date) {
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

MealType Plan::getMealType() {
    return meal_type;
}

void Plan::setDate(Date new_date) {
    date = new_date;
}

void Plan::setMealType(MealType new_meal_type) {
    meal_type = new_meal_type;
}

void Plan::setMeal(Meal new_menu) {
    menu = new_menu;
}

void Plan::showPlan() {
    return;
}

bool Plan::operator==(Plan otherPlan) {
    if (menu == otherPlan.getMeal() && meal_type == otherPlan.getMealType() && date == otherPlan.getDate()) {
        return true;
    }
    else {
        return false;
    }
}