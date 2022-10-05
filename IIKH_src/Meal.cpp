//
// Created by HoJoonEum on 2022/09/28.
//

#include "Meal.h"

Meal::Meal() {};
Meal::Meal(MealType new_mealtype, int new_people) {
    mealtype = new_mealtype;
    people = new_people;
};

int Meal::getPeople() {
    return people;
}
void Meal::setPeople(int new_people) {
    people = new_people;
}

void Meal::addRecipe(Recipe recipe) {
    recipes.emplace(recipe);
    std::cout << "a recipe is added" << endl;
    return;
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
        std::cout << "no recipe is found to be deleted" << endl;
    }
    return;
}

std::set<Recipe> Meal::getRecipes() {
    return recipes;
}

void Meal::showRecipes() {
    return;
}

bool Meal::operator==(Meal other_meal) {
    if (people == other_meal.getPeople() && mealtype == other_meal.getMealType()) {
        return true;
    }
    else {
        return false;
    }
}

bool Meal::operator<(Meal other_meal) {
    if (mealtype < other_meal.getMealType()) return true;
    if (mealtype > other_meal.getMealType()) return false;
    if (people < other_meal.getPeople()) return true;
    if (people > other_meal.getPeople()) return false;
    else return false;
}