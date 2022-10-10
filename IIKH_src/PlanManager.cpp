#include "PlanManager.h"
using namespace std;

// read txt file and initialize plans from existing plan data
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

// returns a plan at an index
Plan PlanManager::getPlanAt(int index) {
    return plans[index];
}

// push a plan back to plans and save current plans to txt file
void PlanManager::addPlan(Plan plan) {
    plans.push_back(plan);
    sortPlansByDate();
    savePlans();
    return;
}

// delete a plan from plans and save current plans to txt file
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

// update a meal of a plan 
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
    savePlans();
    std::cout << "update finished" << "\n";
    return;
}

// update a meal type of a plan
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
    savePlans();
    std::cout << "update finished" << "\n";
    return;
}

// update a date of a plan
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
    sortPlansByDate();
    std::cout << "update finished" << "\n";
    return;
}

std::vector<Plan> PlanManager::searchPlansByMealType(MealType mealtype) {
    std::vector<Plan> searchResult;
    for (auto plan : plans) {
        if (plan.getMeal().getMealType() == mealtype) {
            searchResult.push_back(plan);
        }
    }
    return searchResult;
}

// sorts plans by date
void PlanManager::sortPlansByDate() {
    std::sort(plans.begin(),plans.end(), planComparator<Plan>);
    std::cout << "plans are sorted by Date" << endl;
}

// returns plans by period(day,week,month,year)
std::vector<Plan> PlanManager::getPlansByPeriod(std::string period) {
    std::vector<Plan> plansByPeriod;
    if (period == "year") {
        std::string baseYear = plans.at(0).getDate().getYear();
        for (auto plan : plans) {
            if (plan.getDate().getYear() != baseYear) {
                break;
            }
            else {
                plansByPeriod.push_back(plan);
            }
        }
        return plansByPeriod;
    }
    else if (period == "month") {
        std::string baseMonth = plans.at(0).getDate().getMonth();
        for (auto plan : plans) {
            if (plan.getDate().getMonth() != baseMonth) {
                break;
            }
            else {
                plansByPeriod.push_back(plan);
            }
        }
        return plansByPeriod;
    }
    else if (period == "week") {
        std::string baseDay = plans.at(0).getDate().getDay();
        int baseDayInt = std::stoi(baseDay);
        int dayAfterAWeek = baseDayInt + 7;
        for (auto plan : plans) {
            if (std::stoi(plan.getDate().getDay()) == dayAfterAWeek) {
                break;
            }
            else {
                plansByPeriod.push_back(plan);
            }
        }
        return plansByPeriod;
    }
    else if (period == "day") {
        std::string baseDay = plans.at(0).getDate().getDay();
        for (auto plan : plans) {
            if (plan.getDate().getDay() != baseDay) {
                break;
            }
            else {
                plansByPeriod.push_back(plan);
            }
        }
        return plansByPeriod;
    }
    else {
        return plans;
    }
}

// save current plans to txt file
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

// print out information of plans
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