//
// Created by HoJoonEum on 2022/09/27.
//

#include "Plan.h"
#include "Date.h"
#include "Meal.h"
#include "iostream"

Plan::Plan(Date new_date, Meal new_meal) {
    date = new_date;
    meal = new_meal;
}

Date Plan::getDate() {
    return date;
}

Meal Plan::getMeal() {
    return meal;
}

void Plan::setDate(Date new_date) {
    date = new_date;
}

void Plan::setMeal(Meal new_meal) {
    meal = new_meal;
}

void Plan::showInfo() {
    int year, month, day;

    year = date.getYear(); /*연도 저장 */
    month = date.getMonth(); /*월 저장 */
    day = date.getDay(); /*일 저장 */

    /* date 출력 */
    cout << "------------------------------------------------"<< endl;
	cout <<  year << " / " << month << " / " << day << " / " << endl;
	cout << endl << "- menu -" <<  endl;

    // print out meal type
    cout << "It is a " << meal.getMealType() << '\n';

	set<Recipe> recipes = meal.getRecipes(); /*벡터에 메뉴들을 저장이후 반복문으로 메뉴를 하나씩 출력. */
	for (auto recipe : recipes) {
		std::cout << "Recipe Name:	" << recipe.getRecipeName() << endl;
        std::cout << "Preperation time:  " << recipe.getPrepareTime() << '\n';
	}
	cout << endl;
	return;
}

bool Plan::operator<(Plan other_plan) {
    return date < other_plan.getDate() || meal.getMealType();
}

bool Plan::operator==(Plan other_plan) {
    if (date == other_plan.getDate() && meal.getMealType() == other_plan.getMeal().getMealType()) {
        return true;
    }
    else {
        return false;
    }
}