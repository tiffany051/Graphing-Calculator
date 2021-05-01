#include "number.h"

Number::Number(int number):_num(number)
{

}
int Number::type_of()
{
    return NUMBER;
}
int Number::get_num()
{
    return _num;
}
void Number::print()
{
    cout << _num << " ";
}
