#include "SerializeHelper.h"
std::string SerializeHelper::serialize(std::vector<std::string> data, char delimeter) {
	std::string serialized = "";
	for (auto datum : data) {
		serialized += datum;
		serialized += delimeter;
	}
	return serialized;
}