//
// Created by HoJoonEum on 2022/09/28.
//

#ifndef OOP_PROJ1_MEAL_H
#define OOP_PROJ1_MEAL_H

#include "Recipe.h"

enum MealType { Breakfast, Launch, Dinner, None };

class Meal {
private:
    MealType mealtype = None;
    std::string people = "0";
    std::vector<Recipe> recipes;
public:
    Meal();
    Meal(MealType new_mealtype, std::string people);
    MealType getMealType();
    void setMealType(MealType new_mealtype);
    std::string getPeople();
    void setPeople(std::string new_people);
    std::vector<Recipe> getRecipes();
    void addRecipe(Recipe Recipe);
    void setRecipes(std::vector<Recipe> ex_recipes);
    void deleteRecipe(Recipe Recipe_to_delete);
    void showRecipes();
    bool isSame(Meal other_meal);
    bool isLesser(Meal other_meal);
    static std::string mealTypeToString(MealType meal_type);
    static MealType stringfiedToMealType(std::string string_meal_type);
};

#endif //OOP_PROJ1_MEAL_H
