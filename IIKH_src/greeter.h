#include "RecipeDatabase.h"
#include "PlanManager.h"
#include "InputManager.h"
#include "Recipe.h"
#include "memory"
#include "string"
#include "iostream"

class Greeter {
private:
	PlanManager planmanager;
	std::string temp_string_name;
	RecipeDatabase* recipedb;
public:
	Greeter();
	void showTitle();
	void showMenu();
	void addPlan();
    void deletePlan();
    void updateMeal();
    void updateMealType();
    void updateDate();
    void showAllPlan();
};
