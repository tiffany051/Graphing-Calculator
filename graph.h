#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
#include "graph_info.h"
#include "../../!include/Vector_Class/vector.h"
#include "plot.h"



class graph
{
public:
    graph(graph_info* graph);
    void set_info();
    void update();
    void draw(sf::RenderWindow& window);

private:
    Vector <sf::Vector2f> _points;
    graph_info* _info;
    Plot _plotter;
    int _point;

    sf::RectangleShape x_axis;
    sf::RectangleShape y_axis;


};

#endif // GRAPH_H
