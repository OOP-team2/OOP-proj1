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
	void insertRecipe();
	void deleteRecipe();
	void updateRecipe();
	void showAllRecipe();
	vector<Recipe> getRecipes();
	vector<Recipe> searchRecipesByIngredient();
	vector<Recipe> searchRecipesByRecipeName();
	void addPlan();
    	void deletePlan();
    	void reviseMeal();
    	void reviseMealType();
    	void reviseDate();
    	void showAllPlan();
};
