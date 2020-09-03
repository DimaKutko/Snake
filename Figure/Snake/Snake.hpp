#pragma once
#include "Figure.hpp"

class Snake : public Figure{
public:
    Snake(int size = 3, int x = 500, int y = 500) : Figure(size){
        headX = x;
        headY = y;
        for(int i = 0; i < size; i++){
            figure.push_back(new Point(x,y));
            x += 10;
        }
    }
    
    void draw(RenderWindow& window) override;
    
private:
    int headX;
    int headY;
};

