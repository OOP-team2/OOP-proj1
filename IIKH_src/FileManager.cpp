#include "FileManager.h"
#include "Parser.h"
#include "iostream"
#include "fstream"

using namespace std;

//생성자
FileManager::FileManager(){
    file_name = "DB_Recipe.txt";
}

FileManager::FileManager(string new_file_name){
    file_name = new_file_name;
}

// 파일을 읽어서 파일의 내용을 2차원 문자열 리스트에 저장하는 함수
vector< vector<string> > FileManager::loadRecipeDB(){
    ifstream ifs;
    ofstream ofs;
    ifs.open(file_name);
    vector< vector<string> > data;
    if (ifs.fail())                                 // 파일이 없으면 에러 출력
	{
        ofs.open("DB_Recipe.txt");
        ofs.close();
		cerr << "Error!" << endl;
		return data;
	}

    char buffer[256];
    int i = 0;
	while (ifs.getline(buffer, 256)) {
		data.push_back(Parser::split(string(buffer),'/'));   // 구분자 : /
        i += 1;
	}
    ifs.close();

    return data;
}

void FileManager::writeRecipeDB(vector<vector<string>> data){
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
    // line.clear();
    ofs.close();
}

FileManagerForPlans::FileManagerForPlans() {
    file_name = "DB_Plans.txt";
}

FileManagerForPlans::FileManagerForPlans(std::string file_name) {
    file_name = file_name;
}

vector< vector<string> > FileManagerForPlans::loadPlans() {
    ifstream ifs;
    ofstream ofs;
    ifs.open(file_name);
    vector< vector<string> > data;
    if (ifs.fail())                                 // 파일이 없으면 에러 출력
    {
        ofs.open("DB_Plans.txt");
        ofs.close();
        cerr << "Error!" << endl;
        return data;
    }

    char buffer[256];
    int i = 0;
    while (ifs.getline(buffer, 256)) {
        data.push_back(Parser::split(string(buffer), '/'));   // 구분자 : /
        i += 1;
    }
    ifs.close();

    return data;
}

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