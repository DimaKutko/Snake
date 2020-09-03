#include "Walls.hpp"


Walls::Walls(RenderWindow& window) : Figure(window.getSize().x-2){
    const int height = window.getSize().x;
    const int width = window.getSize().y;
    
    left.reserve(height);
    right.reserve(height);
    down.reserve(width-2);
    
    for(int i = 0, x = 0; i < width; i++){
        down.push_back(new Point(x, height));
        figure.push_back(new Point(x, 0));
        
        down[i]->setColor(wallsColor[0], wallsColor[1], wallsColor[2]);
        figure[i]->setColor(wallsColor[0], wallsColor[1], wallsColor[2]);
        x += down[i]->getSize();
    }
    
    for(int i = 0, y = 0; i < height; i++){
        left.push_back(new Point(0, y));
        right.push_back(new Point(width, y));
        
        left[i]->setColor(wallsColor[0], wallsColor[1], wallsColor[2]);
        right[i]->setColor(wallsColor[0], wallsColor[1], wallsColor[2]);
        y += left[i]->getSize();
    }
}

void Walls::draw(RenderWindow& window){
    for(Point* p : figure) p->draw(window);
    for(Point* p : left) p->draw(window);
    for(Point* p : right) p->draw(window);
    for(Point* p : down) p->draw(window);
}
