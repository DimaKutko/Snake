#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Figure.hpp"

class TextShow : public Figure{
public:
    TextShow(int speed = 1, int points = 0);
    
    void setPoints(int points);
    void setSpeed(int speed);
    void setStringGame(int speed, int points);
    void setString(std::string str);
    void draw(sf::RenderWindow& window) override;
    
private:
    sf::Font font;
    sf::Text text;
    std::string str;
    int speed;
    int points;
};