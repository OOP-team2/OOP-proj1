//
// Created by HoJoonEum on 2022/09/28.
//

#ifndef OOP_PROJ1_SERVING_H
#define OOP_PROJ1_SERVING_H

#include "string"

class Serving {
private:
    std::string name;
    int id;
public:
    Serving(int& new_id, std::string serving_name);
    int getId();
    std::string getName();
    void setName(std::string new_name);
    bool operator==(Serving otherServing);
};


#endif //OOP_PROJ1_SERVING_H
