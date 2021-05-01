#include "graph.h"


graph::graph(graph_info* graph):_info(graph), _point(_info->_points), _plotter(_info)
{
    //blank
}

void graph::set_info()
{
    _plotter.set_info(_info);

}
void graph::update()
{
    _points = _plotter();
}
void graph::draw(sf::RenderWindow& window)
{

    _plotter.set_info(_info);

    //set x-axis
    x_axis.setSize(sf::Vector2f(2, _info->_window_demensions.y));
    x_axis.setPosition(_info->_origin.x, 0);
    x_axis.setFillColor(sf::Color::White);
    window.draw(x_axis);

    //set y_axis
    y_axis.setSize(sf::Vector2f(_info->_window_demensions.y, 2));
    y_axis.setPosition(0, _info->_origin.y);
    y_axis.setFillColor(sf::Color::White);
    window.draw(y_axis);

    sf::CircleShape _point(4);

    for (int i = 0; i < _points.size(); i++)
    {
        _point.setPosition(_points[i]);
        _point.setFillColor(sf::Color::Blue);
        window.draw(_point);
    }
}


