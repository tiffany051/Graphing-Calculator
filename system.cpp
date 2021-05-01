#include "system.h"

#include "system.h"
#include "random.h"

#include <iostream>
#include <constant.h>


System::System(graph_info* info):_g(info)
{
    //blank
}

void System::set_info()
{
    _g.set_info();
}

void System::Step(int command, graph_info* info)
{
    if(command == 1)
    {//zoom in reset the domain and scale
        info->_domain.x /=  1.75;
        info->_domain.y /=  1.75;
        info->_scale.x *= 1.75;
        info->_scale.y *= 1.75;
    }
    else if(command == 2)
    {//zoom out reset the domain and scale
        info->_domain.x *= 1.75;
        info->_domain.y *= 1.75;
        info->_scale.x /= 1.75;
        info->_scale.y /= 1.75;
    }
    else if(command == 3)
    {//pan left
        info->_origin.x += (info->_scale.x / 2);
        info->_domain.x -= .5;
        info->_domain.y -= .5;
    }
    else if (command == 4)
    {//pan right
        info->_origin.x -= (info->_scale.x / 2);
        info->_domain.x += .5;
        info->_domain.y += .5;
    }
    else if (command == 5)
    {//pan up
        info->_origin.y += (info->_scale.x / 2);
    }
    else if (command == 6)
    {//pan down
        info->_origin.y -= (info->_scale.x / 2);
    }
     _g.update();

}


void System::Draw(sf::RenderWindow& window)
{
    _g.draw(window);
}
