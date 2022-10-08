//RecipeDB
#include "RecipeDatabase.h"

/*
    Constructor
    : Load recipes from FileManager and push to runtime database
*/

RecipeDatabase* RecipeDatabase::recipe_db = NULL;
FileManager RecipeDatabase::file_manager = FileManager();
std::vector< std::vector<std::string> > RecipeDatabase::data = {};
std::vector<Recipe> RecipeDatabase::recipe_list = {};

RecipeDatabase::RecipeDatabase(){
    std::vector< std::vector<std::string> > data;
    file_manager = FileManager();
    data = file_manager.loadRecipeDB();

    int i = 0;
    for(std::vector <std::string> recipe : data){
        std::vector<std::string> ingredients = Parser().split(recipe[2], ',');
        std::set<std::string> set_ingredients;
        for (auto ing : ingredients) {
            set_ingredients.insert(ing);
        }
        std::vector<std::string> cooking_order = Parser().split(recipe[3], ',');
        recipe_list.push_back(Recipe(recipe[0], recipe[1], set_ingredients, cooking_order));
    }
}

// function returns RecipeDatabase itself to be used as Singleton
RecipeDatabase* RecipeDatabase::getInstance() {
    if (recipe_db == NULL) {
        recipe_db = new RecipeDatabase();
    }
    return recipe_db;
}

// Print whole recipes in DB to console
void RecipeDatabase::showAllRecipes(){
    for (auto recipe : recipe_list) {
        recipe.showInfo();
    }
    std::cout << "every recipe is shown up" << std::endl;
}

// Add new recipe to database
void RecipeDatabase::insertRecipe(){
    Recipe recipe = recipeInputUI();
    
    recipe_list.push_back(recipe);
    updatedata();
    return;
}

// Delete selected recipe from database
void RecipeDatabase::deleteRecipe(){
    std::cout << "Select Recipe you want to delete" << std::endl;
    RecipeDatabase::showAllRecipes();
    int num = recipeNumInputUI();

    recipe_list.erase(recipe_list.begin() + (num-1));
    updatedata();
    return;
} 

// Update selected recipe
void RecipeDatabase::updateRecipe(){
    Recipe recipe;
    
    std::cout << "Select Recipe you want to update" << std::endl;
    RecipeDatabase::showAllRecipes();
    int num = recipeNumInputUI();
    
    recipe = recipe_list[num-1];
    Recipe new_recipe = recipeInputUI(recipe);

    auto position = recipe_list.begin() + num - 1;
    recipe_list.erase(position);
    recipe_list.insert(position,new_recipe);

//    recipe_list[num-1].setRecipeName(new_recipe.getRecipeName());
//    recipe_list[num-1].setPrepareTime(new_recipe.getPrepareTime());
//    recipe_list[num-1].setIngredients(new_recipe.getIngredients());
//  recipe_list[num-1].setCookingOrder(new_recipe.getCookingOrder());
    updatedata();
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

    return searched_list;
}

