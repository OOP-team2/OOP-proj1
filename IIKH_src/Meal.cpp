//
// Created by HoJoonEum on 2022/09/28.
//

#include "Meal.h"

Meal::Meal() {};
Meal::Meal(int& new_id) {
    id = id;
    id++;
};

int Meal::getId() {
    return id;
}

int Meal::getPeople() {
    return people;
}
void Meal::setPeople(int new_people) {
    people = new_people;
}

void Meal::addServing(Serving serving) {
    servings.push_back(serving);
}

void Meal::deleteServing(Serving serving_to_delete) {
    // need to implement
    return;
}

std::vector<Serving> Meal::getServings() {
    return servings;
}

void Meal::showServings() {
    return;
}

bool Meal::operator==(Meal otherMeal) {
    if (id == otherMeal.getId()) {
        return true;
    }
    else {
        return false;
    }
}