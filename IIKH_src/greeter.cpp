#include "greeter.h"
using namespace std;

// constructor for Greeter. initializes recipedb and planmanager
Greeter::Greeter() {
	recipedb = RecipeDatabase::getInstance();
	planmanager = PlanManager();
}

// destructor for Greeter. releases memory for recipedb
Greeter::~Greeter() {
	delete recipedb;
}

// it prints out welcome title of IIKH
void Greeter::showTitle(){
    cout << "Welcome to IIKH! " << endl;
}

// it prints out options of IIKH and keep getting input by user and call functions according to user input
void Greeter::showMenu(){
	int input_number;
	while (true) {
		system("cls");
		showTitle();
		cout << "----" << endl;
		cout << "Menu" << endl;
		cout << "----" << endl;
		cout << "[1] Recipe Manager" << endl;
		cout << "[2] Plan Manager" << endl;
		cout << "[0] Exit" << endl;

		cout << "\nSelect : " << flush;
		int input_number;
		cin >> input_number;

		if (input_number == 0) {
			cout << "Exit Program...." << endl;
			return;
		}
		else if (input_number == 1) {

			while (true) {
				system("cls");
				cout << "-----------" << endl;
				cout << "Recipe Manager" << endl;
				cout << "-----------" << endl;
				cout << "[1] Add Recipe" << endl;
				cout << "[2] Delete Recipe" << endl;
				cout << "[3] Revise Recipe" << endl;
				cout << "[4] Search Recipe by Ingredient" << endl;
				cout << "[5] Search Recipe by Recipe Name" << endl;
				cout << "[6] Show All Recipe" << endl;
				cout << "[0] Back To Menu" << endl;

				cout << "\nSelect : " << flush;
				int input_num_in_recipe;
				cin >> input_num_in_recipe;
				// clear buffer
				cin.ignore(); 	cin.clear();
				if (input_num_in_recipe == 0) {
					break;
				}
				else if (input_num_in_recipe == 1) {
					system("cls");
					recipedb->insertRecipe();
					cin.ignore();
					continue;
				}
                
				else if (input_num_in_recipe == 2) {
					system("cls");
					recipedb->deleteRecipe();
					cin.ignore();
					continue;
				}
				else if (input_num_in_recipe == 3) {
					system("cls");
					recipedb->updateRecipe();
					cin.ignore();
					continue;
				}
				else if (input_num_in_recipe == 4) {
					system("cls");
					recipedb->searchRecipesByIngredient();
					cin.ignore();
					continue;
				}
				else if (input_num_in_recipe == 5){
					system("cls");
					recipedb->searchRecipesByRecipeName();
					cin.ignore();
					continue;
				}
				else if (input_num_in_recipe == 6) {
					system("cls");
					recipedb->showAllRecipes();
					recipedb->showRecipe();
					cin.ignore();
					continue;
				}
				else {
					cout << "-----------------------------------------------" << endl;
					cout << "Error: Invalid Input. Press Any Key to Go Back." << endl;
					cout << "-----------------------------------------------" << endl;

					cin.ignore();
					if (getchar())continue;

				}
			}
			continue;
		}
		else if (input_number == 2) {
			while (true) {
				system("cls");
				cout << "---------" << endl;
				cout << "Plan Manager" << endl;
				cout << "---------" << endl;
				cout << "[1] Add Plan" << endl;
				cout << "[2] Delete Plan" << endl;
				cout << "[3] Show All Plan" << endl;
				cout << "[4] Show Plans By Period" << endl;
				cout << "[5] Search Plans By Meal Type" << endl;
				cout << "[0] Back To Menu" << endl;
				int input_num_in_plan;
				cin >> input_num_in_plan;
				// clear buffer
				cin.ignore(); 	cin.clear();
				if (input_num_in_plan == 0) {
					break;
				}
				else if (input_num_in_plan == 1) {
					system("cls");
					addPlan();
					cout << endl << "Complete. Enter any key to go back" << endl;
					cin.ignore(); 	cin.clear();
					if (getchar())continue;
				}
				else if (input_num_in_plan == 2) {
					system("cls");
					deletePlan();
					cout << endl << "Complete. Enter any key to go back" << endl;
					cin.ignore(); 	cin.clear();
					if (getchar())continue;
				}
				else if (input_num_in_plan == 3) {
					system("cls");
					showAllPlans();
					cout << endl << "Enter any key to go back" << endl;
					cin.ignore(); 	cin.clear();
					if (getchar())continue;
				}
				else if (input_num_in_plan == 4) {
					system("cls");
					showPlansByPeriod();
					cout << endl << "Enter any key to go back" << endl;
					cin.ignore(); 	cin.clear();
					if (getchar())continue;
				}
				else if (input_num_in_plan == 5) {
					system("cls");
					showPlansByMealType();
					cout << endl << "Enter any key to go back" << endl;
					cin.ignore(); 	cin.clear();
					if (getchar())continue;
				}
				else {
					cout << "-----------------------------------------------" << endl;
					cout << "Error: Invalid Input. Press Any Key to Go Back." << endl;
					cout << "-----------------------------------------------" << endl;
					cin.ignore(); 	cin.clear();
					if (getchar())continue;
				}

			}
			continue;
		}
		else {
			cout << "-----------------------------------------------" << endl;
			cout << "Error: Invalid Input. Press Any Key to Go Back." << endl;
			cout << "-----------------------------------------------" << endl;
			cin.ignore(); 	cin.clear();
			if (getchar())continue;
		}

	}
}

