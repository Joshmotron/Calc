#include "Calculator.h"

int main ()
{
    char inChar;
    Calculator calc;

    std::cin >> inChar;
    while (inChar != ';') {
        std::cout << "\nOriginal display: ";
        calc.show_display();
        std::cout << "\tnew key: " << inChar;
        calc.press_key(inChar);
        std::cout << "\tnew display: ";
        calc.show_display();
        std::cout << "\n" << std::endl;
        std::cin >> inChar;
    }

    return 0;
}
