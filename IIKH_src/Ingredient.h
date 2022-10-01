
#ifndef OOP_PROJ1_INGREDIENT_H
#define OOP_PROJ1_INGREDIENT_H

#include "string"
using namespace std;

class Ingredient {
private:
	string name;
	string weight;
public:
	Ingredient();
	Ingredient(string new_name, string new_weight);
	void setName(string new_name);
	string getName();
	void setWeight(string new_weight);
	string getWeight();
};

#endif //OOP_PROJ1_INGREDIENT_H