#include "function.h"

Function::Function(string function):_function(function)
{

}

int Function::type_of()
{
    return FUNCTION;

}

string Function::get_function()
{
    return _function;
}
void Function::print()
{
    cout << _function << " ";
}
