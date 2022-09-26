//
// Created by HoJoonEum on 2022/09/26.
//
#include "vector"
#include "plan"
#ifndef OOP_PROJ1_PLANMANAGER_H
#define OOP_PROJ1_PLANMANAGER_H

namespace planmanager {

    class PlanManager {
    private:
        vector<Plan> plans;
    public:
        PlanManager();
        void addPlan(Plan plan);
        void deletePlan(Plan plan);
        void reviseMeal(Plan plan, Meal meal);
        void reviseMealType(Plan plan, Meal_Type meal_type);
        void reviseDate(Plan plan, Date date);
        void showAllPlan();
    };

} // planmanager

#endif //OOP_PROJ1_PLANMANAGER_H
