#include "Point.hpp"

Point::Point(int x, int y){
    x = x;
    y = y;
    
    point.setSize(Vector2f(size,size));
    
    
    point.setOrigin(size/2, size/2);
    point.setPosition(x, y);
}

void Point::setColor(int r , int g, int b){
    point.setFillColor(Color(r,g,b));
}

void Point::draw(RenderWindow& window){
    window.draw(point);
}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

void Point::setXY(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::getX(){
    return x;
}

int Point::getY(){
    return y;
}

void Point::setSize(int size){
    point.setSize(Vector2f(size,size));
}
int Point::getSize(){
    return size;
}
