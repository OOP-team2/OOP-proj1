
#ifndef OOP_PROJ1_INGREDIENT_H
#define OOP_PROJ1_INGREDIENT_H

#include "string"
using namespace std;

class Ingredient {
private:
	string name;
public:
	Ingredient();
	Ingredient(string new_name);
	void setName(string new_name);
	string getName();
};

#endif //OOP_PROJ1_INGREDIENT_H