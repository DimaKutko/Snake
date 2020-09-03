#include "Play.hpp"

Play::Play(int height, int width) : window(VideoMode(height, width), "Snake") {
    const int counterFigure = 2;
    
    time = 0;
    
    window.setVerticalSyncEnabled(true);
    
    graphics.reserve(counterFigure);
    
    graphics[0] = new Walls(window);
    
    graphics[1] = new Snake();
    
}
