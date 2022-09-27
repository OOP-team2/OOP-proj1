//
// Created by HoJoonEum on 2022/09/27.
//

#ifndef OOP_PROJ1_PLAN_H
#define OOP_PROJ1_PLAN_H


class Plan {
private:
    Meal menu;
    int meal_type;
    Date date;
public:
    Plan();
    Plan(Meal menu, int meal_type, Date date);
    Date getDate();
    Meal getMeal();
    int getMealType();
    void setDate();
    void setMealType(int meal_type);
    void setMeal(Meal meal);
    void showPlan();
};


#endif //OOP_PROJ1_PLAN_H
