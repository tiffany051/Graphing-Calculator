#ifndef VARIABLE_H
#define VARIABLE_H
#include "../../Shunting_yard/Shunting_yard/Token.h"

using namespace std;

class variable: public Token
{
public:
    variable(char var);
    int type_of();
    void print();

private:
    char _var;
};

#endif // VARIABLE_H
