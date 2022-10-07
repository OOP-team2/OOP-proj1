#include "sstream"
#include "Parser.h"

using namespace std;

// line을 받아 구분자를 기준으로 구분하여 vector로 반환하는 메소드
vector<string> Parser::split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;
 
    vector<string> result;

    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }
 
    return result;
}