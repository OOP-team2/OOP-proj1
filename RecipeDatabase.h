#ifndef OOP_PROJ1_RECIPEDATABASE_H
#define OOP_PROJ1_RECIPEDATABASE_H

#include "FileManager.h"
#include "Recipe.h"
#include "vector"

class RecipeDatabase{
    private:
        FileManager file_manager;
        std::vector<Recipe> recipe_list;
        unsigned int new_id;
    
    public:
        RecipeDatabase();
        void insertRecipe(Recipe recipe);
        void deleteRecipe(Recipe recipe);
        void updateRecipe(Recipe recipe);
        std::vector<Recipe> getRecipes();
        std::vector<Recipe> searchRecipesByIngredients(string ingredients);
        std::vector<Recipe> searchRecipesByRecipeName(string recipename);
}

#endif