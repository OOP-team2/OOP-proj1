//
// Created by HoJoonEum on 2022/09/28.
//

#ifndef OOP_PROJ1_MEAL_H
#define OOP_PROJ1_MEAL_H

#include "set"
#include "Recipe.h"
#include "RecipeDatabase.h"

enum MealType { Breakfast, Launch, Dinner, None };

class Meal {
private:
    MealType mealtype = None;
    int people = 0;
    std::set<Recipe> recipes;
public:
    static RecipeDatabase* recipeDB;
    Meal();
    Meal(MealType new_mealtype, int people);
    MealType getMealType();
    void setMealType(MealType new_mealtype);
    int getPeople();
    void setPeople(int new_people);
    std::set<Recipe> getRecipes();
    void addRecipe(Recipe Recipe);
    void deleteRecipe(Recipe Recipe_to_delete);
    void showRecipes();
    bool operator==(Meal other_meal);
    bool operator< (Meal other_meal);
};

RecipeDatabase* recipeDB = RecipeDatabase().getInstance();


#endif //OOP_PROJ1_MEAL_H
