#include "Apple.hpp"


int generateX(RenderWindow& window){
    int h20 = (window.getSize().x / 20) - 1;
    return (rand() % h20 + 1 ) * 20;
}

int generateY(RenderWindow& window){
    int y20 = (window.getSize().x / 20) - 1;
    return (rand() % y20 + 3 ) * 20;
}

Apple::Apple(RenderWindow& window) : Figure(1){
    figure.push_back(new Point(generateX(window),generateY(window)));
    
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

void Apple::generate(RenderWindow& window){
    figure[0] -> setXY(generateX(window), generateY(window));
}

