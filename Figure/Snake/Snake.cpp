#include "Snake.hpp"
#include <iostream>

Snake::Snake( RenderWindow& window, int size): Figure(size){
    
    int x = window.getSize().x / 2;
    int y = window.getSize().y / 2;
    
    headX = x;
    headY = y;
    
    for(int i = 0; i < size; i++){
        figure.push_back(new Point(x,y));
        x += 10;
    }
    
    speed = 5;
    
    direction = LEFT;
}

void Snake::draw(RenderWindow& window){
    for(Point* p : figure){
        p->draw(window);
    }
}

void Snake::step(RenderWindow& window){
    
    if(direction == STOP)return;
    
    if(timeCounter != 0){
        timeCounter--;
    }else{
        timeCounter = speed;
        
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
    switch (direction) {
        case UP:
            if(this -> direction == DOWN) return;
            break;
         case DOWN:
            if(this -> direction == UP) return;
            break;
        case LEFT:
            if(this -> direction ==  RIGHT) return;
            break;
        case RIGHT:
            if(this -> direction == LEFT) return;
            break;
    }
    
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

void Snake::setSpeed(int speed){
    this -> speed = speed;
}

void Snake::deadlockCheck(RenderWindow& window){
    if(headX == 20 && direction == LEFT) direction = STOP;
    if(headX == window.getSize().x - 20 && direction == RIGHT) direction = STOP;
    if(headY == 20 && direction == UP) direction = STOP;
    if(headY == window.getSize().y - 20 && direction == DOWN) direction = STOP;
}
