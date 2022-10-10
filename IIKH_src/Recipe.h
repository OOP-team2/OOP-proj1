#ifndef Recipe_cpp
#define Recipe_cpp

#include "vector"
#include "iostream"
#include "string"
#include "set"

// Class for a recipe
class Recipe{
    private:
        // variable for a name of a recipe
        std::string recipe_name;
        // variable for a preperation time of a recipe
        std::string prepare_time;
        // variable for ingredients of a recipe
        std::set<std::string> ingredients;
        // variable for cooking order of a recipe
        std::vector<std::string> cooking_order;
    
    public:
        // default constructor for Recipe
        Recipe();
        // constructor with parameters(string,string,set<string>,vector<string>)
        Recipe(std::string new_recipe_name,std::string new_prepare_time,std::set<std::string> new_ingredients, std::vector<std::string> new_cooking_order);
        // a getter for recipe_name
        std::string getRecipeName();
        // a setter for recipe_name
        void setRecipeName(std::string name);
        // a getter for prepare time
        std::string getPrepareTime();
        // a setter for prepare time
        void setPrepareTime(std::string s_time);
        // a getter for ingredients
        std::set<std::string> getIngredients();
        // a setter for setting whole ingredients 
        void setIngredients(std::set<std::string> s_ingredients);
        // a getter for cooking_order
        std::vector<std::string> getCookingOrder();
        // a setter for setting whole cooking_order
        void setCookingOrder(std::vector<std::string> order);
        // function to edit specific ingredient
        void updateIngredient(std::string edit_ingredient);
        // function to remove specifc ingredient
        void deleteIngredient(std::string ingredient);
        // function to add a cooking order
        void addCookingOrder(std::string order);
        // function to delete a cooking order
        void deleteCookingOrder(std::string cooking_order_to_delete);
        // function to return wheter has ingredient
        bool hasIngredient(std::string ingredient);
        // operator == is overloaded to compare
        bool operator==(const Recipe& other_recipe);
        // operator < is overloaded to compare
        bool operator<(const Recipe& other_recipe);
        // function to return stringfied
        std::string toString();
        // function to show name, preparetime
        void showInfo();
};

#endif
