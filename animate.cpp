#include "animate.h"
#include <string.h>
#include "constant.h"
#include <iostream>
using namespace std;
#include "system.h"
#include "graph_info.h"
#include <vector>

#include "textbox.h"

animate::animate():_info(new graph_info), sidebar(WORK_PANEL, SIDE_BAR),system(_info), command(0), input(""), is_input(false),inputing(true)

{
    cout<<"animate CTOR: TOP"<<endl;
    cout << "================" << endl;

    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Graphing Calculator");
    window.setFramerateLimit(60);
    outStream.open("Functions.txt", ios::app);
    inStream.open("Functions.txt");
    while(!inStream.eof())
    {//read the function from function.txt and store it in vector string
        getline(inStream, _function);
        _functions.push_back(_function);
    }

    for (int i = _functions.size() - 1; i >= 0; i--)
    {//draw the text of the function
        history = sf::Text(_functions[i], font);
        history.setCharacterSize(23);
        history.setFillColor(sf::Color::Black);
    }

    //draw the word of history to tell the graph history
    word = sf::Text("History: ", font);
    word.setCharacterSize(23);
    word.setFillColor(sf::Color::Black);
    word.setPosition(sf::Vector2f(1131, 755));

    //home button to reset to defult
    _home_button.setSize(sf::Vector2f(220, 60));
    _home_button.setPosition(sf::Vector2f(1146, 400));
    _home_button.setOutlineColor(sf::Color::Black);
    _home_button.setOutlineThickness(2.0);
    _home = sf::Text("Home ", font);
    _home.setCharacterSize(23);
    _home.setFillColor(sf::Color::Black);
    _home.setPosition(sf::Vector2f(1230, 416));

    //draw the word of direction to tell the user input to view direction
    direction = sf::Text("Direction ", font);
    direction.setCharacterSize(23);
    direction.setFillColor(sf::Color::Black);
    direction.setPosition(sf::Vector2f(1215, 498));
    direction_button.setSize(sf::Vector2f(220, 60));
    direction_button.setPosition(sf::Vector2f(1146, 480));
    direction_button.setOutlineColor(sf::Color::Black);
    direction_button.setOutlineThickness(2.0);


    if(outStream.fail())
    {
        cout << "failed to open file" << endl;
        exit(1);
    }

    //make the initial graph to be the most recent graph ypu had
    input = _functions[_functions.size() - 1];
    equation = sf::Text(input, font);
    _info->_equation = get_input();
    input = "";

    cout<<"Geme CTOR. preparing to load the font."<<endl;

    if (!font.loadFromFile("arial.ttf"))
    {
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

    cout<<"animate instantiated successfully."<<endl;
}

void animate::Draw()
{
    const double VERTICAL_LINE_SPACING = 10.0;
    const double LEFT_MARGIN = 10.0;
    float height = 10;
    system.Draw(window);
    sidebar.draw(window);
    window.draw(_home_button);
    window.draw(_home);
    window.draw(direction_button);
    window.draw(direction);


    if(is_input == true)
    {//this is used to draw the input box
        window.draw(input_box);
        if(inputing == false)
        {
            window.draw(myTextLabel);
        }

        window.draw(input_text);
    }


    //draw 10 functions from most recent to far
    number_function_his = 0;
    for (vector<string>::reverse_iterator it = _functions.rbegin();
                                it!= _functions.rend() && number_function_his < 10; ++it , number_function_his++){
        bool blank = false;
        if (strlen(it->c_str()) == 0){
            //empty rows must be taken into account (getLocalBounds())
            //    but not drawn
            blank = true;
            history.setString("BLANK");
        }
        else{
            history.setString(it->c_str());
        }
        history.setPosition(sf::Vector2f(WORK_PANEL+LEFT_MARGIN, height + 800));
        height += history.getLocalBounds().height+VERTICAL_LINE_SPACING;
        if (!blank)
            window.draw(history);
    }
    equation.setColor(sf::Color::Black);
    equation.setPosition(sf::Vector2f(1127, 600));
    window.draw(equation);
    window.draw(word);

}
void animate::update(){
    //cause changes to the data for the next frame
    system.Step(command, _info);

    command = 0;
    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);

        //mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);

    }
}
void animate::render()
{
       window.clear();
       Draw();
       window.display();
}



