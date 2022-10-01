//
// Created by HoJoonEum on 2022/09/28.
//

#include "Serving.h"

Serving::Serving(int& new_id, std::string serving_name) {
    id = new_id;
    name = serving_name;
    id++;
}

int Serving::getId() {
    return id;
}

std::string Serving::getName() {
    return name;
}

void Serving::setName(std::string new_name) {
    name = new_name;
}

bool Serving::operator== (Serving otherServing) {
    if (name == otherServing.getName()) {
        return true;
    }
    else {
        return false;
    }
}

