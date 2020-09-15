#pragma once
#include "Figure.hpp"
#include "Snake.hpp"

class Apple : public Figure {
public:
    Apple(RenderWindow& window);
    int getX();
    int getY();
    void generate(Snake* snake);
    
    void draw(RenderWindow& window) override;
};
