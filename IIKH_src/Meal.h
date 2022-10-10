#ifndef OOP_PROJ1_MEAL_H
#define OOP_PROJ1_MEAL_H

#include "Recipe.h"

// enum for meal type
enum MealType { Breakfast, Launch, Dinner, None };

// Class for meal for a plan
class Meal {
private:
    // MealType variable for meal type(Breakfast, Launch, Dinner)
    MealType mealtype = None;
    // string variable for people invited for a meal
    std::string people = "0";
    // string vector for saving Recipes for a meal
    std::vector<Recipe> recipes;
public:
    // default constructor
    Meal();
    // constructor with parameters(MealType, string)
    Meal(MealType new_mealtype, std::string people);
    // function to get mealtype
    MealType getMealType();
    // function to set mealtype
    void setMealType(MealType new_mealtype);
    // function to get people
    std::string getPeople();
    // function to set people
    void setPeople(std::string new_people);
    // function to get recipes
    std::vector<Recipe> getRecipes();
    // function to add a recipe
    void addRecipe(Recipe Recipe);
    // function to set recipes at once
    void setRecipes(std::vector<Recipe> ex_recipes);
    // function to delete a recipe
    void deleteRecipe(Recipe Recipe_to_delete);
    // function to print out recipes
    void showRecipes();
    // function to check if same meal
    bool isSame(Meal other_meal);
    // function to check if less meal
    bool isLess(Meal other_meal);
    // static function to transform MealType to string
    static std::string mealTypeToString(MealType meal_type);
    // static function to transform string to MealType
    static MealType stringfiedToMealType(std::string string_meal_type);
};

#endif //OOP_PROJ1_MEAL_H
