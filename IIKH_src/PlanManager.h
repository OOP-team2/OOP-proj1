//
// Created by HoJoonEum on 2022/09/26.
//

#ifndef OOP_PROJ1_PLANMANAGER_H
#define OOP_PROJ1_PLANMANAGER_H

#include "Plan.h"
#include "Date.h"
#include "Meal.h"

class PlanManager {
private:
    std::set<Plan> plans;
public:
    PlanManager();
    PlanManager(std::set<Plan> new_plans);
    void addPlan(Plan plan);
    void deletePlan(Plan plan);
    void updateMeal(Plan plan, Meal meal);
    void updateMealType(Plan plan, MealType meal_type);
    void updateDate(Plan plan, Date date);
    void showInfo();
};


#endif //OOP_PROJ1_PLANMANAGER_H
