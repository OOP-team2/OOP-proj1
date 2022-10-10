#include "RecipeDatabase.h"
#include "PlanManager.h"
#include "Recipe.h"
#include "memory"
#include "string"
#include "iostream"

// class for Greeter which welcomes users and show options that users can select
class Greeter {
private:
	// private member variable for PlanManger which manages plans
	PlanManager planmanager;
	// priavte member variable for RecipeDatabase which manages recipes
	RecipeDatabase* recipedb;
public:
	// constructor for Greeter
	Greeter();
	// destructor for Greeter
	~Greeter();
	// function to show title for IIKH
	void showTitle();
	// function to show menu(optoins) to users
	void showMenu();
	// function to get user input and add a plan to plan manager
	void addPlan();
	// function to get user input and delete a plan of plan manager
    void deletePlan();
	// function to show plans by period
	void showPlansByPeriod();
	// function to search plans by meal type
	void showPlansByMealType();
	// function to show all plans 
    void showAllPlans();
};
