#ifndef recipe_hpp
#define recipe_hpp

#include<string>
#include<vector>
#include<iostream>
#include "Recipe_DB.hpp"


class Recipe{
    private:
        std::string recipe_name;
        int time;
        std::vector<Ingredient> ingredients;
        std::vector<std::string> cooking_order;
    
    public:
        Recipe();
        Recipe(std::string new_recipe_name,int new_time,std::vector<Ingredient> new_ingredients, std::vector<std::string> new_cooking_order);
    
        //get_information
        std::string getRecipeName();
        int getTime();
        std::vector<Ingredient> getIngredients();
        std::vector<string> getCookingOrder();
            
        //set_recipe(correction)
        void setRecipeName(std::string name);
        void setTime(int time);
        void setIngredients(std::vector<Ingredient> ingredients);
        void setCookingOrder(std::vector<std::string> order);
    
        //function
        void editIngredient(Ingredient add_ingredient);
        void removeIngredient(std::string ingredient);
        void addCookingOrder(std::string order);
        void deleteCookingOrder();
        void printRecipe();
};

#endif
