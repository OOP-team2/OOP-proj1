#ifndef OOP_PROJ1_RECIPEDATABASE_H
#define OOP_PROJ1_RECIPEDATABASE_H

#include "FileManager.h"
#include "Recipe.h"
#include "Parser.h"
#include "vector"
#include "string"

/*
    RecipeDatabase manages recipes which includes Create, Read, Update and Delete function
    And it also supports search recipes by name and ingredient
*/
class RecipeDatabase{
    private:
        static FileManagerForRecipes file_manager;                                                   // Object to load and write recipe data from stored file
        static std::vector< std::vector<std::string> > data;                               // raw data of recipes
        static std::vector<Recipe> recipe_list;                                            // Database of recipes at runtime

        static Recipe recipeInputUI();                                                     // Console UI for add recipe
        static Recipe recipeInputUI(Recipe recipe);                                        // Console UI for update recipe
        static int recipeNumInputUI();                                                     // Console select recipe UI for update and delete recipe
        static std::string recipeNameInputUI();                                            // Console name input UI for search by name
        static std::string recipeIngredientInputUI();                                      // Console ingredient input UI for search by ingredient
        static void updatedata();                                                          // Update data field to write data to file

    public:
        static RecipeDatabase* recipe_db;                                                  // instance of recipeDB itself
        
        RecipeDatabase();                                                                  // Constructor of recipeDB
        static RecipeDatabase* getInstance();                                              // Get instance of recipeDB
        static void showAllRecipes();                                                      // Print list of recipes
        static void showRecipe();                                                          // Print a recipe
        static void insertRecipe();                                                        // Add recipe to database
        static void deleteRecipe();                                                        // Delete recipe from database
        static void updateRecipe();                                                        // Update selected recipe
        static std::vector<Recipe> getRecipes();                                           // Get recipeDB
        static std::vector<Recipe> searchRecipesByIngredient();                            // Search recipe in database by recipe name
        static std::vector<Recipe> searchRecipesByRecipeName();                            // Search recipe in database by ingredient 
};

#endif