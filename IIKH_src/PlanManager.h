//
// Created by HoJoonEum on 2022/09/26.
//
#include "vector"
#include "Plan.h"
#include "Date.h"

#ifndef OOP_PROJ1_PLANMANAGER_H
#define OOP_PROJ1_PLANMANAGER_H


class PlanManager {
private:
    PlanManager(std::vector<Plan> newPlans);
    std::vector<Plan> plans;
public:
    PlanManager();
    explicit PlanManager(const std::vector <Plan> &plans);
    void addPlan(Plan plan);
    void deletePlan(Plan plan);
    void reviseMeal(Plan plan, Meal meal);
    void reviseMealType(Plan plan, Meal_Type meal_type);
    void reviseDate(Plan plan, Date date);
    void showAllPlan();
};


#endif //OOP_PROJ1_PLANMANAGER_H
