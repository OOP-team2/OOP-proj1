#ifndef recipe_hpp
#define recipe_hpp

#include<string>
#include<vector>
#include<iostream>
#include "Ingredient.h"


class Recipe{
    private:
        int ID;
        std::string recipe_name;
        int prepare_time;
        std::vector<Ingredient> ingredients;
        std::vector<std::string> cooking_order;
    
    public:
        Recipe();
        Recipe(int new_ID,std::string new_recipe_name,int new_prepare_time,std::vector<Ingredient> new_ingredients, std::vector<std::string> new_cooking_order);
    
        //get_recipe_information
        int getID();
        std::string getRecipeName();
        int getPrepareTime();
        std::vector<Ingredient> getIngredients();
        std::vector<std::string> getCookingOrder();
            
        //set_recipe_information
        void setRecipeName(std::string name);
        void setPrepareTime(int s_time);
        void setIngredients(std::vector<Ingredient> s_ingredients);
        void setCookingOrder(std::vector<std::string> order);
    
        //function
        void editIngredient(Ingredient edit_ingredient);
        void removeIngredient(std::string ingredient);
        void addCookingOrder(std::string order);
        void deleteCookingOrder();
        void printRecipe();
};

#endif
