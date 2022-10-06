#pragma once
#include "Recipe.h"

Recipe::Recipe(std::string new_recipe_name,int new_prepare_time, std::set<Ingredient> new_ingredients, std::vector<std::string> new_cooking_order) {
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
int Recipe::getPrepareTime(){
    return prepare_time;
}
// function to get ingredients
std::set<Ingredient> Recipe::getIngredients(){
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
void Recipe::setPrepareTime(int new_prepare_time) {
    prepare_time = new_prepare_time;
}
void Recipe::setIngredients(std::set<Ingredient> new_ingredients) {
    ingredients = new_ingredients;
}
void Recipe::setCookingOrder(std::vector<std::string> order){
    cooking_order = order;
}

//function
void Recipe::editIngredient(Ingredient edit_ingredient){
    auto iter = ingredients.begin();
    for (Ingredient ing : ingredients) {
        if (ing.getName() == edit_ingredient.getName()) {
            break;
        }
        iter++;
    }
    ingredients.erase(iter);
    std::cout << "enter a new ingredient name: ";
    string new_ing_name;
    std::cin >> new_ing_name;
    Ingredient new_ingredient = Ingredient(new_ing_name);
    ingredients.insert(edit_ingredient);
}

void Recipe::deleteIngredient(std::string ingredientName){
    auto iter = ingredients.begin();
    for (Ingredient ing : ingredients) {
        if (ing.getName() == ingredientName) {
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

// function to show recipe information
void Recipe::showInfo(){
    std::cout << " Recipe Name: " << recipe_name << std::endl;
    std::cout << " Cooking Time: " << prepare_time << std::endl;

    if (ingredients.size())
    {
        std::cout << std::endl;
        std::cout << " [Ingredients in this Recipe]" << std::endl;
        for (auto ing : ingredients) {
            std::cout << " - " << ing.getName() << '\n';
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
    
    std::cout<<"\n\n\n";
}


bool Recipe::operator==(Recipe other_recipe) {
    if (recipe_name == other_recipe.getRecipeName() && prepare_time == other_recipe.getPrepareTime()) {
        return true;
    }
    else {
        return false;
    }
}