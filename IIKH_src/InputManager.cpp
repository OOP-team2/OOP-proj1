#include "InputManager.h"


//add recipe information
void InputManager::recipeInput() {
    int weight, time;
    std::string ingredient, name, order;
    //std::vector<std::string> order;
    std::cout << "\n";

    //get recipe_name
    std::cout << "Recipe Name: ";
    std::cin >> name;

    std::cout << "\n";
    //get ingredient_Information
    std::cout << "(If you want to stop add_ingredient, please enter \"stop\")";
    while (ingredient != "stop") {
        int i = 1;
        std::cout << "[" << i++ << "]" << " Ingredient: ";
        std::cin >> ingredient;
        std::cout << "[" << i++ << "]" << " Weight: ";
        std::cin >> weight;
        std::cout << "\n";
    }

    //get preparation_time
    std::cout << "\n";
    std::cout << "Prepare Time(minutes): ";
    std::cin >> time;

    //get cooking order
    std::cout << "\n";
    std::cout << "(If you want to stop add_ingredient, please enter \"stop\")";
    while (order != "stop") {
        int i = 1;
        std::cout << "[" << i++ << "]" << " Order: ";
        std::cin >> order;
    }
}

//
void InputManager::recipeInput(std::vector<std::string> recipe_info) {
    //??
}

//delete or update recipeNumber
void InputManager::recipeNumInput() {
    std::cout << "\n";
    int number;
    std::cout << "Input Recipe Number: ";
    std::cin >> number;

}
//search for recipe using recipe_name
void InputManager::recipeNameInput() {
    std::cout << "\n";
    std::string s_recipeName;
    std::cout << "Input Recipe Name: ";
    std::cin >> s_recipeName;
}

//search for recipe using recipe_Ingredient
void InputManager::recipeIngredientInput() {
    std::cout << "\n";
    std::string s_Ingredient;
    std::cout << "Input Recipe Ingredient: ";
    std::cin >> s_Ingredient;
}







//add plan information
void InputManager::planInput() {
    int year, month, day, serving;
    std::string plan, meal, menu;
    std::cout << "\n";

    //get plan_name
    std::cout << "Plan Name: ";
    std::cin >> plan;
    std::cout << "\n";

    //get Year
    std::cout << "Year: ";
    std::cin >> year;
    std::cout << "\n";
    //get Month
    std::cout << "Month: ";
    std::cin >> month;
    std::cout << "\n";
    //get Day
    std::cout << "Day: ";
    std::cin >> day;
    std::cout << "\n";

    //get meal
    std::cout << "Meal: ";
    std::cin >> meal;
    std::cout << "\n";

    //get menu
    std::cout << "Menu: ";
    std::cin >> menu;
    std::cout << "\n";

    //get seving
    std::cout << "How many servings will you have?: ";
    std::cin >> serving;
    std::cout << "\n";



}

void InputManager::planInput(vector<string> plan_info) {



}

void InputManager::planNumInput() {
    std::cout << "\n";
    int number;
    std::cout << "Input Plan Number: ";
    std::cin >> number;


}

void InputManager::planNameInput() {
    std::cout << "\n";
    std::string s_planName;
    std::cout << "Input plan Name: ";
    std::cin >> s_recipeName;

}
