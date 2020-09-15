#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

class Point{
public:
    Point(int x = 0, int y = 0);
    void draw(RenderWindow& window);
    void setColor(int r = 0, int g = 0, int b = 0);
    void setSize(int size = 20);
    int getSize();
    
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    void operator=(const Point& other);
    
private:
    RectangleShape point;
    int size = 20;
    int x;
    int y;
};
