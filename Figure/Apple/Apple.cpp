#include "Apple.hpp"

Apple::Apple(RenderWindow& window) : Figure(1){
    int x = (rand() % (window.getSize().x / 20)) * 20;
    int y = (rand() % (window.getSize().y / 20)) * 20;
    
    figure.push_back(new Point(x,y));
    
    figure[0] -> setColor(0,255,0);
}

int Apple::getY(){
    return figure[0] -> getY();
}

int Apple::getX(){
    return figure[0] -> getX();
}

void Apple::draw(RenderWindow& window){
    figure[0] -> draw(window);
}
