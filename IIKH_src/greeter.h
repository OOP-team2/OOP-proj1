#include "RecipeDatabase.h"
#include "PlanManager.h"
#include "InputManager.h"
#include "Recipe.h"
#include "memory"

class Greeter {
private:
	PlanManager planmanager;
	std::string temp_string_name;
	RecipeDatabase* recipedb;
	void searchRecipesByIngredient();
	void searchRecipesByRecipeName();
public:
	Greeter();
	void showTitle();
	void showMenu();
	void insertRecipe();
	void deleteRecipe();
	void updateRecipe();
	void showAllRecipe();
	void showRecipes(std::vector<Recipe> recipes);
	void addPlan();
    void deletePlan();
    void updateMeal();
    void updateMealType();
    void updateDate();
    void showAllPlan();
};
