//FileManager
#include "FileManager.h"
#include "Parser.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//생성자
FileManager::FileManager(){
    this->file_name = "DB_Recipe.txt";
}

FileManager::FileManager(string file_name){
    this->file_name = file_name;
}

// 파일을 읽어서 파일의 내용을 2차원 문자열 리스트에 저장하는 함수
vector< vector<string> > FileManager::loadRecipeDB(){
    ifstream ifs;
    ifs.open(this->file_name);
    vector< vector<string> > data;
    if (ifs.fail())                                 // 파일이 없으면 에러 출력
	{
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

void FileManager::writeRecipeDB(std::vector<std::vector<std::string>> data){
    std::string line = "";
    std::ofstream ofs;
    ofs.open(this->file_name, std::ios::trunc);

    for(int i = 0; i < data.size(); i++){
        for(int j = 0; j < data[i].size(); j++){
            line += data[i][j];
            line += "/";
        }
        ofs << line;
        line = "";
    }

    ofs.close();
}