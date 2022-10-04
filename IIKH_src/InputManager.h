#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include<iostream>
#include<string>
#include<vector>
class InputManager {

public:

    //send recipe_DB
    void recipeInput();
    void recipeInput(std::vector<std::string> recipe_info);
    void recipeNumInput();
    void recipeNameInput();
    void recipeIngredientInput();

    //send plan_DB
    void planInput();
    void planInput(std::vector<std::string> plan_info);
    void planNumInput();
    void planNameInput();



};

#endif