//
// Created by HoJoonEum on 2022/09/28.
//
#include "string"
#include "Serving.h"

Serving::Serving(std::string serving_name) {
    name = serving_name;
}

std::string Serving::getName() {
    return name;
}

void Serving::setName(std::string new_name) {
    name = new_name;
}

