#include "TextShow.hpp"

TextShow::TextShow(int speed, int points) : Figure(0){
    if (!font.loadFromFile("FontForSnake.ttf"))
    {
        std::cout << "Error font" << std::endl;
    }
    
    str = "S: " + std::to_string(1) + " | P: " + std::to_string(0);
    
    this -> points = points;
    
    this -> speed = speed;
    
    text.setFillColor(sf::Color::White);
    
    text.setStyle(sf::Text::Bold);
    
    text.setCharacterSize(50);
    
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
    str = "S: " + std::to_string(speed) + " | P: " + std::to_string(points);
}

void TextShow::setString(std::string str){
    this -> str = str;
}
