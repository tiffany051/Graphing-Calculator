#ifndef FUNCTION_H
#define FUNCTION_H

#include <cstring>
#include <iostream>
#include "../../Shunting_yard/Shunting_yard/Token.h"
#include "../../Final_Project/Final_Project/operator.h"


class Function: public Token
{
public:
    Function(string function);
    int type_of();
    void print();
    string get_function();

private:
    string _function;
};

#endif // FUNCTION_H
