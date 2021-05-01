#include "plot.h"

Plot::Plot(graph_info* graph):_info(graph),_translator(_info)
{
    //initialize the plot
    graph->_equation.push(new variable('x'));
    graph->_window_demensions = sf::Vector2f(WORK_PANEL, SCREEN_HEIGHT);
    graph->_origin = sf::Vector2f(graph->_window_demensions.x / 2, graph->_window_demensions.y / 2);
    graph->_domain = sf::Vector2f(-5, 5);
    graph->_range = sf::Vector2f(-6, 6);
    graph->_points = 900;
    graph->increament = (graph->_domain.y - graph->_domain.x ) / (graph->_points);
    graph->_scale = sf::Vector2f(120, 120);
}
void Plot::set_info(graph_info* graph)
{
    _info->_window_demensions = graph->_window_demensions;
    _info->_origin = graph->_origin;
    _info->_domain = graph->_domain;
    _info->_range = graph->_range;
    _info->_points = graph->_points;
    _info->_scale = graph->_scale;
    _info->increament = (_info->_domain.y - _info->_domain.x) / _info->_points;
}

Vector <sf::Vector2f> Plot::operator()()
{
    //given equation will get in shynting yard for postfix
    //then passed into RPN for the corespond y value
    //store the graph corrdinate into a vector
    //converted into sfml coordinate
    //store in graph_coordinate and return it
    set_info(_info);
    shunting_yard sy(_info->_equation);

    Queue <Token*> postfix = sy.postfix();
    RPN _rpn(postfix);

    Vector <sf::Vector2f> _points;
    sf::Vector2f _graph;

    Vector <sf::Vector2f> _graph_coordinate;
    for (float i = _info->_domain.x ; i <= _info->_domain.y; i += _info->increament)
    {
        float y = _rpn(i);
        _points.push_back(sf::Vector2f(i, y));//put the corrdinate into vector
    }
    for (int i = 0;i < _points.size(); i++)
    {
        _graph = _translator(_points[i]);
        _graph_coordinate.push_back(_graph);

    }
    return _graph_coordinate;

}

