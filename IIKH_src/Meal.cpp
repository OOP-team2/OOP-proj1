//
// Created by HoJoonEum on 2022/09/28.
//

#include "Meal.h"


Meal::Meal() {};
Meal::Meal(MealType new_mealtype, std::string new_people) {
    mealtype = new_mealtype;
    people = new_people;
};

MealType Meal::getMealType() {
    return mealtype;
}

void Meal::setMealType(MealType new_mealtype) {
    mealtype = new_mealtype;
}

std::string Meal::getPeople() {
    return people;
}
void Meal::setPeople(std::string new_people) {
    people = new_people;
}

void Meal::addRecipe(Recipe recipe) {
    recipes.push_back(recipe);
    std::cout << "a recipe is added" << std::endl;
    return;
}

void Meal::setRecipes(std::vector<Recipe> ex_recipes) {
    recipes = ex_recipes;
}

void Meal::deleteRecipe(Recipe recipe_to_delete) {
    auto iter = recipes.begin();
    for (auto recipe : recipes) {
        if (recipe == recipe_to_delete) {
            recipes.erase(iter);
            break;
        }
        iter++;
    }
    if (iter == recipes.end()) {
        std::cout << "no recipe is found to be deleted" << std::endl;
    }
    return;
}

std::vector<Recipe> Meal::getRecipes() {
    return recipes;
}

void Meal::showRecipes() {
    return;
}

bool Meal::isSame(Meal other_meal) {
    if (people == other_meal.getPeople() && mealtype == other_meal.getMealType()) {
        return true;
    }
    else {
        return false;
    }
}

bool Meal::isLesser(Meal other_meal) {
    if (mealtype < other_meal.getMealType()) return true;
    if (mealtype > other_meal.getMealType()) return false;
    if (people < other_meal.getPeople()) return true;
    if (people > other_meal.getPeople()) return false;
    else return false;
}

MealType Meal::stringfiedToMealType(std::string string_meal_type) {
    if (string_meal_type == "Breakfast") {
        return Breakfast;
    }
    else if (string_meal_type == "Launch") {
        return Launch;
    }
    else if (string_meal_type == "Dinner") {
        return Dinner;
    }
    else {
        return None;
    }
}

std::string Meal::mealTypeToString(MealType meal_type) {
    std::string stringfied = "";
    switch (meal_type)
    {
    case Breakfast:
        stringfied = "Breakfast";
        break;
    case Launch:
        stringfied = "Launch";
        break;
    case Dinner:
        stringfied = "Dinner";
        break;
    case None:
        stringfied = "None";
        break;
    default:
        break;
    }
    return stringfied;
}