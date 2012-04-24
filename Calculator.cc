#include "Calculator.h"

Calculator::Calculator()
{
    display = 0.0;
    last_key_was_op  = false;
}

void Calculator::show_display() const
{
    std::cout << display;
}

bool Calculator::press_key(const char key)
{
    if (isdigit(key)) {
        return process_digit(key);
    }

    switch (key)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return process_operator(key);
            break;
        case '(':
            operandStack.push(key);
            break;
        case ')':
            operandStack.push(key);
            break;
        case '=':
            return process_operator(key);
            break;
        case 's':
        case 'S':
        case 'r':
        case 'R':
            return process_memory(key);
    }
}

bool Calculator::process_digit(const char key)
{
    if (last_key_was_op) {
        display = 0.0;
        last_key_was_op = false;
    }

    display *= 10.0;
    display += (float) (key - '0');

    operandStack.push((float) (key - '0'));

    return true;
}

double Calculator::process_numbers() {
    double temp = 0;
    int multiple = 1;

    if (operandStack.top() == ')') {
        operandStack.pop();
        while (operandStack.top() != '(') {
            temp += operandStack.top() * multiple;
            operandStack.pop();
            multiple *= 10;
        }
    } else {
        temp = operandStack.top();
    }

    return temp;
}

bool Calculator::process_operator(const char key)
{
    int stackTopPrecedence;
    double leftHandOperand, rightHandOperand, result;
    char operation;

    operatorStack.push(key);

    std::cout << std::endl;
    std::cout << "Not empty? " << !operatorStack.empty() << std::endl;
    std::cout << "operatorStack.top() " << operatorStack.top() << std::endl;
    std::cout << "getPrecedence(key) " << getPrecedence(key) << std::endl;

    while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(key))
    {
        // This code does not do any error handling
        rightHandOperand = process_numbers();
        operandStack.pop();

        leftHandOperand  = process_numbers();
        operandStack.pop();

        operation = operatorStack.top();
        operatorStack.pop();

        switch (operation) {
            case '+':
                result = leftHandOperand + rightHandOperand;
                break;

            case '-':
                result = leftHandOperand - rightHandOperand;
                break;

            case '*':
                result = leftHandOperand * rightHandOperand;
                break;

            case '/':
                if (rightHandOperand == 0) {
                    std::cerr << "\nError! Divison by Zero not allowed." << std::endl;
                } else {
                    result = leftHandOperand / rightHandOperand;
                }
                break;

            case '^':
                result = std::pow(leftHandOperand, rightHandOperand);
                break;

            case '=':
                display = operandStack.top();
                break;

            default:
                std::cerr << "\nInvalid operation found (" << key << ")" << endl;
        }
    }

    std::cout << leftHandOperand << " " << operation << " " << rightHandOperand << std::endl;
    operandStack.push(result);
    display = result;
    last_key_was_op = true;

    return true;
}

int Calculator::getPrecedence(char operatorChar) const
{
    return 0;
}

bool Calculator::process_memory(const char key)
{
    switch (key) {
    case 'S':
    case 's':
        std::cout << "need to fix this" << std::endl;

    }

    last_key_was_op = true;

    return true;
}
