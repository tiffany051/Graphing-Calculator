#ifndef GRAPH_INFO_H
#define GRAPH_INFO_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "constant.h"
#include "../../!include/Stack_and_Queue/Queue/queue.h"
#include "Token.h"

using namespace std;

struct graph_info
{
    Queue<Token*> _equation;
    sf::Vector2f _window_demensions;
    sf::Vector2f _origin;
    //grapn's (0,0) in screen coordinates
    sf::Vector2f _scale;
    sf::Vector2f _domain;
    sf::Vector2f _range;
    int x_min;
    int x_max;
    int y_min;
    int y_max;
    float increament;
    int _points;//number of points

};


#endif // GRAPH_INFO_H
