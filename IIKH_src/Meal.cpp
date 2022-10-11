#include "Meal.h"

// initialize a Meal instance
Meal::Meal() {};
// initialize mealtype and people
Meal::Meal(MealType new_mealtype, std::string new_people) {
    mealtype = new_mealtype;
    people = new_people;
};

// returns mealtype
MealType Meal::getMealType() {
    return mealtype;
}

// set new value to mealtype
void Meal::setMealType(MealType new_mealtype) {
    mealtype = new_mealtype;
}

// returns people
std::string Meal::getPeople() {
    return people;
}

// set new value to people
void Meal::setPeople(std::string new_people) {
    people = new_people;
}

// pushes new recipe back to recipes
void Meal::addRecipe(Recipe recipe) {
    recipes.push_back(recipe);
    std::cout << "a recipe is added" << std::endl;
    return;
}

// set new value to recipes
void Meal::setRecipes(std::vector<Recipe> ex_recipes) {
    recipes = ex_recipes;
}

// delete a recipe from recipes
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

// returns recipes
std::vector<Recipe> Meal::getRecipes() {
    return recipes;
}

// print out all recipe info in recipes
void Meal::showRecipes() {
    for (auto recipe : recipes) {
        recipe.showInfo();
    }
    return;
}

// examine other meal to check if same meal
bool Meal::isSame(Meal other_meal) {
    if (people == other_meal.getPeople() && mealtype == other_meal.getMealType()) {
        return true;
    }
    else {
        return false;
    }
}

// examine other meal to check if less meal
bool Meal::isLess(Meal other_meal) {
    if (mealtype < other_meal.getMealType()) return true;
    if (mealtype > other_meal.getMealType()) return false;
    if (people < other_meal.getPeople()) return true;
    if (people > other_meal.getPeople()) return false;
    else return false;
}

// recives a stringfied meal type then returns a MealType
MealType Meal::stringfiedToMealType(std::string string_meal_type) {
    if (string_meal_type == "Breakfast") {
        return Breakfast;
    }
    else if (string_meal_type == "Lunch") {
        return Lunch;
    }
    else if (string_meal_type == "Dinner") {
        return Dinner;
    }
    else {
        return None;
    }
}

// recives a MealType then returns stringfied MealType
std::string Meal::mealTypeToString(MealType meal_type) {
    std::string stringfied = "";
    switch (meal_type)
    {
    case Breakfast:
        stringfied = "Breakfast";
        break;
    case Lunch:
        stringfied = "Lunch";
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