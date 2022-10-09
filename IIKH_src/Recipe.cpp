#include "Recipe.h"

Recipe::Recipe() {
    recipe_name = "None";
    prepare_time = "00";
}

Recipe::Recipe(std::string new_recipe_name, std::string new_prepare_time, std::set<std::string> new_ingredients, std::vector<std::string> new_cooking_order) {
    recipe_name = new_recipe_name;
    prepare_time = new_prepare_time;
    ingredients = new_ingredients;
    cooking_order = new_cooking_order;
}

// funtion to get recipe name
std::string Recipe::getRecipeName(){
    return recipe_name;
}
// function to get prepare time
std::string Recipe::getPrepareTime(){
    return prepare_time;
}
// function to get ingredients
std::set<std::string> Recipe::getIngredients(){
    return ingredients;
}
// function to get cooking order
std::vector<std::string> Recipe::getCookingOrder(){
    return cooking_order;
}

//set_recipe(correction) 
void Recipe::setRecipeName(std::string name) {
    recipe_name = name;
}
void Recipe::setPrepareTime(std::string new_prepare_time) {
    prepare_time = new_prepare_time;
}
void Recipe::setIngredients(std::set<std::string> new_ingredients) {
    ingredients = new_ingredients;
}
void Recipe::setCookingOrder(std::vector<std::string> order){
    cooking_order = order;
}

//function
void Recipe::editIngredient(std::string edit_ingredient){
    auto iter = ingredients.begin();
    for (std::string ing : ingredients) {
        if (ing== edit_ingredient) {
            break;
        }
        iter++;
    }
    ingredients.erase(iter);

    std::cout << "enter a new ingredient name: ";
    std::string new_ing_name;
    std::cin >> new_ing_name;
    ingredients.insert(edit_ingredient);
}

void Recipe::deleteIngredient(std::string ingredientName){
    auto iter = ingredients.begin();
    for (std::string ing : ingredients) {
        if (ing == ingredientName) {
            break;
        }
        iter++;
    }
    ingredients.erase(iter);
    std::cout << ingredientName << " has been deleted." << std::endl;
}

void Recipe::addCookingOrder(std::string new_cooking_order){
    cooking_order.push_back(new_cooking_order);
}
void Recipe::deleteCookingOrder(std::string cooking_order_to_delete){
    auto iter = cooking_order.begin();
    for (std::string order : cooking_order) {
        if (order == cooking_order_to_delete) {
            break;
        }
        iter++;
    }
    cooking_order.erase(iter);
}

bool Recipe::hasIngredient(std::string ingredient) {
    for(std::string ing : ingredients){
        if (ing.find(ingredient) != std::string::npos && ing.find(ingredient) >= 0)
            return true;
    }
    return false;
}

std::string Recipe::toString() {
    std::string stringfied = "";
    stringfied += recipe_name;
    stringfied += '.';
    stringfied += prepare_time;
    stringfied += '.';
    for (auto ing : ingredients) {
        stringfied += ing;
        stringfied += ',';
    }
    stringfied += '.';
    for (auto co : cooking_order) {
        stringfied += co;
        stringfied += ',';
    }
    return stringfied;
}

// function to show recipe information
void Recipe::showInfo(){
    std::cout << " ----------------------------------------------- " << std::endl;
    std::cout << " Recipe Name: " << recipe_name << std::endl;
    std::cout << " Cooking Time: " << prepare_time << std::endl;

    if (ingredients.size())
    {
        std::cout << std::endl;
        std::cout << " [Ingredients in this Recipe]" << std::endl;
        for (auto ing : ingredients) {
            std::cout << " - " << ing << '\n';
        }
    }

    if (getCookingOrder().size())
    {
        std::cout << std::endl;
        std::cout << " <Cooking Order of this Recipe> " << std::endl;
        for (int i = 0; i < cooking_order.size(); i++)
        {
            std::cout << " " << i + 1 << ". " << cooking_order[i] << std::endl;
        }

    }
    std::cout << " ----------------------------------------------- " << std::endl;
    
    std::cout<<"Press Any key to continue..."<<std::endl;
}


bool Recipe::operator==(Recipe other_recipe) {
    if (recipe_name == other_recipe.getRecipeName() && prepare_time == other_recipe.getPrepareTime()) {
        return true;
    }
    else {
        return false;
    }
}

bool Recipe::operator<(const Recipe& other_recipe) {
    if (recipe_name < other_recipe.recipe_name) return true;
    if (recipe_name > other_recipe.recipe_name) return false;
    if (prepare_time < other_recipe.prepare_time) return true;
    if (prepare_time > other_recipe.prepare_time) return false;
    else return false;
}