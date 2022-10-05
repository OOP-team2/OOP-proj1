//RecipeDB
#include "RecipeDatabase.h"
#include "Parser.h"
#include <vector>
#include <string>
#include <algorithm>

/*
    Constructor
    : Load recipes from FileManager and push to runtime database
*/
RecipeDatabase::RecipeDatabase(){
    // std::vector< std::vector<std::string> > data;
    file_manager = FileManager("DB_Recipe.txt");
    data = file_manager.loadRecipeDB();

    std::vector<std::string> ingredients;
    std::vector<std::string> cooking_order; 
    for(std::vector <std::string> recipe : data){
        ingredients = Parser().split(recipe[3],',');
        cooking_order = Parser().split(recipe[4], ',');
        recipe_list.push_back(Recipe(stoi(recipe[0]), recipe[1], stoi(recipe[2]), ingredients, cooking_order));
    }
}

// Add new recipe to database
void RecipeDatabase::insertRecipe(Recipe recipe){
    recipe_list.push_back(recipe);
}

// Delete selected recipe from database
void RecipeDatabase::deleteRecipe(Recipe recipe){
    for(int i = 0; i < recipe_list.size(); i++){
        if(isEqual(recipe_list[i],recipe)){
            recipe_list.erase(recipe_list.begin() + i);
        }
    }
} 

// Update selected recipe
void RecipeDatabase::updateRecipe(Recipe recipe){
    for(Recipe existingRecipe : recipe_list){
        if(isEqual(existingRecipe,recipe)){
            existingRecipe.setRecipeName(recipe.getRecipeName());
            existingRecipe.setPrepareTime(recipe.getPrepareTime());
            existingRecipe.setIngredients(recipe.getIngredients());
            existingRecipe.setCookingOrder(recipe.getCookingOrder());
        }
    }
}

// Search recipe by name
std::vector<Recipe> RecipeDatabase::searchRecipesByIngredient(std::string ingredient){
    std::vector<Recipe> searched_list;

    for(Recipe existingRecipe : recipe_list){
        if(hasIngredient(existingRecipe, ingredient)){
            searched_list.push_back(existingRecipe);
        }
    }

    return searched_list;
}

// Search recipe by ingredient
std::vector<Recipe> RecipeDatabase::searchRecipesByRecipeName(std::string recipename){
    std::vector<Recipe> searched_list;

    for(Recipe existingRecipe : recipe_list){
        if(isSameName(existingRecipe, recipename)){
            searched_list.push_back(existingRecipe);
        }
    }
 
    return searched_list;
}


// Getter
std::vector<Recipe> RecipeDatabase::getRecipes(){
    return recipe_list;
}

/*
    Util function
    : Use only in DB class. not visible from outside
*/

// Compare name of two recipes
bool RecipeDatabase::isSameName(Recipe existingRecipe, std::string recipename){
    if(existingRecipe.getRecipeName().compare(recipename)) return true;
    else return false;
}

// Check if the recipe has the ingredient
bool RecipeDatabase::hasIngredient(Recipe existingRecipe, std::string ingredient){
    for(Ingredient ingredients : existingRecipe.getIngredients()){
        if(ingredients.getName().compare(ingredient)) return true;
    }
    return false;
}

// Compare two recipes to see if they are the same
bool RecipeDatabase::isEqual(Recipe r1, Recipe r2){
    if(r1.getID() == r2.getID())
        return true;
    else
        return false;
}


/*
    UI function
*/

// Print whole recipes in DB to console
void RecipeDatabase::showAllRecipes(){
    for(int i = 0; i < recipe_list.size(); i++){
        std::cout<<i<<". "<<recipe_list[i].getRecipeName()<<std::endl;
    }
}

Recipe RecipeDatabase::recipeInputUI() {
    int id, prepare_time;
    std::string input, name;
    std::vector<std::string> ingredients, order;

    //get recipe_name
    std::cout << "\n";
    std::cout << "Recipe Name: ";
    std::cin >> name;

    //get ingredient_Information
    std::cout << "\n";
    std::cout << "(If you want to stop add_ingredient, please enter \"stop\")";
    while (input != "stop") {
        int i = 1;
        std::cout << "[" << i++ << "]" << " Ingredient & Weight: ";
        std::cin >> input;
        ingredients.push_back(input);
    }
    input = "";

    //get preparation_time
    std::cout << "\n";
    std::cout << "Prepare Time(minutes): ";
    std::cin >> prepare_time;

    //get cooking order
    std::cout << "\n";
    std::cout << "(If you want to stop add_ingredient, please enter \"stop\")";
    while (input != "stop") {
        int i = 1;
        std::cout << "[" << i++ << "]" << " Order: ";
        std::cin >> input;
        order.push_back(input);
    }
    
    return Recipe(id, name, prepare_time, ingredients, order); 
}