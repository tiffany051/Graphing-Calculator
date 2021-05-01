#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>

using namespace std;


const int OPERATOR = 3;
const int NUMBER = 1;
const int VARIABLE = 6;
const int FUNCTION = 2;
const int R_PAR = 4;
const int L_PAR = 5;

class Token
{
public:
    Token();
    virtual ~Token();
    virtual int type_of();
    virtual void print();
};

#endif // TOKEN_H
