#ifndef OOP_PROJ1_RECIPEDATABASE_H
#define OOP_PROJ1_RECIPEDATABASE_H

#include "FileManager.h"
#include "Recipe.h"
#include <vector>

/*
    RecipeDatabase manages recipes which includes Create, Read, Update and Delete function
    And it also supports search recipes by name and ingredient
*/
class RecipeDatabase{
    private:
        FileManager file_manager;                                                   // Object to load and write recipe data from stored file
        std::vector< std::vector<std::string> > data;                               // raw data of recipes
        std::vector<Recipe> recipe_list;                                            // Database of recipes at runtime
        bool isSameName(Recipe existingRecipe, std::string recipename);             // Compare recipe name to find recipes with samename
        bool hasIngredient(Recipe existingRecipe, std::string ingredient);          // Check if the recipe has the ingredient
        bool isEqual(Recipe r1, Recipe r2);                                         // Compare two recipes to see if they are the same
        Recipe recipeInputUI();                                                     // Console UI for add recipe
    
    public:
        RecipeDatabase();                                                           // Constructor of recipeDB
        void showAllRecipes();                                                      // Print list of recipes
        void insertRecipe(Recipe recipe);                                           // Add recipe to database
        void deleteRecipe(Recipe recipe);                                           // Delete recipe from database
        void updateRecipe(Recipe recipe);                                           // Update selected recipe
        std::vector<Recipe> getRecipes();                                           // Get recipeDB
        std::vector<Recipe> searchRecipesByIngredient(std::string ingredients);     // Search recipe in database by recipe name
        std::vector<Recipe> searchRecipesByRecipeName(std::string recipename);      // Search recipe in database by ingredient 
};

#endif