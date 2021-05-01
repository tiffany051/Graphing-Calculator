#include "textbox.h"

Textbox::Textbox(float length, float width)
{
    input_box.setPosition(length, width);
    input_box.setSize(sf::Vector2f(7, 100));
    input_box.setFillColor(sf::Color::Green);
}
