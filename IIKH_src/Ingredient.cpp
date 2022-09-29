

#include <iostream>
#include "Ingredient.h"

Ingredient::Ingredient() {
	name = "";
	weight = "";
}
Ingredient::Ingredient(std::string new_name, std::string new_weight) {
	name = new_name;
	weight = new_weight;
}

std::string Ingredient::getName() {
	return name;
}

void Ingredient::setName(std::string new_name) {
	name = new_name;
}

std::string Ingredient::getWeight() {
	return weight;
}

void Ingredient::setWeight(std::string new_weight) {
	weight = new_weight;
}