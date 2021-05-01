#ifndef NUMBER_H
#define NUMBER_H
#include <iostream>
#include "../../Shunting_yard/Shunting_yard/Token.h"

using namespace std;


class Number : public Token
{
public:
    Number(int number);
    int type_of() override;
    void print() override;
    int get_num();

private:
    int _num;
};

#endif // NUMBER_H
