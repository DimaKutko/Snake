#pragma once
#include "Figure.hpp"
#include "Point.hpp"
#include <SFML/Graphics.hpp>
#include "Apple.hpp"

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
    bool eat(int x, int y);
    int size();
    int getSpeed();
    
private:
    int headX;
    int headY;
    Direction direction;
    int timeCounter = 0;
    int speed = 10;
    
    void shift();
    bool tailCheck();
};



