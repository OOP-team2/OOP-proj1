//RecipeDB
#include "RecipeDatabase.h"
#include <vector>
#include <string>
#include <algorithm>

RecipeDatabase::RecipeDatabase(){
    std::vector< std::vector<std::string> > data;
    file_manager = FileManager();
    data = file_manager.load();                                                 // 데이터 불러오기

    int i = 0;
    for(auto recipe = data.begin(); recipe != data.end(); recipe){              // DB 초기화
        recipe_list.push_back(Recipe());                                        // input file 형식이 지정되면 작성
    }
}

void RecipeDatabase::insertRecipe(Recipe recipe){
    recipe_list.push_back(recipe);
}

void RecipeDatabase::deleteRecipe(Recipe recipe){
    for(int i = 0; i < recipe_list.size(); i++){
        if(isEqual(recipe_list[i],recipe)){
            recipe_list.erase(recipe_list.begin() + i);
        }
    }
} 

void RecipeDatabase::updateRecipe(Recipe recipe){
    for(Recipe existingRecipe : recipe_list){
        if(isEqual(existingRecipe,recipe)){
            existingRecipe.setRecipeName(recipe.getRecipeName());
            existingRecipe.setTime(recipe.getTime());
            existingRecipe.setIngredients(recipe.getIngredients());
            existingRecipe.setCookingOrder(recipe.getCookingOrder());
        }
    }
}

std::vector<Recipe> RecipeDatabase::getRecipes(){
    return recipe_list;
}

std::vector<Recipe> RecipeDatabase::searchRecipesByIngredient(std::string ingredient){
    std::vector<Recipe> searched_list;

    for(Recipe existingRecipe : recipe_list){
        if(hasIngredient(existingRecipe, ingredient)){
            searched_list.push_back(existingRecipe);
        }
    }

    return searched_list;
}

std::vector<Recipe> RecipeDatabase::searchRecipesByRecipeName(std::string recipename){
    std::vector<Recipe> searched_list;

    for(Recipe existingRecipe : recipe_list){
        if(isSameName(existingRecipe, recipename)){
            searched_list.push_back(existingRecipe);
        }
    }
 
    return searched_list;
}

bool RecipeDatabase::isSameName(Recipe existingRecipe, std::string recipename){
    if(existingRecipe.getRecipeName() == recipename) return true;
    else return false;
}

bool RecipeDatabase::hasIngredient(Recipe existingRecipe, std::string ingredient){
    for(Ingredient ingredients : existingRecipe.getIngredients()){
        if(ingredients.getName() == ingredient) return true;
    }
    return false;
}

bool RecipeDatabase::isEqual(Recipe r1, Recipe r2){
    if(r1.getRecipeName() == r2.getRecipeName() 
        && r1.getCookingOrder() == r2.getCookingOrder()
        && r1.getIngredients() == r2.getIngredients()
        && r1.getTime() == r2.getTime())
        return true;

    else
        return false;
}
