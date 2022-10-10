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

// Class for managing plans
class PlanManager {
private:
    // variable for saving state of plans
    std::vector<Plan> plans;
    // variable for managing txt file for saving plans
    FileManagerForPlans file_manager = FileManagerForPlans();
public:
    // default constructor for PlanManager
    PlanManager();
    // function to get a plan at an index
    Plan getPlanAt(int index);
    // function to add a plan to plans
    void addPlan(Plan plan);
    // function to delete a plan from plans
    void deletePlan(Plan plan);
    // function to update a meal of a plan
    void updateMeal(Plan plan, Meal meal);
    // function to update a meal type of a plan
    void updateMealType(Plan plan, MealType meal_type);
    // function to update a date of a plan
    void updateDate(Plan plan, Date date);
    // function to save plans to txt file
    void savePlans();
    // function to print out information of plans
    void showInfo();
};


#endif //OOP_PROJ1_PLANMANAGER_H
