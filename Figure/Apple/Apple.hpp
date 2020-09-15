#pragma once
#include "Figure.hpp"
#include "Snake.hpp"

class Apple : public Figure {
public:
    Apple(RenderWindow& window);
    int getX();
    int getY();
    void generate(RenderWindow& window);
    
    void draw(RenderWindow& window) override;
};
