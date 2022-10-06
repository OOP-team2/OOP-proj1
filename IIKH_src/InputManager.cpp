#include "InputManager.h"


//recipe DB monitor interface 
void InputManager::monitor(){
    int number;
    bool check = true;
    std::cout<< "<Select the command to run in RecipeDB from the numbers below>"<<std::endl;
    std::cout<<"\n";
    std::cout<<"[1] "<<"Show All Recipes"<<std::endl;
    std::cout<<"[2] "<<"Insert New Recipe"<<std::endl;
    std::cout<<"[3] "<<"Delete Recipe"<<std::endl;
    std::cout<<"[4] "<<"Update Existing Recipe"<<std::endl;
    std::cout<<"[5] "<<"Get Recipe"<<std::endl;
    std::cout<<"[6] "<<"Search Recipe by Ingredient"<<std::endl;
    std::cout<<"[7] "<<"Search Recipe by RecipeName"<<std::endl;
    std::cout<<"[8] "<<"Go to Main"<<std::endl;
    std::cout<<"Select Number: " <<std::endl;
    while(check){
    std::cin>>number;
    switch (number){
        case 1: 

        check = false;
        break;
        case 2:

        check = false;
        break;
        case 3:
        check = false;
        break;
        case 4:

        check = false;
        break;
        case 5:

        check = false;
        break;
        case 6:

        check = false;
        break;
        case 7:

        check = false;
        break;
        case 8:

        check = false;
        break;
        default: 
        std::cout<<"You input wrong information. Try again" <<std::endl;
    }
    }
}

//add recipe information
void InputManager::recipeInput() {
    int weight, time, ID;
    std::string ingredient, name, order;
    //std::vector<std::string> order;
    std::cout << "\n";

    //get recipe_name
    std::cout << "Recipe ID: ";
    std::cin >> ID;

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
    std::cout << "Input Recipe Ingredient : ";
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

void InputManager::planInput(std::vector<std::string> plan_info) {



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
    std::cin >> s_planName;

}
