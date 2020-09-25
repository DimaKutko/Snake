#pragma once
#include <SFML/Graphics.hpp>
#include "Figure.hpp"
#include "Snake.hpp"
#include "Walls.hpp"
#include <iostream>
#include <vector>
#include "Apple.hpp"
#include "TextShow.hpp"
#include "Best.hpp"

using namespace sf;

class Play{
public:
    Play(int height = 640, int width = 600);
    ~Play();
    
    void run();
    
private:
    RenderWindow window;
    vector<Figure*> graphics;
    Snake* snake;
    Apple* apple;
    TextShow* text;
    Best best;
    
    int points;
    
    void restartGame();
    void action(RenderWindow& window, Event& event);
    void speedController();
};

