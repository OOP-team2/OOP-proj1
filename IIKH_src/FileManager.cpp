#include "FileManager.h"

using namespace std;

// initialize file_name with default txt file name
FileManagerForRecipes::FileManagerForRecipes(){
    file_name = "DB_Recipe.txt";
}

// initialize file_name with new file name
FileManagerForRecipes::FileManagerForRecipes(string new_file_name){
    file_name = new_file_name;
}

// read txt file and returns string vector if file exists else create new txt file
vector< vector<string> > FileManagerForRecipes::loadDB(){
    ifstream ifs;
    ofstream ofs;
    ifs.open(file_name);
    vector< vector<string> > data;
    if (ifs.fail())
	{
        ofs.open("DB_Recipe.txt");
        ofs.close();
		cerr << "Error!" << endl;
		return data;
	}

    char buffer[256];
    int i = 0;
	while (ifs.getline(buffer, 256)) {
		data.push_back(Parser::split(string(buffer),'/'));
        i += 1;
	}
    ifs.close();

    return data;
}

// write recipe data txt file with vector of string vector
void FileManagerForRecipes::writeRecipeDB(vector<vector<string>> data){
    string line = "";
    ofstream ofs;
    ofs.open(file_name, ios::out);

    for(int i = 0; i < data.size(); i++){
        for(int j = 0; j < data[i].size(); j++){
            line += data[i][j];
            line += "/";
        }
        line += "\n";
    }

    ofs << line;
    ofs.close();
}

// initialize file_name with default txt file name
FileManagerForPlans::FileManagerForPlans() {
    file_name = "DB_Plans.txt";
}

// initialize file_name with new file name
FileManagerForPlans::FileManagerForPlans(std::string file_name) {
    file_name = file_name;
}

// read txt file and returns string vector if file exists else create new txt file
vector< vector<string> > FileManagerForPlans::loadDB() {
    ifstream ifs;
    ofstream ofs;
    ifs.open(file_name);
    vector< vector<string> > data;
    if (ifs.fail())
    {
        ofs.open("DB_Plans.txt");
        ofs.close();
        cerr << "Error!" << endl;
        return data;
    }

    char buffer[256];
    int i = 0;
    while (ifs.getline(buffer, 256)) {
        data.push_back(Parser::split(string(buffer), '/'));
        i += 1;
    }
    ifs.close();

    return data;
}

// write plan data txt file with vector of string vector
void FileManagerForPlans::writePlans(vector<string> data) {
    string line = "";
    ofstream ofs;
    ofs.open(file_name, ios::out);

    for (auto planData : data) {
        ofs << planData;
        ofs << '\n';
    }

    ofs.close();
}