

#include <iostream>
#include "Ingredient.h"

Ingredient::Ingredient() {
	name = "";
}
Ingredient::Ingredient(std::string new_name) {
	name = new_name;
}

std::string Ingredient::getName() {
	return name;
}

void Ingredient::setName(std::string new_name) {
	name = new_name;
}