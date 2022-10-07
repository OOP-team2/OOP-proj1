//
// Created by HoJoonEum on 2022/09/28.
//

#include "Meal.h"


Meal::Meal() {};
Meal::Meal(MealType new_mealtype, int new_people) {
    mealtype = new_mealtype;
    people = new_people;
};

MealType Meal::getMealType() {
    return mealtype;
}

void Meal::setMealType(MealType new_mealtype) {
    mealtype = new_mealtype;
}

int Meal::getPeople() {
    return people;
}
void Meal::setPeople(int new_people) {
    people = new_people;
}

void Meal::addRecipe(Recipe recipe) {
    recipes.push_back(recipe);
    std::cout << "a recipe is added" << std::endl;
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

bool Meal::operator==(Meal other_meal) {
    if (people == other_meal.getPeople() && mealtype == other_meal.getMealType()) {
        return true;
    }
    else {
        return false;
    }
}

bool Meal::operator<(const Meal& other_meal) {
    if (mealtype < other_meal.mealtype) return true;
    if (mealtype > other_meal.mealtype) return false;
    if (people < other_meal.people) return true;
    if (people > other_meal.people) return false;
    else return false;
}
