//RecipeDB
#include "RecipeDatabase.h"
#include <vector>
#include <string>

RecipeDatabase::RecipeDatabese(){
    std::vector< std::vector<std::string> > data;
    file_manager = FileManager();
    data = file_manager.load();                                                 // 데이터 불러오기

    for(auto recipe = data.begins(); recipe != data.end(); recipe++){           // DB 초기화
        recipe_list.push_back(Recipe(recipe));
    }
}

void insertRecipe(Recipe recipe){
    recipe_list.push_back(recipe);
}

void deleteRecipe(Recipe recipe){
    for(auto existingRecipe = recipe_list.begins(); existingRecipe != recipe_list.end(); existingRecipe++){
        if(*existingRecipe == recipe){
            recipe_list.erase(existingRecipe);
        }
    }
}

void updateRecipe(Recipe recipe){
    for(auto existingRecipe = recipe_list.begins(); existingRecipe != recipe_list.end(); existingRecipe++){
        if(*existingRecipe == recipe){
            existingRecipe.setRecipeName(recipe.getRecipeName());
            existingRecipe.setTime(recipe.getTime());
            existingRecipe.setIngredients(recipe.getIngredients());
            existingRecipe.setCookingOrder(recipe.getCookingOrder());
        }
    }
}

std::vector<Recipe> getRecipes(){
    return recipe_list;
}

std::vector<Recipe> searchRecipesByIngredient(std::string ingredient){
    std::vector<Recipe> searched_list;

    auto it = find_if(recipe_list.begins() , recipe_list.end(), hasIngredient(it, ingredient));
    while (it != recipe_list.end()) {
        searched_list.push_back(it)
        it = find_if(it+1, recipe_list.end(), hasIngredient(it+1, ingredient));
    }

    return searched_list;
}

std::vector<Recipe> searchRecipesByRecipeName(std::string recipename){
    std::vector<Recipe> searched_list;

    auto it = find_if(recipe_list.begins() , recipe_list.end(), isSameName(it, recipename));
    while (it != recipe_list.end()) {
        searched_list.push_back(it)
        it = find_if(it+1, recipe_list.end(), isSameName(it+1, recipename));
    }

    return searched_list;
}

bool isSameName(auto it, std::string recipename){
    if(it.getRecipeName() == recipename) return true;
    else return false;
}

bool hasIngredient(auto it, std::string ingredient){
    for(auto it2 = it.getIngredients().begins(); it2 != it.getIngredients.end(); it2++){
        if(it2.getName() == ingredient) return true;
    }
    return false;
}