#include "Snake.hpp"
#include <iostream>

Snake::Snake(int size, int x, int y): Figure(size){
    
    headX = x;
    headY = y;
    
    for(int i = 0; i < size; i++){
        figure.push_back(new Point(x,y));
        x += 10;
    }
    
    direction = LEFT;
}

void Snake::draw(RenderWindow& window){
    for(Point* p : figure){
        p->draw(window);
    }
}

void Snake::step(){
    
    if(timeCounter != 0){
        timeCounter--;
    }else{
        
        timeCounter = 10;
        
        shift();
        
        switch (direction) {
            case UP:
                headY -= 10;
                break;
            case DOWN:
                headY += 10;
                break;
            case LEFT:
                headX -= 10;
                break;
            case RIGHT:
                headX += 10;
                break;
            default:
                return;
        }
        
        figure[0] -> setY(headY);
        figure[0] -> setX(headX);
    }
}

void Snake::setDirection(Direction direction){
    this -> direction = direction;
}

void Snake::stepLeft(){
    shift();
    
    headX -= 10;

    figure[0] -> setY(headY);
    
    figure[0] -> setX(headX);
}

void Snake::stepRight(){
    shift();
    
    headX += 10;
    
    
    figure[0] -> setY(headY);
    
    figure[0] -> setX(headX);
}

void Snake::stepTop(){
    shift();
    
    headY -= 10;
    
    
    figure[0] -> setY(headY);
    
    figure[0] -> setX(headX);
}

void Snake::stepDown(){
    shift();
    
    headY += 10;
    
    
    figure[0] -> setY(headY);
    
    figure[0] -> setX(headX);
    
}

void Snake::shift(){
    Point* temp = figure[figure.size() - 1];
    
    for(int i = figure.size() - 1; i > 0; i--){
        figure[i] = figure[i-1];
    }
    
    figure[0] = temp;
}

