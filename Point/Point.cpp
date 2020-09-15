#include "Point.hpp"

Point::Point(int x, int y){
    this -> x = x;
    this -> y = y;
    
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

void Point::setSize(int size){
    point.setSize(Vector2f(size,size));
}

int Point::getSize(){
    return size;
}

void Point::setY(int y){
    this -> y = y;
    point.setPosition(x, this -> y);
}

void Point::setX(int x){
    this -> x = x;
    point.setPosition(this -> x, y);
}

int Point::getY(){
    return y;
}

int Point::getX(){
    return x;
}

void Point::operator=(const Point &other){
    this -> x = other.x;
    this -> y = other.y;
    
    point.setPosition(x, y);
}

