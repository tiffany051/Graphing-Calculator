#ifndef OPERATOR_H
#define OPERATOR_H
#include <cstring>
#include <iostream>
#include "../../Shunting_yard/Shunting_yard/Token.h"

using namespace std;


class Operator: public Token
{
public:
    Operator(string op);
    int type_of();
    void print();
    int prec();
    string get_operator();



private:
    int _op;
    string _operator;
    int _pre;
};

#endif // OPERATOR_H
