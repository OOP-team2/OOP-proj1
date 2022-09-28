//
// Created by HoJoonEum on 2022/09/28.
//

#include "Meal.h"
Meal::Meal() {}

void Meal::addServing(Serving serving, int people) {
    servings.push_back(serving);
}

void Meal::deleteServing(int serving_to_delete) {
    for (auto serving : servings) {
        if (serving == serving_to_delete) {
            servings.erase(serving_to_delete);
        }
    }
}

vector<Serving> Meal::getServings() {
    return servings;
}

void Meal::showServings() {
    return;
}