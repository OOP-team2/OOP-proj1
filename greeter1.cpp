#include "greeter1.h"
#include <memory>

Greeter::Greeter() {
	recipedb = make_unique<RecipeDatabase>();
	planmanager = make_unique <PlanManager>();
	string temp_string;
	int temp_num;
}

void Greeter::showTitle(){
    cout << "Welcome to IIKH! " << endl;
}

void Greeter::showMenu(){
	int input_number;
	while (true) {
		system("clear");
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
				system("clear");
				cout << "-----------" << endl;
				cout << "Recipe Manager" << endl;
				cout << "-----------" << endl;
				cout << "[1] Add Recipe" << endl;
				cout << "[2] Delete Recipe" << endl;
				cout << "[3] Revise Recipe" << endl;
				cout << "[4] Search Recipe" << endl;
				cout << "[5] Show All Recipe" << endl;
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
					system("clear");
					addRecipe();
					cin.ignore();
					continue;
				}
                
				else if (input_num_in_recipe == 2) {
					system("clear");
					deleteRecipe();
					cin.ignore();
					continue;
				}
				else if (input_num_in_recipe == 3) {
					system("clear");
					updateRecipe();
					cin.ignore();
					continue;
				}
				else if (input_num_in_recipe == 4) {
					system("clear");
					searchRecipe();
					cin.ignore();
					continue;
				}
				else if (input_num_in_recipe == 5) {
					system("clear");
					showAllRecipe();
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
				system("clear");
				cout << "---------" << endl;
				cout << "Plan Manager" << endl;
				cout << "---------" << endl;
				cout << "[1] Add Plan" << endl;
				cout << "[2] Delete Plan" << endl;
				//cout << "[3] Revise Plan" << endl;
				cout << "[3] Search Plan" << endl;
				cout << "[4] Show All Plan" << endl;
				cout << "[0] Back To Menu" << endl;
				int input_num_in_plan;
				cin >> input_num_in_plan;
				// clear buffer
				cin.ignore(); 	cin.clear();
				if (input_num_in_plan == 0) {
					break;
				}
				else if (input_num_in_plan == 1) {
					system("clear");
					Plan *new_plan;
					addPlan(new_plan);
					cout << endl << "Complete. Enter any key to go back" << endl;
					cin.ignore(); 	cin.clear();
					if (getchar())continue;
				}
				else if (input_num_in_plan == 2) {
					system("clear");
					deletePlan();
					cout << endl << "Complete. Enter any key to go back" << endl;
					cin.ignore(); 	cin.clear();
					if (getchar())continue;
				}
				else if (input_num_in_plan == 3) {
					system("clear");
					searchPlan();
					cout <<endl<< "Enter any key to go back" << endl;
					cin.ignore(); 	cin.clear();
					if (getchar())continue;
				}
				else if (input_num_in_plan == 4) {
					system("clear");
					showPlan();
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


