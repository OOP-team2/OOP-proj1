//
// Created by HoJoonEum on 2022/09/26.
//

#include "PlanManager.h"
#include "iostream"
#include "Date.h"

using namespace std;
PlanManager::PlanManager() {};

PlanManager::PlanManager(set<Plan> new_plans) {
    plans = new_plans;
}
void PlanManager::addPlan(Plan plan) {
    plans.insert(plan);
}
void PlanManager::deletePlan(Plan plan) {
    auto iter = plans.begin();
    for (auto ex_plan : plans) {
        if (ex_plan == plan) break;
        iter++;
    }
    plans.erase(iter);
    return;
}
void PlanManager::updateMeal(Plan plan, Meal meal) {
    auto iter = plans.begin();
    Date exDate;
    for (auto ex_plan : plans) {
        if (ex_plan == plan) {
            exDate = ex_plan.getDate();
            break;
        }
        iter++;
    }
    Plan newPlan = Plan(exDate, meal);
    plans.insert(iter, newPlan);
    std::cout << "update finished" << "\n";
    return;
}
void PlanManager::updateMealType(Plan plan, MealType meal_type) {
    auto iter = plans.begin();
    Meal exMeal;
    Date exDate;
    for (auto ex_plan : plans) {
        if (ex_plan == plan) {
            exDate = ex_plan.getDate();
            exMeal = ex_plan.getMeal();
            break;
        }
        iter++;
    }
    exMeal.setMealType(meal_type);
    Plan newPlan = Plan(exDate, exMeal);
    plans.insert(iter, newPlan);
    std::cout << "update finished" << "\n";
    return;
}
void PlanManager::updateDate(Plan plan, Date date) {
    auto iter = plans.begin();
    Meal exMeal;
    for (auto ex_plan : plans) {
        if (ex_plan == plan) {
            exMeal = ex_plan.getMeal();
            break;
        }
        iter++;
    }
    Plan newPlan = Plan(date, exMeal);
    plans.insert(iter, newPlan);
    std::cout << "update finished" << "\n";
    return;
}
void PlanManager::showInfo() {
    for (Plan plan : plans) {
        // printout plan information
        plan.showInfo();
    }
    std::cout << "every plan is showed up" << endl;
    return;
}