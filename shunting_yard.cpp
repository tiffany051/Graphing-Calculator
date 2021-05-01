#include "shunting_yard.h"

shunting_yard::shunting_yard(Queue <Token*> infix):_infix(infix)
{


}

Queue <Token*> shunting_yard::postfix()
{
    Stack_class <Token*> _operator;//the stack that store operator
    Queue <Token*> _postfix;

//    cout << "_postfix " << _infix << endl;
    int prec = 0;

    while(_infix.empty() == false)
    {
        Token* i = _infix.pop();
        if(i->type_of() == NUMBER || i->type_of() == VARIABLE)
        {//if it is number than push into the postfix queue
            _postfix.push(i);
        }

        else if(i->type_of() == FUNCTION)
        {//if is a function push into the operator stack
            _operator.push(i);
        }

        else if(i->type_of() == OPERATOR)
        {//when its an operator
         //1. if the operator stack is empty, push the operator
         // 2. if the operator stack is not empty
               //1. get the precedence of current operator
               //2. compare with the operator on top of the stack
               //3. if the current operator has larger precedence, push on that stack
               //4. else if the current operator has smaller or equal precedence of the top stack
                      //pop the stack until it reach the less precedence
                      //and push those operators in the stack to queue
            Token* _op_ptr;
            if(_operator.empty())
            {
                _operator.push(i);
            }
            else
            {//when is not empty stack
                _op_ptr = _operator.top();
                prec = static_cast<Operator*>(i)->prec();
                int stack_pre = static_cast<Operator*>(_op_ptr)->prec();

                if(prec > stack_pre || _op_ptr->type_of() == L_PAR)
                {
                    _operator.push(i);
                }
                else
                {//when the current precedence is smaller of euqal to the top of stack
                    while (prec <= stack_pre && !_operator.empty())
                    {
                        _postfix.push(_operator.pop());
                    }
                    _operator.push(i);
                }
            }
        }

        else if(i->type_of() == L_PAR)
        {
            _operator.push(i);
        }
        else if(i->type_of() == R_PAR)
        {
            Token* _op_ptr = _operator.top();
            while(_op_ptr->type_of() != L_PAR)
            {//pop till you see the left parenthesis
                _postfix.push(_operator.pop());
                _op_ptr = _operator.top();
            }
            _postfix.push(_operator.pop());
        }
    }


    while(!_operator.empty())
    {//when the infix is empty but the operator stack is not
        Token* p = _operator.pop();
        _postfix.push(p);
    }

    return _postfix;
}

void shunting_yard::print() const
{
    for (Queue <Token*>::Iterator it = _postfix.front(); it != nullptr; it++)
    {
        (*it)->print();
    }

}




