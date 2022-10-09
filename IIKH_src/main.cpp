#include "iostream"
#include "greeter.h"
using namespace std;

// main function. entry point of this program
int main() {
    Greeter g = Greeter();
    g.showMenu();

    return 0;
}