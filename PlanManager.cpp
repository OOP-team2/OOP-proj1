//
// Created by HoJoonEum on 2022/09/26.
//

#include "PlanManager.h"
#include "iostream"
#include "Date.h"

using namespace std;
PlanManager::PlanManager(const vector <Plan> &plans) : plans(plans) {}

PlanManager::PlanManager(vector<Plan> newPlans) {
    for (auto plan : newPlans) {
        plans.push_back(plan);
    }
}
void PlanManager::addPlan(Plan plan) {
    plans.push_back(plan);
}
void PlanManager::deletePlan(Plan plan) {
    for (auto existingPlan = plans.begin(); existingPlan != plans.end(); existingPlan++) {
        if (*existingPlan == plan) {
            plans.erase(existingPlan);
        }
    }
}
void PlanManager::reviseMeal(Plan plan, Meal meal) {
    for (auto existingPlan = plans.begin(); existingPlan != plans.end(); existingPlan++) {
        if (*existingPlan == plan) {
            (*existingPlan).setMeal(meal);
        }
    }
}
void PlanManager::reviseMealType(Plan plan, Meal_Type meal_type) {
    for (auto existingPlan = plans.begin(); existingPlan != plans.end(); existingPlan++) {
        if (*existingPlan == plan) {
            (*existingPlan).setMealType(meal_type);
        }
    }
}
void PlanManager::reviseDate(Plan plan, Date date) {
    for (auto existingPlan = plans.begin(); existingPlan != plans.end(); existingPlan++) {
        if (*existingPlan == plan) {
            (*existingPlan).setDate(date);
        }
    }
}
void PlanManager::showAllPlan() {
    for (auto plan : plans) {
        cout << plan.getMeal() << ' ' << plan.getMealType() << ' ' << plan.getDate() << endl;
    }
}