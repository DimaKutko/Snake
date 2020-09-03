#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Point.hpp"
#include "Snake.hpp"
#include "Walls.hpp"

using namespace std;

void action(sf::RenderWindow& window, sf::Event& event){
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)window.close();
        
        if(event.type == sf::Event::KeyPressed){
            switch (event.key.code) {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                case sf::Keyboard::Up:
                    cout << "UP" << endl;
                    
                    break;
                case sf::Keyboard::Down:
                    cout << "Down" << endl;
                    
                    break;
                case sf::Keyboard::Left:
                    cout << "Left" << endl;
                    
                    break;
                case sf::Keyboard::Right:
                    cout << "Right" << endl;
                    
                    break;
                default:
                    cout << "NULL" << endl;
                    break;
            }
        }
        
    }
}


int main()
{
    
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Snake");
    
    sf::Clock clock;
    float time;
    window.setVerticalSyncEnabled(true);
    
    Snake s(3, 500, 500);
    Walls w(window);
    
    while(window.isOpen())
    {
        sf::Event event;
        
        action(window, event);
        
        window.clear();
        time = clock.getElapsedTime().asMilliseconds();
        clock.restart();
        
        w.draw(window);
        s.draw(window);
        
        window.display();
    }
    return 0;
}
