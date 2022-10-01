//
// Created by HoJoonEum on 2022/09/26.
//

#include "PlanManager.h"
#include "iostream"
#include "Date.h"

using namespace std;
PlanManager::PlanManager() {};

PlanManager::PlanManager(vector<Plan> newPlans) {
    for (Plan plan : newPlans) {
        plans.push_back(plan);
    }
}
void PlanManager::addPlan(Plan plan) {
    plans.push_back(plan);
}
void PlanManager::deletePlan(Plan plan) {
    return;
}
void PlanManager::reviseMeal(Plan plan, Meal meal) {
    return;
}
void PlanManager::reviseMealType(Plan plan, MealType meal_type) {
    return;
}
void PlanManager::reviseDate(Plan plan, Date date) {
    return;
}
void PlanManager::showAllPlan() {
    for (Plan plan : plans) {
        // printout plan information
    }
    return;
}