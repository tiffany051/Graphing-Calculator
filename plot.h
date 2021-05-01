#ifndef PLOT_H
#define PLOT_H


#include "graph_info.h"
#include "../../Shunting_yard/Shunting_yard/shunting_yard.h"
#include "../../!include/Vector_Class/vector.h"
#include "../../!include/Stack_and_Queue/Queue/queue.h"

#include "../../Shunting_yard/Shunting_yard/variable.h"
#include "left_parenthesis.h"
#include "right_parenthesis.h"
#include "../../Shunting_yard/Shunting_yard/Token.h"
#include "../../Final_Project/Final_Project/rpn.h"
#include "../../Final_Project/Final_Project/coordinate_translator.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Plot
{
public:
    Plot(graph_info* graph);
    void set_info(graph_info* graph);

    Vector <sf::Vector2f> operator()();



private:
    graph_info* _info;
    Queue <Token*> _post_fix;
    coordinate_translator _translator;



};

#endif // PLOT_H
