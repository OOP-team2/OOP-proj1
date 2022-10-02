//
// Created by HoJoonEum on 2022/09/27.
//

#include "Plan.h"
#include "Date.h"
#include "Meal.h"
#include <iostream>
using namespace std;

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
    int year, month, day;
    string comment;

    year = date.getYear();
    month = date.getMonth();
    day = date.getDay();
    comment = date.getComment();

    cout << "------------------------------------------------"<< endl;
	cout <<  year << " / " << month << " / " << day << " / " << meal_type << endl;
	cout << "Comment : " << comment << endl;	

	cout << endl << "-menu-" <<  endl;

	vector<Serving> servings = menu.getServings();
	for (int i = 0; i < servings.size(); i++) {
		std::cout << "Menu Name:	" << servings[i].getName() << endl;
		std::cout << "Num of People:	" << servings[i].getId() << endl;
	}
	cout << endl;
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
