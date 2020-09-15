#pragma once
#include "Figure.hpp"
#include "Point.hpp"

enum Direction {UP, DOWN, LEFT, RIGHT};

class Snake : public Figure{
public:
    Snake(int size = 3, int x = 250, int y = 250) ;
    
    void draw(RenderWindow& window) override;
    vector<Point*>* getSnake();
    void step();
    void setDirection(Direction direction);
    Direction getDirection();
    
private:
    int headX;
    int headY;
    Direction direction;
    int timeCounter = 3;
    
    void stepLeft();
    void stepRight();
    void stepTop();
    void stepDown();
    void shift();
};



