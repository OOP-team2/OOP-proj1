#include "Parser.h"
#include "sstream"

using namespace std;

// recives a string value and a delimeter then returns vector of string without delimeter
vector<string> Parser::split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;
 
    vector<string> result;

        while (getline(iss, buffer, Delimiter)) {
            result.push_back(buffer);
        }
 
    return result;
}