void animate::processEvents()
{
   sf::Event event;
   float mouseX, mouseY;
   while (window.pollEvent(event))//or waitEvent
       {
       // check the type of the event...
           switch (event.type)
           {
           // window closed
           case sf::Event::Closed:
               window.close();
               break;
           case::sf::Event::TextEntered:
           {//when the text is being enter
               inputing = true;


               if(event.text.unicode < 128)
               {//add each character you entered into input string

                   input += static_cast<char>(event.text.unicode);
                   if(event.text.unicode == '\b')
                   {
                       if(input.size() > 1)
                       {//erase the last element
                           input.erase(input.size() - 2, input.size() - 1);
                       }

                   }
                   input_text = sf::Text(input, font);
                   input_text.setCharacterSize(50);
                   input_text.setFillColor(sf::Color::Yellow);
                   input_text.setPosition(sf::Vector2f(340, 155));
               }
               break;
           }
           // key pressed
           case sf::Event::KeyPressed:
               switch(event.key.code)
               {


               case sf::Keyboard::Left:
              {
                  sidebar[SB_KEY_PRESSED] = "Pan Left";

                  command = 3;
                  break;
              }
              case sf::Keyboard::Right:
              {
                  sidebar[SB_KEY_PRESSED] = "Pan Right";
                  command = 4;
                  break;
              }
               case sf::Keyboard::Up:
               {
                   sidebar[SB_KEY_PRESSED] = "Pan Up";
                   command = 5;
                   break;
               }
               case sf::Keyboard::Down:
               {
                   sidebar[SB_KEY_PRESSED] = "Pan Down";
                   command = 6;
                   break;
               }
              case sf::Keyboard::Escape:
              {
                  sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                  window.close();
                   break;
               }
              case sf::Keyboard::LAlt:
              {
                  command = 1;
                  sidebar[SB_KEY_PRESSED] = "Zoom in";
                  break;
              }


              case sf::Keyboard::Tab:
              {
                  command = 2;
                  sidebar[SB_KEY_PRESSED] = "Zoom out";
                  break;
              }



               case sf::Keyboard::F:
               {//get the string

                   //set the input box
                   input = "";
                   is_input = true;
                   input_box.setSize(sf::Vector2f(480, 90));
                   input_box.setPosition(320,150);
                   input_box.setFillColor(sf::Color::Black);
                   input_box.setOutlineColor(sf::Color::White);
                   input_box.setOutlineThickness(2.0);

                   //set f(x) =
                   inputing = false;
                   myTextLabel = sf::Text("F(x) = ", font);
                   myTextLabel.setCharacterSize(50);
                   myTextLabel.setStyle(sf::Text::Bold);
                   myTextLabel.setColor(sf::Color::White);
                   myTextLabel.setPosition(sf::Vector2f(320, 155));
                   window.pollEvent(event);

                   break;
               }



               case sf::Keyboard::Enter:
               {//press enter to finish inputting
                   outStream << endl;
                   _info->_equation = get_input();
                   _functions.push_back(input);
                   outStream << input ;
                   equation = sf::Text(input, font);
                   is_input = false;
                   input = "";
                   break;
               }

               }

               break;







           case sf::Event::MouseEntered:
               mouseIn = true;
               break;

           case sf::Event::MouseLeft:
               mouseIn = false;
               break;

           case sf::Event::MouseMoved:
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
                //Do something with it if you need to...
               break;
           case sf::Event::MouseButtonReleased:
                   if (event.mouseButton.button == sf::Mouse::Right)
                   {
                       sidebar[SB_MOUSE_CLICKED] = "RIGHT CLICK " +
                               mouse_pos_string(window);

                   }
                   else{

                       int mouse_x = sf::Mouse::getPosition(window).x;
                       int mouse_y = sf::Mouse::getPosition(window).y;

                       int size = _functions.size();
                       //give a range of x and y on the sidebar that each history graph is located
                       //is like creating a invisible box around the graph histry
                       //whenever you are click at that box, it would call that function
                       if(mouse_x >= 1132 && mouse_x <= 1245 && mouse_y >= 815 && mouse_y <= 832)
                       {
                           input = _functions[size - 1];
                           _info->_equation = get_input();
                           equation = sf::Text(input, font);
                           input = "";
                       }
                       else if (mouse_x >= 1131 && mouse_x <= 1245 && mouse_y >= 843 && mouse_y <= 862)
                       {
                           input = _functions[size - 2];
                           _info->_equation = get_input();
                           equation = sf::Text(input, font);
                           input = "";
                       }
                       else if (mouse_x >= 1131 && mouse_x <= 1245 && mouse_y >= 873 && mouse_y <= 889)
                       {
                           input = _functions[size - 3];
                           _info->_equation = get_input();
                           equation = sf::Text(input, font);
                           input = "";
                       }
                       else if (mouse_x >= 1131 && mouse_x <= 1245 && mouse_y >= 899 && mouse_y <= 918)
                       {
                           input = _functions[size - 4];
                           _info->_equation = get_input();
                           equation = sf::Text(input, font);
                           input = "";
                       }
                       else if (mouse_x >= 1131 && mouse_x <= 1245 && mouse_y >= 926 && mouse_y <= 948)
                       {
                           input = _functions[size - 5];
                           _info->_equation = get_input();
                           equation = sf::Text(input, font);
                           input = "";
                       }
                       else if (mouse_x >= 1131 && mouse_x <= 1245 && mouse_y >= 958 && mouse_y <= 976)
                       {
                           input = _functions[size - 6];
                           _info->_equation = get_input();
                           equation = sf::Text(input, font);
                           input = "";
                       }
                       else if (mouse_x >= 1131 && mouse_x <= 1245 && mouse_y >= 985 && mouse_y <= 1000)
                       {
                           input = _functions[size - 7];
                           _info->_equation = get_input();
                           equation = sf::Text(input, font);
                           input = "";
                       }
                       else if (mouse_x >= 1131 && mouse_x <= 1245 && mouse_y >= 1010 && mouse_y <= 1027)
                       {
                           input = _functions[size - 8];
                           _info->_equation = get_input();
                           equation = sf::Text(input, font);
                           input = "";
                       }
                       else if (mouse_x >= 1131 && mouse_x <= 1245 && mouse_y >= 1038 && mouse_y <= 1053)
                       {
                           input = _functions[size - 9];
                           _info->_equation = get_input();
                           equation = sf::Text(input, font);
                           input = "";
                       }
                       else if (mouse_x >= 1131 && mouse_x <= 1245 && mouse_y >= 1060 && mouse_y <= 1076)
                       {
                           input = _functions[size - 10];
                           _info->_equation = get_input();
                           equation = sf::Text(input, font);
                           input = "";
                       }
                       else if(mouse_x >= 1143 && mouse_x <= 1366 && mouse_y >= 399 && mouse_y <= 459)
                       {//home
                           _info->_origin = sf::Vector2f(_info->_window_demensions.x / 2, _info->_window_demensions.y / 2);
                           _info->_domain.x = -5;
                           _info->_domain.y = 5;
                           _info->_scale.x = 120;
                           _info->_scale.y = 120;
                       }
                       else if(mouse_x >= 1143 && mouse_x <= 1366 && mouse_y >= 480 && mouse_y <= 540)
                       {//home
                           sidebar[SB_MOUSE_CLICKED] = "[Tab]ZOOM IN \n[LAlt]ZOOM OUT \n[Left]PAN LEFT \n[Right]PAN RIGHT \n[F]INPUT \n[Space]HOME \nClick the function \nin the history \nto draw";
                       }
                       else
                       {
                           sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
                                   mouse_pos_string(window);
                       }

                   }
                   break;
               default:
                   break;
           }
       }
}
void animate::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
   outStream.close();
   inStream.close();
   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}



