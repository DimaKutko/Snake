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
    Play(int height = 500, int width = 500);
    ~Play();
    
    void run();
    
private:
    RenderWindow window;
    vector<Figure*> graphics;
    Snake* _snake;
    
    void action(RenderWindow& window, Event& event);
};

