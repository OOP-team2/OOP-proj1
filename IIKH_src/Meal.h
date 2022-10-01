//
// Created by HoJoonEum on 2022/09/28.
//

#ifndef OOP_PROJ1_MEAL_H
#define OOP_PROJ1_MEAL_H

#include <vector>
#include "Serving.h"

enum MealType { breakfast, launch, dinner };

class Meal {
private:
    std::vector<Serving> servings;
    int people = 0;
    int id;
public:
    Meal();
    Meal(int& new_id);
    int getId();
    void addServing(Serving serving);
    void setPeople(int new_people);
    int getPeople();
    void deleteServing(Serving serving_to_delete);
    void showServings();
    std::vector<Serving> getServings();
    bool operator== (Meal otherMeal);
};


#endif //OOP_PROJ1_MEAL_H