// it gets user input and add a new plan
void Greeter::addPlan() {
	Date newDate = Date();
	Meal newMeal = Meal();
	string userInput;
	cout << "You are now adding a Plan" << endl;
	cout << "Let's add a Date!" << endl;
	cout << "Enter a Year: ";
	getline(cin, userInput);
	newDate.setYear(userInput);
	userInput.clear();

	cout << "Enter a Month: ";
	getline(cin, userInput);
	newDate.setMonth(userInput);
	userInput.clear();

	cout << "Enter a Day: ";
	getline(cin, userInput);
	newDate.setDay(userInput);
	userInput.clear();

	cout << "Let's add a Meal!" << endl;
	cout << "Enter a Meal Type(Breakfast or Launch or Dinner)" << endl;
	getline(cin, userInput);
	MealType newMealType;
	newMealType = Meal::stringfiedToMealType(userInput);
	newMeal.setMealType(newMealType);
	userInput.clear();

	cout << "Enter how many people you have" << endl;
	getline(cin, userInput);
	newMeal.setPeople(userInput);
	userInput.clear();

	cout << "Now you are adding Recipes!" << endl;
	vector<string> selectedRecipeIndices;
	vector<Recipe> recipes = RecipeDatabase::getRecipes();
	RecipeDatabase::showAllRecipes();
	cout << "Enter all indices of Recipes you want to add(seperate with comma)" << endl;
	getline(cin, userInput);
	vector<string> indices = Parser::split(userInput, ',');
	for (auto index : indices) {
		newMeal.addRecipe(recipes[stoi(index)-1]);
	}
	userInput.clear();
	Plan newPlan = Plan(newDate, newMeal);
	planmanager.addPlan(newPlan);
	cout << "Your Plan is added!" << endl;
}

// it gets a existing plan and deleate a plan
void Greeter::deletePlan() {
	string indexToDelete;
	planmanager.showInfo();
	cout << "Enter an index of a Recipe you want to delete: ";
	getline(cin, indexToDelete);
	Plan planToDelete = planmanager.getPlanAt(stoi(indexToDelete)-1);
	planmanager.deletePlan(planToDelete);
	cout << "A Plan is deleted" << endl;
}

// it shows all plans
void Greeter::showAllPlans() {
	planmanager.showInfo();
	return;
}

// is shows all plans by meal type
void Greeter::showPlansByMealType() {
	string mealtype;
	cout << "Enter a Meal Type you want to search" << endl;
	getline(cin, mealtype);
	vector<Plan> searchResult = planmanager.searchPlansByMealType(Meal::stringfiedToMealType(mealtype));
	for (auto plan : searchResult) {
		plan.showInfo();
	}
	cout << "all plans matched is shown" << endl;
}

// it shows plans by period. year, month, week, day from now
void Greeter::showPlansByPeriod() {
	string period;
	cout << "Enter a period you want to see: " << endl;
	getline(cin, period);
	vector<Plan> plansByPeriod = planmanager.getPlansByPeriod(period);
	for (auto plan : plansByPeriod) {
		plan.showInfo();
	}
	cout << "all plans in a period you wanted shown up" << endl;
}