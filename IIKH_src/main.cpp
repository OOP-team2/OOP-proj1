#include "iostream"
#include "greeter.h"
using namespace std;

int main() {
    Greeter greeter = Greeter();
    greeter.showTitle();
    greeter.showMenu();
    return 0;
}