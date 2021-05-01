#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#include "../../!include/Stack_and_Queue/Queue/queue.h"
#include "../../!include/Stack_and_Queue/Stack/stack_class.h"
#include "../../Shunting_yard/Shunting_yard/Token.h"
#include "../../Final_Project/Final_Project/operator.h"
#include "../../Shunting_yard/Shunting_yard/variable.h"
#include "../../Shunting_yard/Shunting_yard/number.h"
#include <iostream>

using namespace std;


class shunting_yard
{
public:
    friend class Queue <Token*>;
    shunting_yard(Queue <Token*> infix);
    Queue <Token*> postfix();

    void print() const;
    friend ostream& operator <<(ostream& outs, const shunting_yard& sy);

private:

    Queue <Token*> _postfix;
    Queue <Token*> _infix;



};

#endif // SHUNTING_YARD_H
