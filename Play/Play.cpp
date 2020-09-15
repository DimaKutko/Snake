#include "Play.hpp"

Play::Play(int height, int width) : window(VideoMode(height, width), "Snake") {
    const int counterFigure = 3;
    
    window.setVerticalSyncEnabled(true);
    
    snake = new Snake(window);
    
    apple = new Apple(window);
    
    graphics.reserve(counterFigure);
    
    graphics.push_back(new Walls(window));
    
    graphics.push_back(snake);
    
    graphics.push_back(apple);
    
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
        
        snake -> deadlockCheck(window);
        
        if(snake -> isStop()){
            snake -> dead();
        }else{
            snake -> step(window);
        }
        
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
                    if(snake -> isStop())return;
                    std::cout << "UP" << std::endl;
                    snake -> setDirection(UP);
                    break;
                case Keyboard::Down:
                case Keyboard::S:
                    if(snake -> isStop())return;
                    std::cout << "Down" << std::endl;
                    snake -> setDirection(DOWN);
                    break;
                case Keyboard::Left:
                case Keyboard::A:
                    if(snake -> isStop())return;
                    std::cout << "Left" << std::endl;
                    snake -> setDirection(LEFT);
                    break;
                case Keyboard::Right:
                case Keyboard::D:
                    if(snake -> isStop())return;
                    std::cout << "Right" << std::endl;
                    snake -> setDirection(RIGHT);
                    break;
                default:
                    std::cout << "NULL" << std::endl;
                    break;
            }
        }
        
    }
}
