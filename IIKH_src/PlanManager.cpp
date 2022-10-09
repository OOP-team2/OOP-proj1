//
// Created by HoJoonEum on 2022/09/26.
//

#include "PlanManager.h"
using namespace std;

PlanManager::PlanManager() {
    vector<string> date_data, recipe_data;
    string people;
    MealType mealtype;
    vector<vector<string> > plan_data = file_manager.loadPlans();
    for (vector<string> plan_by_line : plan_data) {
        date_data = Parser::split(plan_by_line[0], '.');
        people = plan_by_line[1];
        mealtype = Meal::stringfiedToMealType(plan_by_line[2]);
        string recipeName;
        string prepTime;
        vector<Recipe> exRecipes;
        for (int i = 3; i < plan_by_line.size(); i++) {
            recipe_data = Parser::split(plan_by_line[i], '.');
            recipeName = recipe_data[0];
            prepTime = recipe_data[1];
            set<string> ingredients;
            vector<string> exIngredients = Parser::split(recipe_data[2], ',');
            for (auto exIng : exIngredients) {
                ingredients.insert(exIng);
            }
            vector<string> cookingOrder = Parser::split(recipe_data[3], ',');
            Recipe exRecipe = Recipe(recipeName, prepTime, ingredients, cookingOrder);
            exRecipes.push_back(exRecipe);
        }
        Date exDate;
        if (date_data.size() > 3) {
            exDate = Date(date_data[0], date_data[1], date_data[2], date_data[3]);
        }
        else {
            exDate = Date(date_data[0], date_data[1], date_data[2]);
        }
        Meal exMeal = Meal(mealtype, people);
        exMeal.setRecipes(exRecipes);
        Plan exPlan = Plan(exDate, exMeal);
        plans.push_back(exPlan);
    }
}

Plan PlanManager::getPlanAt(int index) {
    return plans[index];
}

void PlanManager::addPlan(Plan plan) {
    plans.push_back(plan);
    savePlans();
    return;
}

void PlanManager::deletePlan(Plan plan) {
    auto iter = plans.begin();
    for (Plan ex_plan : plans) {
        if (ex_plan.isSame(plan)) break;
        iter++;
    }
    plans.erase(iter);
    savePlans();
    return;
}
void PlanManager::updateMeal(Plan plan, Meal meal) {
    auto iter = plans.begin();
    Date exDate;
    for (Plan ex_plan : plans) {
        if (ex_plan.isSame(plan)) {
            exDate = ex_plan.getDate();
            break;
        }
        iter++;
    }
    plans.erase(iter);

    Plan newPlan = Plan(exDate, meal);
    plans.insert(iter,newPlan);
    std::cout << "update finished" << "\n";
    return;
}
void PlanManager::updateMealType(Plan plan, MealType meal_type) {
    auto iter = plans.begin();
    Meal exMeal;
    Date exDate;
    for (auto ex_plan : plans) {
        if (ex_plan.isSame(plan)) {
            exDate = ex_plan.getDate();
            exMeal = ex_plan.getMeal();
            break;
        }
        iter++;
    }
    exMeal.setMealType(meal_type);
    plans.erase(iter);
    Plan newPlan = Plan(exDate, exMeal);
    plans.insert(iter,newPlan);
    std::cout << "update finished" << "\n";
    return;
}
void PlanManager::updateDate(Plan plan, Date date) {
    auto iter = plans.begin();
    Meal exMeal;
    for (auto ex_plan : plans) {
        if (ex_plan.isSame(plan)) {
            exMeal = ex_plan.getMeal();
            break;
        }
        iter++;
    }
    plans.erase(iter);
    Plan newPlan = Plan(date, exMeal);
    plans.insert(iter, newPlan);
    std::cout << "update finished" << "\n";
    return;
}

void PlanManager::savePlans() {
    vector<string> stringfiedPlans;
    string stringfiedPlan;
    for (Plan plan : plans) {
        stringfiedPlan = plan.toString();
        stringfiedPlans.push_back(stringfiedPlan);
    }
    file_manager.writePlans(stringfiedPlans);
    cout << "Plans are saved" << endl;
}

void PlanManager::showInfo() {
    int index = 1;
    for (Plan plan : plans) {
        // printout plan information
        cout << "Order of this plan: " << index << endl;
        plan.showInfo();
        index++;
    }
    cout << "every plan is shown up" << endl;
    return;
}