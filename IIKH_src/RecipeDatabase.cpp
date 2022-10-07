//RecipeDB
#include "RecipeDatabase.h"
#include "Parser.h"
#include <vector>
#include <string>

/*
    Constructor
    : Load recipes from FileManager and push to runtime database
*/
RecipeDatabase::RecipeDatabase(){
    // std::vector< std::vector<std::string> > data;
    file_manager = FileManager("DB_Recipe.txt");
    data = file_manager.loadRecipeDB();

    int i = 0;
    for(auto recipe = data.begin(); recipe != data.end(); recipe){
        recipe_list.push_back(Recipe());
    }
}

// function returns RecipeDatabase itself to be used as Singleton
RecipeDatabase* RecipeDatabase::getInstance() {
    if (recipeDB == NULL) {
        recipeDB = new RecipeDatabase();
    }
    return recipeDB;
}

// Print whole recipes in DB to console
void RecipeDatabase::showAllRecipes(){
    for(int i = 0; i < recipe_list.size(); i++){
        std::cout<<to_string(i)<<". "<<recipe_list[i].getRecipeName()<<std::endl;
    std::vector<std::string> ingredients;
    std::vector<std::string> cooking_order; 
    for(std::vector <std::string> recipe : data){
        ingredients = Parser::split(recipe[3],',');
        cooking_order = Parser::split(recipe[4], ',');
        recipe_list.push_back(Recipe(stoi(recipe[0]), recipe[1], stoi(recipe[2]), ingredients, cooking_order));     // recipe생성자 수정예정
    }
}

// Add new recipe to database
void RecipeDatabase::insertRecipe(){
    Recipe recipe = recipeInputUI();
    
    recipe_list.push_back(recipe);
    updatedata();
    file_manager.writeRecipeDB(data);
    return;
}

// Delete selected recipe from database
void RecipeDatabase::deleteRecipe(){
    std::cout << "Select Recipe you want to delete" << std::endl;
    showAllRecipes();
    int num = recipeNumInputUI();

    recipe_list.erase(recipe_list.begin() + (num-1));
    updatedata();
    file_manager.writeRecipeDB(data);
    return;
} 

// Update selected recipe
void RecipeDatabase::updateRecipe(){
    Recipe recipe;
    
    std::cout << "Select Recipe you want to update" << std::endl;
    showAllRecipes();
    int num = recipeNumInputUI();
    
    recipe = recipe_list[num-1];
    Recipe new_recipe = recipeInputUI(recipe);

    recipe.setRecipeName(new_recipe.getRecipeName());
    recipe.setPrepareTime(new_recipe.getPrepareTime());
    recipe.setIngredients(new_recipe.getIngredients());
    recipe.setCookingOrder(new_recipe.getCookingOrder());

    updatedata();
    file_manager.writeRecipeDB(data);
    return;
}

// Search recipe by name
std::vector<Recipe> RecipeDatabase::searchRecipesByIngredient(){
    std::vector<Recipe> searched_list;
    std::string ingredient = recipeIngredientInputUI();

    for(Recipe existingRecipe : recipe_list){
        if(hasIngredient(existingRecipe, ingredient)){
            searched_list.push_back(existingRecipe);
        }
    }

    for(Recipe recipe : searched_list)
        recipe.printRecipe();

    return searched_list;
}

// Search recipe by ingredient
std::vector<Recipe> RecipeDatabase::searchRecipesByRecipeName(){
    std::vector<Recipe> searched_list;
    std::string recipename = recipeIngredientInputUI();

    for(Recipe existingRecipe : recipe_list){
        if(isSameName(existingRecipe, recipename)){
            searched_list.push_back(existingRecipe);
        }
    }

    for(Recipe recipe : searched_list)
        recipe.printRecipe();
 
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


void RecipeDatabase::updatedata(){
    std::string ingredients = "";
    std::string cooking_order;
    std::vector<std::string> recipe_string;

    data.clear();

    for(Recipe recipe : recipe_list){
        for(int i = 0; i < recipe.getIngredients().size(); i++){
            ingredients += recipe.getIngredients()[i].getName();
            ingredients += ", ";
        }
        for(int i = 0; i < recipe.getCookingOrder().size(); i++){
            cooking_order += recipe.getCookingOrder()[i];
            cooking_order += ", ";
        }
        recipe_string.push_back(to_string(recipe.getID()));
        recipe_string.push_back(recipe.getRecipeName());
        recipe_string.push_back(to_string(recipe.getPrepareTime()));
        recipe_string.push_back(ingredients);
        recipe_string.push_back(cooking_order);

        data.push_back(recipe_string);
    }

    return;
}

/*
    UI function
*/

// Print whole recipes in DB to console
void RecipeDatabase::showAllRecipes(){
    for(int i = 0; i < recipe_list.size(); i++){
        std::cout<<i+1<<". "<<recipe_list[i].getRecipeName()<<std::endl;
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
    std::cout << "(If you want to stop add_ingredient, please enter \"stop\")" << std::endl;
    int i = 1;
    while (input != "stop") {
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
    std::cout << "(If you want to stop add_order, please enter \"stop\")" << std::endl;
    i = 1;
    while (input != "stop") {
        std::cout << "[" << i++ << "]" << " Order: ";
        std::cin >> input;
        order.push_back(input);
    }
    
    return Recipe(id, name, prepare_time, ingredients, order); 
}

Recipe RecipeDatabase::recipeInputUI(Recipe recipe) {
    int id, prepare_time;
    std::string input, name;
    std::vector<std::string> ingredients, order;

    //get recipe_name
    std::cout << "\n";
    std::cout << "Recipe Name: " << recipe.getRecipeName() << "-->";
    std::getline(std::cin, name);

    if(name.compare("\n")) 
        name = recipe.getRecipeName();

    //get ingredient_Information
    std::cout << "\n";
    std::cout << "(If you want to stop add_ingredient, please enter \"stop\")" << std::endl;

    int i = 1;
    while (input != "stop") {
        if(i-1 < recipe.getIngredients().size()){
            std::cout << "[" << i << "]" << " Ingredient & Weight: " << recipe.getIngredients()[i-1].getName() << "-->";
            std::getline(std::cin, input);
            if(name.compare("\n")) 
                input = recipe.getIngredients()[i-1].getName();
        }
        else{
            std::cout << "[" << i << "]" << " Ingredient & Weight: ";
            std::cin >> input;
        }  
        ingredients.push_back(input);
        i++;
    }
    input = "";

    //get preparation_time
    std::cout << "\n";
    std::cout << "Prepare Time(minutes): ";
    std::cin >> prepare_time;

    //get cooking order
    std::cout << "\n";
    std::cout << "(If you want to stop add_order, please enter \"stop\")" << std::endl;
    i = 1;
    while (input != "stop") {
        if(i-1 < recipe.getCookingOrder().size()){
            std::cout << "[" << i << "]" << " Order: " << recipe.getCookingOrder()[i-1] << "-->";
            std::getline(std::cin, input);
            if(name.compare("\n")) 
                input = recipe.getCookingOrder()[i-1];
        }
        else{
            std::cout << "[" << i++ << "]" << " Order: ";
            std::cin >> input;
        }  
        order.push_back(input);
        i++;
    }
    
    return Recipe(id, name, prepare_time, ingredients, order); 
}

int RecipeDatabase::recipeNumInputUI() {
    int number;

    std::cout << "\n";
    std::cout << "Input Recipe Number: ";
    std::cin >> number;

    return number;
}

std::string RecipeDatabase::recipeNameInputUI() {
    std::string s_recipeName;
    
    std::cout << "\n";
    std::cout << "Input Recipe Name: ";
    std::cin >> s_recipeName;

    return s_recipeName;
}

std::string RecipeDatabase::recipeIngredientInputUI() {
    std::string s_Ingredient;
    
    std::cout << "\n";
    std::cout << "Input Recipe Ingredient: ";
    std::cin >> s_Ingredient;

    return s_Ingredient;
}