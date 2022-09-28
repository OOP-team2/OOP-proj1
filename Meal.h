//
// Created by HoJoonEum on 2022/09/28.
//

#ifndef OOP_PROJ1_MEAL_H
#define OOP_PROJ1_MEAL_H


class Meal {
private:
    vector<Serving> servings;
public:
    Meal();
    void addServing(Serving serving, int people);
    void deleteServing(Serving serving_to_delete);
    void showServings();
    vector<Serving> getServings();
};


#endif //OOP_PROJ1_MEAL_H
