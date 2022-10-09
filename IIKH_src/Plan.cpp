#include "Plan.h"

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
    std::string year, month, day;

    year = date.getYear(); /*연도 저장 */
    month = date.getMonth(); /*월 저장 */
    day = date.getDay(); /*일 저장 */

    /* date 출력 */
    std::cout << "------------------------------------------------"<< std::endl;
	std::cout <<  year << " / " << month << " / " << day << " / " << std::endl;
    
    // print out meal type
    std::cout << "It is a " << Meal::mealTypeToString(meal.getMealType()) << '\n';
	
    std::cout << std::endl << "- Recipes for This Meal -" <<  std::endl;


	std::vector<Recipe> recipes = meal.getRecipes(); /*벡터에 메뉴들을 저장이후 반복문으로 메뉴를 하나씩 출력. */
	for (auto recipe : recipes) {
        recipe.showInfo();
	}
	std::cout << std::endl;
	return;
}

bool Plan::isLesser(Plan other_plan) {
    return date.isLesser(other_plan.getDate()) || meal.isLesser(other_plan.getMeal());
}

bool Plan::isSame(Plan other_plan) {
    if (date.isSame(other_plan.getDate()) && meal.getMealType() == other_plan.getMeal().getMealType()) {
        return true;
    }
    else {
        return false;
    }
}

std::string Plan::toString() {
    std::string eachPlan = "";
    eachPlan += date.toString();
    eachPlan += "/";
    eachPlan += meal.getPeople();
    eachPlan += "/";
    eachPlan += Meal::mealTypeToString(meal.getMealType());
    eachPlan += "/";
    std::vector<Recipe> recipes = meal.getRecipes();
    for (auto recipe : recipes) {
        eachPlan += recipe.toString();
        eachPlan += '/';
    }
    return eachPlan;
}