#ifndef SYSTEM_H
#define SYSTEM_H


#include "graph_info.h"
#include "graph.h"

using namespace std;
class System
{
public:
    System(graph_info* info);
    void Step(int command, graph_info* info);
//    int Size();
    void set_info();
    void Draw(sf::RenderWindow& widnow);
private:
    graph _g;
};

#endif // SYSTEM_H
