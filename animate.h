#ifndef ANIMATE_H
#define ANIMATE_H


#include <SFML/Graphics.hpp>
#include "system.h"
#include "sidebar.h"
#include "graph_info.h"
#include "graph.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class animate{
public:
    animate();
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();
    void set_info();
    Queue <Token*> get_input();

private:
    graph_info* _info;
    sf::RenderWindow window;
    sf::CircleShape mousePoint;         //The little red dot
    System system;                      //container for all the animated objects
    int command;                        //command to send to system
    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;               //text to draw on main screen
    sf::Text input_text;                //show the equation
    bool mouseIn;                       //mouse is in the screen
    Sidebar sidebar;
    sf::RectangleShape input_box;       //box for input
    string input;                       //string for input
    bool is_input;                      //use on creating box
    bool inputing;                      //use to draw f(x)
    vector <string> _functions;         //vector string type to store the functions in the file
    ofstream outStream;                 //ostream to write in the funtion.txt
    ifstream inStream;                  //ifstream to read the function.txt
    string _function;                   //the string function which use to get the function from the function,txt
    int number_function_his;            //this is use to draw how many number of graph history in the side bar
    sf::Text history;                   //text of graph history
    sf::Text word;                      //text for word "History:" shown on sidebar
    sf::RectangleShape direction_button;
    sf::Text direction;                 //text for word "direction" shown window
    sf::Text equation;                  //output equation on the graph
    float _width;

    sf::RectangleShape _home_button;
    sf::Text _home;
};

string mouse_pos_string(sf::RenderWindow& window);

#endif // ANIMATE_H
