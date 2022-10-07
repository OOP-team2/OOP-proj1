#include "Plan.h"
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
    std::cout << "------------------------------------------------"<< std::endl;
	std::cout <<  year << " / " << month << " / " << day << " / " << std::endl;
	std::cout << std::endl << "- menu -" <<  std::endl;

    // print out meal type
    std::cout << "It is a " << meal.getMealType() << '\n';

	std::vector<Recipe> recipes = meal.getRecipes(); /*벡터에 메뉴들을 저장이후 반복문으로 메뉴를 하나씩 출력. */
	for (auto recipe : recipes) {
		std::cout << "Recipe Name:	" << recipe.getRecipeName() << std::endl;
        std::cout << "Preperation time:  " << recipe.getPrepareTime() << '\n';
	}
	std::cout << std::endl;
	return;
}

bool Plan::operator<(const Plan& other_plan) {
    return date < other_plan.date || meal < other_plan.meal;
}

bool Plan::operator==(Plan other_plan) {
    if (date == other_plan.getDate() && meal.getMealType() == other_plan.getMeal().getMealType()) {
        return true;
    }
    else {
        return false;
    }
}