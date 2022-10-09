#ifndef OOP_PROJ1_SERIALIZEHELPER_H
#define OOP_PROJ1_SERIAKIZEHELPER_H

#include "vector"
#include "string"

class SerializeHelper {
public:
	static std::string serialize(std::vector<std::string> data, char delimeter);
};

#endif