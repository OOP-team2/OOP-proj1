//
// Created by HoJoonEum on 2022/09/26.
//

#ifndef OOP_PROJ1_PLANMANAGER_H
#define OOP_PROJ1_PLANMANAGER_H

#include "Plan.h"
#include "Date.h"
#include "Meal.h"
#include "FileManager.h"
#include "Parser.h"
#include "Recipe.h"
#include "iostream"
#include "vector"

class PlanManager {
private:
    std::vector<Plan> plans;
    FileManagerForPlans file_manager = FileManagerForPlans();
public:
    PlanManager();
    Plan getPlanAt(int index);
    void addPlan(Plan plan);
    void deletePlan(Plan plan);
    void updateMeal(Plan plan, Meal meal);
    void updateMealType(Plan plan, MealType meal_type);
    void updateDate(Plan plan, Date date);
    void savePlans();
    void showInfo();
};


#endif //OOP_PROJ1_PLANMANAGER_H
