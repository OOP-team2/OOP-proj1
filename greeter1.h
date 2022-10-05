#include "RecipeDatabase.h"
#include "PlanManager.h"
#include "InputManager.h"
#include <memory>


class Greeter {
private:
	unique_ptr<RecipeDatabase> recipedb;
	unique_ptr<PlanManager> planmanager;
	string temp_string_name;
	int temp_num;
public:
	Greeter();
	void showTitle();
	void showMenu();
	void addRecipe(); // add new recipe
	void deleteRecipe(); // delete recipe
	void updateRecipe(); // edit recipe
	void searchRecipe(); // search recipe by ingredients or recipename
	void showAllRecipe(); // show all recipe
	void addPlan(Plan* plan_to_add);
	void addPlan(int year, int month, int day, int meal_type, Plan plan_to_add); // function overloading
	void deletePlan();
	void revisePlan();
	void searchPlan();
	void showPlan();
	void showPeriod();
};