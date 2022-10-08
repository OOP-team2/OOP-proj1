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

    for(std::vector <std::string> recipe : data){
        std::vector<std::string> ingredients = Parser::split(recipe[2], ',');
        std::set<std::string> set_ingredients;
        for (auto ing : ingredients) {
            set_ingredients.insert(ing);
        }
        std::vector<std::string> cooking_order = Parser::split(recipe[3], ',');
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
    for (int i = 0; i < recipe_list.size(); i++) {
        std::cout<<i+1<<". "<<recipe_list[i].getRecipeName()<<std::endl;
    }
    std::cout << "every recipe is shown up" << std::endl;
}

void RecipeDatabase::showRecipe(){
    std::cout<<"\n";
    std::cout << "Select Recipe you want to see" << std::endl;
    int num = recipeNumInputUI();
    recipe_list[num-1].showInfo();
}

// Add new recipe to database
void RecipeDatabase::insertRecipe(){
    Recipe recipe = recipeInputUI();
    
    recipe_list.push_back(recipe);
    updatedata();
    file_manager.writeRecipeDB(data);

    std::cout << "Recipe is added to list" << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    return;
}

// Delete selected recipe from database
void RecipeDatabase::deleteRecipe(){
    std::cout << "Select Recipe you want to delete" << std::endl;
    RecipeDatabase::showAllRecipes();
    int num = recipeNumInputUI();

    recipe_list.erase(recipe_list.begin() + (num-1));
    updatedata();
    file_manager.writeRecipeDB(data);
    return;
} 

// Update selected recipe
void RecipeDatabase::updateRecipe(){
    Recipe* recipe;
    
    std::cout << "Select Recipe you want to update" << std::endl;
    RecipeDatabase::showAllRecipes();
    int num = recipeNumInputUI();
    
    recipe = &recipe_list[num-1];
    Recipe new_recipe = recipeInputUI(*recipe);

    recipe->setRecipeName(new_recipe.getRecipeName());
    recipe->setPrepareTime(new_recipe.getPrepareTime());
    recipe->setIngredients(new_recipe.getIngredients());
    recipe->setCookingOrder(new_recipe.getCookingOrder());

    updatedata();
    file_manager.writeRecipeDB(data);

    std::cout << "Recipe is updated" << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
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

    if(searched_list.size() == 0)
        std::cout<<"No such recipe"<<std::endl;
    else{
        for(Recipe recipe : searched_list)
        recipe.showInfo();
    }

    return searched_list;
}

