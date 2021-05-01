#ifndef LEFT_PARENTHESIS_H
#define LEFT_PARENTHESIS_H

#include <iostream>
#include "../../Shunting_yard/Shunting_yard/Token.h"

using namespace std;

class Left_parenthesis:public Token
{
public:
    Left_parenthesis(string l_par);
    int type_of();
    void print();

private:
    string _l_par;
};

#endif // LEFT_PARENTHESIS_H
