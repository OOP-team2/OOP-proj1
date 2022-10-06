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
        RecipeDatabase* recipeDB = NULL;                                            // instance of recipeDB itself
        Recipe recipeInputUI();                                                     // Console UI for add recipe
        Recipe recipeInputUI(Recipe recipe);                                        // Console UI for update recipe
        int recipeNumInputUI();                                                     // Console select recipe UI for update and delete recipe
        std::string recipeNameInputUI();                                            // Console name input UI for search by name
        std::string recipeIngredientInputUI();                                      // Console ingredient input UI for search by ingredient
        void updatedata();                                                          // Update data field to write data to file
    
    public:
        RecipeDatabase();                                                           // Constructor of recipeDB
        RecipeDatabase* getInstance();                                              // Get instance of recipeDB
        void showAllRecipes();                                                      // Print list of recipes
        void insertRecipe();                                                        // Add recipe to database
        void deleteRecipe();                                                        // Delete recipe from database
        void updateRecipe();                                                        // Update selected recipe
        std::vector<Recipe> getRecipes();                                           // Get recipeDB
        std::vector<Recipe> searchRecipesByIngredient();                            // Search recipe in database by recipe name
        std::vector<Recipe> searchRecipesByRecipeName();                            // Search recipe in database by ingredient 
};

#endif