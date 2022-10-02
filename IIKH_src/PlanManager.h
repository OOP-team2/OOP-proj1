//
// Created by HoJoonEum on 2022/09/26.
//

#ifndef OOP_PROJ1_PLANMANAGER_H
#define OOP_PROJ1_PLANMANAGER_H

#include "vector"
#include "Plan.h"
#include "Date.h"
#include "Meal.h"

class PlanManager {
private:
    std::vector<Plan> plans;
public:
    PlanManager();
    PlanManager(std::vector<Plan> newPlans);
    void addPlan(Plan plan);
    void deletePlan(Plan plan);
    void reviseMeal(Plan plan, Meal meal);
    void reviseMealType(Plan plan, MealType meal_type);
    void reviseDate(Plan plan, Date date);
    void showAllPlan();
};


#endif //OOP_PROJ1_PLANMANAGER_H