// Search recipe by ingredient
std::vector<Recipe> RecipeDatabase::searchRecipesByRecipeName(){
    std::vector<Recipe> searched_list;
    std::string recipename = recipeIngredientInputUI();

    for(Recipe existingRecipe : recipe_list){
        std::string name = existingRecipe.getRecipeName();
        if (name.find(recipename) != std::string::npos && name.find(recipename) >= 0)
            searched_list.push_back(existingRecipe);
    }

    if(searched_list.size() == 0)
        std::cout<<"No such recipe"<<std::endl;
    else{
        for(Recipe recipe : searched_list)
        recipe.showInfo();
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
    return existingRecipe.hasIngredient(ingredient);
}

// Compare two recipes to see if they are the same
bool RecipeDatabase::isEqual(Recipe r1, Recipe r2){
    if(r1.getRecipeName() == r2.getRecipeName())
        return true;
    else
        return false;
}

// syncronize recipe_list and data to write file
void RecipeDatabase::updatedata(){
    std::string ingredients;
    std::string cooking_order;
    std::vector<std::string> recipe_string;

    data.clear();

    for(Recipe recipe : recipe_list){
        for(auto ing : recipe.getIngredients()){
            if(ing == "\n" || ing == " ")
                continue;
            ingredients += ing;
            ingredients += ",";
        }
        for(int i = 0; i < recipe.getCookingOrder().size(); i++){
            if(recipe.getCookingOrder()[i] == "\n" || recipe.getCookingOrder()[i] == " ")
                continue;
            cooking_order += recipe.getCookingOrder()[i];
            cooking_order += ",";
        }
        recipe_string.push_back(recipe.getRecipeName());
        recipe_string.push_back(recipe.getPrepareTime());
        recipe_string.push_back(ingredients);
        recipe_string.push_back(cooking_order);

        data.push_back(recipe_string);

        ingredients.clear();
        cooking_order.clear();
        recipe_string.clear();
    }

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
    std::cout << "Recipe Name: "<< std::flush;
    std::getline(std::cin, name);

    //get ingredient_Information
    std::cout << "\n";
    std::cout << "(If you want to stop add_ingredient, please enter \"stop\")" << std::endl;
    int i = 1;
    while (true) {
        std::cout << "[" << i++ << "]" << " Ingredient: "<< std::flush;
        std::getline(std::cin, input);
        if (input == "stop")
            break;
        else
            ingredients.insert(input);
    }
    input.clear();

    //get preparation_timev
    std::cout << "\n";
    std::cout << "Prepare Time(minutes): "<< std::flush;
    std::getline(std::cin, prepare_time);

    //get cooking order
    std::cout << "\n";
    std::cout << "(If you want to stop add_order, please enter \"stop\")" << std::endl;
    i = 1;
    while (true) {
        std::cout << "[" << i++ << "]" << " Order: "<< std::flush;
        std::getline(std::cin, input);
        if (input == "stop")
            break;
        else
            order.push_back(input);
    }
    
    return Recipe(name, prepare_time, ingredients, order); 
}

Recipe RecipeDatabase::recipeInputUI(Recipe recipe) {
    std::string prepare_time;
    std::string input, name;
    std::vector<std::string> order;
    std::set<std::string> ingredients;

    //get recipe_name
    std::cout << "\n";
    std::cout << "Recipe Name: " << recipe.getRecipeName() << "-->" << std::flush;
    std::getline(std::cin, name);

    if(name.compare("") == 0) 
        name = recipe.getRecipeName();
 
    //get ingredient_Information
    std::cout << "\n";
    std::cout << "(If you want to stop add_ingredient, please enter \"stop\")" << std::endl;

    int i = 1;
    std::set<std::string> ex_ingredients = recipe.getIngredients();
    auto ingredient = ex_ingredients.begin();
    while (true) {
        if(i-1 < ex_ingredients.size()) {
            std::cout << "[" << i << "]" << " Ingredient: " << *ingredient << "-->"<< std::flush;
            std::getline(std::cin, input);
            if(input.compare("") == 0) 
                input = *ingredient;
            ingredient++;
        }
        else{
            std::cout << "[" << i << "]" << " Ingredient: " << std::flush;
            std::getline(std::cin, input);
        }
        if (input == "stop")
            break;
        else
            ingredients.insert(input);
        i++;
    }
    input.clear();

    //get preparation_time
    std::cout << "\n";
    std::cout << "Prepare Time(minutes): " << recipe.getPrepareTime() << "-->" << std::flush;
    std::getline(std::cin, prepare_time);

    if(prepare_time.compare("") == 0) 
        prepare_time = recipe.getPrepareTime();

    //get cooking order
    std::cout << "\n";
    std::cout << "(If you want to stop add_order, please enter \"stop\")" << std::endl;
    i = 1;
    while (true) {
        if(i-1 < recipe.getCookingOrder().size()){
            std::cout << "[" << i << "]" << " Order: " << recipe.getCookingOrder()[i-1] << "-->" << std::flush;
            std::getline(std::cin, input);
            if(input.compare("") == 0) 
                input = recipe.getCookingOrder()[i-1];
        }
        else{
            std::cout << "[" << i << "]" << " Order: " << std::flush;
            std::getline(std::cin, input);
        }

        if (input == "stop")
            break;
        else
            order.push_back(input);  
        i++;
    }
    
    return Recipe(name, prepare_time, ingredients, order); 
}

int RecipeDatabase::recipeNumInputUI() {
    int number;

    std::cout << "\n";
    std::cout << "Input Recipe Number: "<< std::flush;
    std::cin >> number;
    std::cin.ignore();

    return number;
}

std::string RecipeDatabase::recipeNameInputUI() {
    std::string s_recipeName;
    
    std::cout << "\n";
    std::cout << "Input Recipe Name: "<< std::flush;

    std::getline(std::cin, s_recipeName);

    return s_recipeName;
}

std::string RecipeDatabase::recipeIngredientInputUI() {
    std::string s_Ingredient;
    
    std::cout << "\n";
    std::cout << "Input Recipe Ingredient: "<< std::flush;

    std::getline(std::cin, s_Ingredient);

    return s_Ingredient;
}