// Search recipe by ingredient
std::vector<Recipe> RecipeDatabase::searchRecipesByRecipeName(){
    std::vector<Recipe> searched_list;
    std::string recipename = recipeNameInputUI();

    for(Recipe existingRecipe : recipe_list){
        int pos = 0;
        int index;
        while ((index = existingRecipe.getRecipeName().find(recipename, pos)) != std::string::npos) {
            pos = index + 1; //new position is from next element of index
        }
        if (pos != 0) {
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
    if(existingRecipe.getRecipeName() == recipename) return true;
    else return false;
}

// Check if the recipe has the ingredient
bool RecipeDatabase::hasIngredient(Recipe existingRecipe, std::string ingredient){
    return existingRecipe.hasIngredient(ingredient);
}

// Compare two recipes to see if they are the same
bool RecipeDatabase::isEqual(Recipe r1, Recipe r2){
    if(r1.getRecipeName() == r2.getRecipeName())
        return true;
    else
        return false;
}


void RecipeDatabase::updatedata() {
    std::string ingredients = "";
    std::string cooking_order;
    std::vector<std::string> recipe_string;
    
    data.clear();
    std::string lineToWrite;
    std::vector<std::string> linesToWrite;
    for(Recipe recipe : recipe_list){
        lineToWrite = "";
        lineToWrite += recipe.getRecipeName();
        lineToWrite += "/";

        lineToWrite += recipe.getPrepareTime();
        lineToWrite += "/";

        ingredients = "";
        for(auto ing : recipe.getIngredients()){
            ingredients += ing;
            ingredients += ",";
        }
        lineToWrite += ingredients;
        lineToWrite += "/";

        cooking_order = "";
        for(int i = 0; i < recipe.getCookingOrder().size(); i++){
            cooking_order += recipe.getCookingOrder()[i];
            cooking_order += ",";
        }
        lineToWrite += cooking_order;
        lineToWrite += "/";

        linesToWrite.push_back(lineToWrite);

        recipe_string.push_back(recipe.getRecipeName());
        recipe_string.push_back(recipe.getPrepareTime());
        recipe_string.push_back(ingredients);
        recipe_string.push_back(cooking_order);

        data.push_back(recipe_string);
    }

    file_manager.writeRecipeDB(linesToWrite);
    return;
}

/*
    UI function
*/

Recipe RecipeDatabase::recipeInputUI() {
    std::string prepare_time;
    std::string input, name;
    std::vector<std::string> order;
    std::set<std::string> ingredients;

    //get recipe_name
    std::cout << "\n";
    std::cout << "Recipe Name: ";
    std::getline(std::cin,name);

    //get preparation_time
    std::cout << "\n";
    std::cout << "Preparation Time(minutes): ";
    std::getline(std::cin,prepare_time);

    //get ingredient_Information
    std::cout << "\n";
    std::cout << "(If you want to stop adding ingredient, please enter \"stop\")" << std::endl;
    int i = 1;
    while (input != "stop") {
        std::cout << "[" << i++ << "]" << " Ingredient: ";
        std::getline(std::cin,input);
        if (input == "stop") break;
        ingredients.insert(input);
    }
    input = "";


    //get cooking order
    std::cout << "\n";
    std::cout << "(If you want to stop adding cooking order, please enter \"stop\")" << std::endl;
    i = 1;
    while (input != "stop") {
        std::cout << "[" << i++ << "]" << "Cooking Order: ";
        std::getline(std::cin,input);
        if (input == "stop") break;
        order.push_back(input);
    }
    
    return Recipe(name, prepare_time, ingredients, order); 
}

Recipe RecipeDatabase::recipeInputUI(Recipe recipe) {
    std::string input;
    std::string name, prepare_time;
    std::set<std::string> ingredients;
    std::vector<std::string> order;

    //get recipe_name
    std::cout << "\n";
    std::cout << "Recipe Name: ";
    std::getline(std::cin,name);

    if (name.empty()) {
        name = recipe.getRecipeName();
    }

    //get preparation_time
    std::cout << "\n";
    std::cout << "Preparation Time(minutes): ";
    std::getline(std::cin,prepare_time);

    if (prepare_time.empty()) {
        prepare_time = recipe.getPrepareTime();
    }

    //get ingredient_Information
    std::cout << "\n";
    std::cout << "(If you want to keep existing ingredient, press just enter)" << std::endl;
    std::cout << "(If you want to stop updating ingredients, please enter \"stop\")" << std::endl; 

    int i = 1;
    std::set<std::string> ex_ingredients = recipe.getIngredients();
    auto ingredient = ex_ingredients.begin();
    while (input != "stop") {
        if(i-1 < ex_ingredients.size()) {
            std::cout << "[" << i << "]" << "Change Ingredient: from " << *ingredient << " to ";
            getline(std::cin, input);
            if (input.empty()) {
                input = *ingredient;
            }
        }
        else{
            std::cout << "[" << i << "]" << "Add New Ingredient: ";
            getline(std::cin, input);
        }
        if (input == "stop") break;
        ingredients.insert(input);
        ingredient++;
        i++;
    }
    input.clear();


    //get cooking order
    std::cout << "\n";
    std::cout << "(If you want to keep existing cooking order, press just enter)" << std::endl;
    std::cout << "(If you want to stop updating cooking order, please enter \"stop\")" << std::endl;
    i = 1;
    std::vector<std::string> cooking_order = recipe.getCookingOrder();
    while (input != "stop") {
        if(i-1 < cooking_order.size()){
            std::cout << "[" << i << "]" << "Change Cooking Order: from " << cooking_order[i-1] << " to ";
            std::getline(std::cin, input);
            if (input.empty()) {
                input = cooking_order[i-1];
            }
        }
        else{
            std::cout << "[" << i++ << "]" << "Add New Cooking Order: ";
            std::getline(std::cin, input);
        }
        if (input == "stop") break;
        order.push_back(input);
        i++;
    }
    
    return Recipe(name, prepare_time, ingredients, order); 
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
    std::getline(std::cin,s_recipeName);

    return s_recipeName;
}

std::string RecipeDatabase::recipeIngredientInputUI() {
    std::string s_Ingredient;
    
    std::cout << "\n";
    std::cout << "Input Recipe Ingredient: ";
    std::getline(std::cin,s_Ingredient);

    return s_Ingredient;
}