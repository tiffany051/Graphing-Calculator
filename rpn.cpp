#include "rpn.h"

RPN::RPN(Queue <Token*> postfix):_post_fix(postfix)
{

}

float RPN::operator()(float x)
{
    Queue <Token*> _before = _post_fix;
    Stack_class <float> result;

    while(!_before.empty())
    {
        Token* begin = _before.pop();

        if(begin->type_of() == VARIABLE)
        {
            result.push(x);
        }
        else if(begin->type_of() == NUMBER)
        {
           Number* num = static_cast<Number*>(begin);
           result.push(num->get_num());
        }
        else if (begin->type_of() == OPERATOR)
        {
            Operator* _op = static_cast <Operator*>(begin);
            string op = _op->get_operator();
            float num1 = result.pop();

            if(op == "+" || op == "-" || op == "*" || op == "/" || op == "^")
            {
               float num2 = result.pop();
               if(op == "+")
               {
                   result.push(num2 + num1);
               }
               else if (op == "-")
               {
                    result.push(num2 - num1);
               }
               else if (op == "*")
               {
                   result.push(num2 * num1);
               }
               else if (op == "/")
               {
                    result.push(num2 / num1);
               }
               else if (op == "^")
               {
                    result.push(pow(num2, num1));
               }

            }

        }
        else if(begin->type_of() == FUNCTION)
        {
            Function* _func = static_cast <Function*>(begin);
            string func = _func->get_function();
            float num1 = result.pop();
            if(func == "sin")
            {
                result.push(sin(num1));
            }
            else if (func == "cos")
            {
                result.push(cos(num1));
            }
            else if (func == "tan")
            {
                result.push(tan(num1));
            }
            else if (func == "ln")
            {
                result.push(log(num1));
            }
            else if (func == "csc")
            {
                result.push(1 / sin(num1));
            }
            else if (func == "sec")
            {
                result.push(1 / cos(num1));
            }
            else if (func == "cot")
            {
                result.push(1 / tan(num1));
            }
            else
            {
                cout << "Graph Error draw y = x" << endl;
            }
        }
    }
    return result.pop();
}
