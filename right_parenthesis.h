#ifndef RIGHT_PARENTHESIS_H
#define RIGHT_PARENTHESIS_H
#include <iostream>
#include "../../Shunting_yard/Shunting_yard/Token.h"

using namespace std;


class Right_Parenthesis:public Token
{
public:
    Right_Parenthesis(string r_par);
    int type_of();
    void print();

private:
    string _r_par;
};

#endif // RIGHT_PARENTHESIS_H
