#include "variable.h"

variable::variable(char var): _var(var)
{

}
int variable::type_of()
{
    return VARIABLE;
}

void variable::print()
{

    cout << _var << " ";
}
