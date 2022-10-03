#ifndef OOP_PROJ1_RECIPEDATABASE_H
#define OOP_PROJ1_RECIPEDATABASE_H

#include "FileManager.h"
#include "Recipe.h"
#include <vector>

class RecipeDatabase{
    private:
        FileManager file_manager;                                                   // file input object
        std::vector<Recipe> recipe_list;
        bool isSameName(Recipe existingRecipe, std::string recipename);
        bool hasIngredient(Recipe existingRecipe, std::string ingredient);
        bool isEqual(Recipe r1, Recipe r2);
    
    public:
        RecipeDatabase();
        void showAllRecipes();
        void insertRecipe(Recipe recipe);
        void deleteRecipe(Recipe recipe);
        void updateRecipe(Recipe recipe);
        std::vector<Recipe> getRecipes();
        std::vector<Recipe> searchRecipesByIngredient(std::string ingredients);
        std::vector<Recipe> searchRecipesByRecipeName(std::string recipename);
};

#endif