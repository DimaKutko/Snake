#pragma once
#include "Figure.hpp"
#include "Point.hpp"
#include <SFML/Graphics.hpp>

enum Direction {UP, DOWN, LEFT, RIGHT, STOP};

class Snake : public Figure{
public:
    Snake(RenderWindow& window, int size = 3);
    
    void draw(RenderWindow& window) override;
    void step(RenderWindow& window);
    void setDirection(Direction direction);
    Direction getDirection();
    int getHeadX();
    int getHeadY();
    void setSpeed(int speed);
    void deadlockCheck(RenderWindow& window);
    bool isStop();
    void dead();
    
private:
    int headX;
    int headY;
    Direction direction;
    int timeCounter = 5;
    int speed;
    
    void shift();
    bool tailCheck();
};



