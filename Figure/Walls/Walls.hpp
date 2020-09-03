#pragma once
#include "Figure.hpp"
#include "Point.hpp"
#include <iostream>

const int wallsColor[3] = {153,102,51};

class Walls : public Figure{
public:
    Walls(RenderWindow& window);
    ~Walls();
    
    void draw(RenderWindow& window) override;
    
    
private:
    vector<Point*> left;
    vector<Point*> down;
    vector<Point*> right;
};
