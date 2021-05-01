#ifndef TEXTBOX_H
#define TEXTBOX_H
#include  <SFML/Graphics.hpp>



class Textbox
{
public:
    Textbox(float length, float width);


private:
    sf::RectangleShape input_box;
    sf::Text function;
};

#endif // TEXTBOX_H
