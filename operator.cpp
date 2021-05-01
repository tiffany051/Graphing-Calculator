#include "operator.h"


Operator::Operator(string op):_operator(op)
{
    if(op == "^")
    {
        _pre = 4;
    }
    else if (op == "/" || op == "*")
    {
        _pre = 3;
    }
    else
    {
        _pre = 2;
    }
}

int Operator::type_of()
{
    return OPERATOR;
}

string Operator::get_operator()
{
     return _operator;
}

void Operator::print()
{

    cout << _operator << " ";
}
int Operator::prec()
{
    return _pre;
}