//[][][][][][][][][][]

string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}

void animate::set_info()
{
    system.set_info();
}

Queue <Token*> animate::get_input()
{
    //this function will take in the string input and convert to infix queue
    Queue <Token*> _my_infix;
    int i = input.length();
    char str[i + 1];
    strcpy(str, input.c_str());
    char delim[] = " ";
    char* token = strtok(str, delim);

    while(token != nullptr)
    {
        //compare the token with variables
        if(strcmp(token, "sin") == 0 || strcmp(token, "cos") == 0 || strcmp(token, "tan") == 0 || strcmp(token, "sec") == 0 || strcmp(token, "csc") == 0 || strcmp(token, "cot") == 0)
        {
            _my_infix.push(new Function(token));
        }
        else if ( strcmp(token, "(") == 0)
        {
            _my_infix.push(new Left_parenthesis(token));
        }
        else if (strcmp(token, "x") == 0)
        {
            _my_infix.push(new variable ('x'));
        }
        else if ( strcmp(token, ")") == 0)
        {
            _my_infix.push(new Right_Parenthesis(token));
        }
        else if(strcmp(token, "*") == 0 || strcmp(token, "/") == 0 || strcmp(token, "-") == 0 || strcmp(token, "+") == 0 || strcmp(token, "^") == 0 )
        {
            _my_infix.push(new Operator(token));
        }
        else
        {
            int number = ((int) *token) - 48;
            _my_infix.push(new Number(number));
        }

        token = strtok(NULL, delim);
    }
    return  _my_infix;
}






