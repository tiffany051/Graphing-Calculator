#include "coordinate_translator.h"

coordinate_translator::coordinate_translator(graph_info* info):_info(info)
{
    //blank
}

sf::Vector2f coordinate_translator::translate(sf::Vector2f points)
{//translate the graph points to sfml window coordinate
    sf:: Vector2f coordinate = points;
    coordinate.x = (coordinate.x * _info->_scale.x) + _info->_origin.x ;
    coordinate.y = (-coordinate.y * _info->_scale.y) + _info->_origin.y;
    return sf::Vector2f(coordinate.x, coordinate.y);
}

sf::Vector2f  coordinate_translator::operator ()(sf::Vector2f points)
{
    return translate(points);
}
