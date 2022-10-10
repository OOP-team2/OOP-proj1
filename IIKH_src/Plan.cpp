#include "Plan.h"

// initialize date and meal
Plan::Plan(Date new_date, Meal new_meal) {
    date = new_date;
    meal = new_meal;
}

// returns date
Date Plan::getDate() {
    return date;
}

// set new value to date
void Plan::setDate(Date new_date) {
    date = new_date;
}

// returns meal 
Meal Plan::getMeal() {
    return meal;
}

// set new value to meal
void Plan::setMeal(Meal new_meal) {
    meal = new_meal;
}

// print out information of a plan
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

// examine other plan to check if less plan
bool Plan::isLess(Plan other_plan) {
    return date.isLess(other_plan.getDate()) || meal.isLess(other_plan.getMeal());
}

// examine other plan to check if same plan
bool Plan::isSame(Plan other_plan) {
    if (date.isSame(other_plan.getDate()) && meal.getMealType() == other_plan.getMeal().getMealType()) {
        return true;
    }
    else {
        return false;
    }
}

// operator < is overloaded to compare and sort
bool Plan::operator<(const Plan& other_plan) {
    if (date.isLess(other_plan.date)) {
        return true;
    }
    else {
        return false;
    }
}

// returns string representation of a plan
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