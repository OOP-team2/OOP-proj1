//FileManager
#include "FileManager.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//생성자
FileManager::FileManager(){
    this->file_name = "test.txt";
}

// line을 받아 구분자를 기준으로 구분하여 vector로 반환하는 메소드
vector<string> FileManager::split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;
 
    vector<string> result;

    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }
 
    return result;
}

// 파일을 읽어서 파일의 내용을 2차원 문자열 리스트에 저장하는 함수
vector< vector<string> > FileManager::load(){
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
        
		data.push_back(split(string(buffer),'/'));   // 구분자 : /
        i += 1;
	}
    ifs.close();
    return data;
}

// 미구현
// recipe객체를 받을건지 아니면 파일에 쓰려는 내용만 받을건지?
void FileManager::write(std::string recipe){
    std::ofstream ofs;
    ofs.open(this->file_name);
    ofs.close();
}