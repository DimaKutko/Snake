#include "Snake.hpp"
#include <iostream>

Snake::Snake(RenderWindow& window, int size): Figure(size){
    
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
    
    figure[0] -> setColor(255, 0, 0);
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
                headY -= 20;
                break;
            case DOWN:
                headY += 20;
                break;
            case LEFT:
                headX -= 20;
                break;
            case RIGHT:
                headX += 20;
                break;
            default:
                return;
        }
        
        figure[0] -> setY(headY);
        figure[0] -> setX(headX);
    }
}

void Snake::setDirection(Direction direction){
    if(isStop())return;
    
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
        case STOP:
            break;
    }
    
    this -> direction = direction;
}

void Snake::shift(){
    figure[0] -> setColor(255, 255, 255);
    
    Point* temp = figure[figure.size() - 1];
    
    for(int i = figure.size() - 1; i > 0; i--){
        figure[i] = figure[i-1];
    }
    
    figure[0] = temp;
    
    figure[0] -> setColor(255, 0, 0);
}

void Snake::setSpeed(int speed){
    this -> speed = speed;
}

void Snake::deadlockCheck(RenderWindow& window){
    if(headX == 20 && direction == LEFT) direction = STOP;
    if(headX == window.getSize().x - 20 && direction == RIGHT) direction = STOP;
    if(headY == 20 && direction == UP) direction = STOP;
    if(headY == window.getSize().y - 20 && direction == DOWN) direction = STOP;
    if(tailCheck())direction = STOP;
}

bool Snake::tailCheck(){
    bool check = false;
    
    if(direction == LEFT){
        for(Point* p : figure){
            if(p -> getX() == headX - 20 && p -> getY() == headY){
                check = true;
                break;
            }
        }
    }else if(direction == RIGHT){
        for(Point* p : figure){
            if(p -> getX() == headX + 20 && p -> getY() == headY) {
                check = true;
                break;
            }
        }
    }else if(direction == UP){
        for(Point* p : figure){
            if(p -> getY() == headY - 20 && p -> getX() == headX) {
                check = true;
                break;
            }
        }
    }else if(direction == DOWN){
        for(Point* p : figure){
            if(p -> getY() == headY + 20 && p -> getX() == headX) {
                check = true;
                break;
            }
        }
    }
    
    return check;
}

bool Snake::isStop(){
    return direction == STOP;
}

void Snake::dead(){
    for(int i = 1; i < figure.size(); i++){
        figure[i] -> setColor(139,0,0);
    }
}

bool Snake::eat(int x, int y){
    for(Point* s : figure){
        if(s -> getX() == x && s -> getY() == y){
            figure.push_back(new Point(figure[figure.size()-1]->getX(), figure[figure.size()-1]->getY()));
            return true;
        }
    }
    return false;
}
