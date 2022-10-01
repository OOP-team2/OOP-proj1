#include "recipe.hpp"

Recipe::Recipe(std::string new_recipe_name,int new_time,std::vector<Ingredient> new_ingredients, std::vector<std::string> new_cooking_order){
    recipe_name = new_recipe_name;
    time = new_time;
    ingredients = new_ingredients;
    cooking_order = new_cooking_order;
}

//getdata
std::string Recipe::getRecipeName(){
    return recipe_name;
}
int Recipe::getTime(){
    return time;
}
std::vector<Ingredient> Recipe::getIngredients(){
    return ingredients;
}
std::vector<std::string> Recipe::getCookingOrder(){
    return cooking_order;
}

//set_recipe(correction)
//this -> 
void Recipe::setRecipeName(std::string name) {
    recipe_name = name;
}
void Recipe::setTime(int time) {
    time = time;
}
void Recipe::setIngredients(std::vector<Ingredient> ingredients) {
    ingredients = ingredients;
}
void Recipe::setCookingOrder(std::vector<std::string> order){
    cooking_order.clear();
    cooking_order.push_back(order);
}


//function
void Recipe::editIngredient(Ingredient edit_ingredient){
    for (int i=0; i<ingredients.size(); i++) {
        if(ingredients[i].getName()==edit_ingredient.getName()) {
            if(ingredients[i].getWeight() + edit_ingredient.getWeight()>0){
                ingredients[i].setWeight(ingredients[i].getWeight() + edit_ingredient.getWeight());
                return;
            }
            else{
                ingredients.erase(ingredients.begin() + i);
                return;
            }
        }
    }
    ingredients.push_back(edit_ingredient);
}

void Recipe::removeIngredient(std::string ingredient){
    for (int i = 0; i < ingredients.size(); i++) {
        if (ingredients[i].getName() == ingredient) {
            ingredients.erase(ingredients.begin() + i);
            std::cout<<ingredient<<" has been removed."<<std::endl;
            
        }
    }
    std::cout<<"There are no "<<ingredient<<"on the list."<<std::endl;
 
}

void Recipe::addCookingOrder(std::string order){
    cooking_order.push_back(order);
}
void Recipe::deleteCookingOrder(){
    cooking_order.clear();
}

//수정 요망
void Recipe::printRecipe(){
    std::cout << " Recipe Name: " << getRecipeName() << std::endl;
    std::cout << " Cooking Time: " << getTime() << std::endl;

    if (getIngredients().size())
    {
        std::cout << std::endl;
        std::cout << " [Ingredients List]" << std::endl;
        for (int i = 0; i < getIngredients().size(); i++)
        {
            std::cout << " " << i + 1 << ". " << getIngredients()[i].getName() << "    "
                << getIngredients()[i].getWeight() << std::endl;
        }
    }

    if (getCookingOrder().size())
    {
        std::cout << std::endl;
        std::cout << " <Cooking Order> " << std::endl;
        for (int i = 0; i < getCookingOrder().size(); i++)
        {
            std::cout << " " << i + 1 << ". " << getCookingOrder()[i] << std::endl;
        }

    }
    
    std::cout<<"\n\n\n";
}
