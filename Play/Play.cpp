#include "Play.hpp"

Play::Play(int height, int width) : window(VideoMode(height, width), "Snake") {
    const int counterFigure = 2;
    
    time = 0;
    
    window.setVerticalSyncEnabled(true);
    
    graphics.reserve(counterFigure);
    
    graphics.push_back(new Walls(window));
    
    _snake = new Snake();
    
    graphics.push_back(_snake);
}

Play::~Play(){
    std::cout << "~Play\n";
    for(Figure* f : graphics) delete f;
    
}

void Play::run(){
    while(window.isOpen())
    {
        Event event;
        
        action(window, event);
        window.clear();
        
        _snake->step();
        
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
                case Keyboard::W:
                    std::cout << "UP" << std::endl;
                    _snake -> setDirection(UP);
                    break;
                case Keyboard::Down:
                case Keyboard::S:
                    std::cout << "Down" << std::endl;
                    _snake -> setDirection(DOWN);
                    break;
                case Keyboard::Left:
                case Keyboard::A:
                    std::cout << "Left" << std::endl;
                    _snake -> setDirection(LEFT);
                    
                    break;
                case Keyboard::Right:
                case Keyboard::D:
                    std::cout << "Right" << std::endl;
                    _snake -> setDirection(RIGHT);
                    
                    break;
                default:
                    std::cout << "NULL" << std::endl;
                    break;
            }
        }
        
    }
}
