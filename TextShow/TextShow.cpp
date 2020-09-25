#include "TextShow.hpp"

TextShow::TextShow(int speed, int points) : Figure(0){
    if (!font.loadFromFile("FontForSnake.ttf"))
    {
        std::cout << "Error font" << std::endl;
    }
    
    str = "Speed: " + std::to_string(1) + " | Points: " + std::to_string(0);
    
    this -> points = points;
    
    this -> speed = speed;
    
    text.setPosition(0, -5);
    
    text.setFillColor(sf::Color::White);
    
    text.setStyle(sf::Text::Bold);
    
    text.setCharacterSize(35);
    
    text.setFont(font);
}

void TextShow::draw(sf::RenderWindow& window){
    text.setString(str);
    
    window.draw(text);
}

void TextShow::setSpeed(int speed){
    this -> speed = speed;
}

void TextShow::setPoints(int points){
      this -> points = points;
}

void TextShow::setStringGame(int speed, int points){
    str = "Speed: " + std::to_string(speed) + " | Points: " + std::to_string(points);
}

void TextShow::setString(std::string str){
    this -> str = str;
}
