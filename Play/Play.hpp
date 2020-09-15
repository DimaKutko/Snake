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
    Play(int height = 1000, int width = 1000);
    ~Play();
    
    void run();
    
private:
    RenderWindow window;
    Clock clock;
    float time;
    vector<Figure*> graphics;
    Snake* _snake;
    
    void action(RenderWindow& window, Event& event);
};
