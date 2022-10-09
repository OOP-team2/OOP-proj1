#ifndef OOP_PROJ1_PARSER_H
#define OOP_PROJ1_PARSER_H

#include "string"
#include "vector"

// Class for parsing string value seperated by a delimeter
class Parser{
    public:
        static std::vector<std::string> split(std::string str, char Delimiter);
};

#endif