#include "Snake.hpp"

void Snake::draw(RenderWindow& window){
    for(Point* p : figure){
        p->draw(window);
    }
}

