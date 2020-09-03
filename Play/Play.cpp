#include "Play.hpp"

Play::Play(int height, int width) : window(VideoMode(height, width), "Snake") {
    const int counterFigure = 2;
    
    time = 0;
    
    window.setVerticalSyncEnabled(true);
    
    graphics.reserve(counterFigure);
    
    graphics.push_back(new Walls(window));
    graphics.push_back(new Snake());
}

Play::~Play(){
    std::cout << "~Play\n";
    for(Figure* f : graphics) delete f;
    
}

void Play::run(){
    std::cout << graphics.size();
    while(window.isOpen())
    {
        Event event;
        
        action(window, event);
        window.clear();
        time = clock.getElapsedTime().asMilliseconds();
        clock.restart();
        
        for(Figure* f : graphics) f->draw(window);
        
        window.display();
    }
}

void Play::action(RenderWindow& window, Event& event){
    while(window.pollEvent(event))
    {
        if(event.type == Event::Closed)window.close();
        
        if(event.type == Event::KeyPressed){
            switch (event.key.code) {
                case Keyboard::Escape:
                    window.close();
                    break;
                case Keyboard::Up:
                    std::cout << "UP" << std::endl;
                    
                    break;
                case Keyboard::Down:
                    std::cout << "Down" << std::endl;
                    
                    break;
                case Keyboard::Left:
                    std::cout << "Left" << std::endl;
                    
                    break;
                case Keyboard::Right:
                    std::cout << "Right" << std::endl;
                    
                    break;
                default:
                    std::cout << "NULL" << std::endl;
                    break;
            }
        }
        
    }
}
