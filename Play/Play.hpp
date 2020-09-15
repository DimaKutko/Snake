#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Figure.hpp"
#include "Snake.hpp"
#include "Walls.hpp"
#include <iostream>
#include <vector>

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
    
    void action(RenderWindow& window, Event& event);
};

