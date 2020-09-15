#pragma once
#include <SFML/Graphics.hpp>
#include "Figure.hpp"
#include "Snake.hpp"
#include "Walls.hpp"
#include <iostream>
#include <vector>
#include "Apple.hpp"

using namespace sf;

class Play{
public:
    Play(int height = 600, int width = 600);
    ~Play();
    
    void run();
    
private:
    RenderWindow window;
    vector<Figure*> graphics;
    Snake* snake;
    Apple* apple;
    
    void action(RenderWindow& window, Event& event);
};

