#ifndef Calculator_H
#define Calculator_H

#include <cmath>
#include <stack>
#include <cctype>
#include <iostream>
using namespace std;
// Calculator implements a basic four function calculator
// valid keys are the digits (0-9), '+', '-', '*', '/', and '='
// optional (extra credit) keys include 'S' to store the current display
// value in memory,
// 'R' to recall the memory to the display,
// and '.' to implement floating point numbers

class Calculator
{
  public:
    Calculator();
    void show_display() const;
    bool press_key(const char key); // returns true if successful
    // invalid conditions include
    // invalid sequence (i.e. "4 + + 4")
    // division by zero

  private:
    double   display;   // the value currently being displayed
    double   memory;    // the value in memory (if implemented)
    bool     last_key_was_op;   // true iff the last key was an operation key

    // use the STL version of a stack
    stack<double>  operandStack;
    stack<char>    operatorStack; // the last operation key pressed (e.g. +,-,*, or /)

    bool     process_digit(const char ch);      // function to process a single digit
    bool     process_operator(const char ch);   // function to process an operation key
    bool     process_memory(const char ch);     // function to do (optional) memory operation(s)
    int      getPrecedence(char operatorChar) const;
};

#endif
