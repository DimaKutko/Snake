#include "Walls.hpp"


Walls::Walls(RenderWindow& window) : Figure(4){
    
    for(int i = 0; i < 4; i++){
        figure.push_back(new Point(1,2));
        figure[i] -> setColor(wallsColor[0], wallsColor[1], wallsColor[2]);
    }
    
    figure[0] -> setSize(10, window.getSize().x);
    figure[0] -> setX(10);
    figure[0] -> setY(50);
    
    figure[1] -> setSize(10, window.getSize().x);
    figure[1] -> setX(window.getSize().x);
    figure[1] -> setY(50);
    
    figure[2] -> setSize(window.getSize().y, 10);
    figure[2] -> setX(10);
    figure[2] -> setY(50);
    
    figure[3] -> setSize(window.getSize().y, 10);
    figure[3] -> setX(10);
    figure[3] -> setY(window.getSize().y);
}

void Walls::draw(RenderWindow& window){
    for(Point* p : figure){
        p -> draw(window);
    }
}
