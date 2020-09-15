#pragma once
#include "Point.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Figure{
public:
    Figure(int size);
    virtual ~Figure();
    virtual void draw(RenderWindow& window) = 0;
    
protected:
    vector<Point*> figure;
};



