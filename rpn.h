#ifndef RPN_H
#define RPN_H

#include "../../Final_Project/Final_Project/shunting_yard.h"
#include "../../Final_Project/Final_Project/Token.h"
#include "../../!include/Stack_and_Queue/Queue/queue.h"
#include "../../!include/Stack_and_Queue/Stack/stack_class.h"
#include "../../Final_Project/Final_Project/number.h"
#include "../../Final_Project/Final_Project/operator.h"
#include "../../Final_Project/Final_Project/function.h"
#include <iostream>
#include <math.h>

using namespace std;

class RPN
{
public:
    RPN(Queue <Token*> postfix);
    float operator()(float x);

private:
    Queue <Token*> _post_fix;

};

#endif // RPN_H
