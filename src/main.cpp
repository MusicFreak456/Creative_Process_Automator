#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>

#include"Keyboard.hpp"

using namespace std;

int main()
{
    sf::RenderWindow main_window(sf::VideoMode(1798,500),"Creative Process Automator");
    main_window.setFramerateLimit(60);

    sf::Font montserrat_black;
    if(montserrat_black.loadFromFile("fonts/Montserrat-Black.ttf"))
    {
        cout << "Font black loaded" << endl;
    }
    sf::Font montserrat_regular;
    if(montserrat_regular.loadFromFile("fonts/Montserrat-Regular.ttf"))
    {
        cout << "Font regular loaded" << endl;
    }
    sf::Color background(0,32,43);

    Keyboard keyboard;
    keyboard.movePosition(0,main_window.getSize().y - keyboard.get_keys_height());

    while(main_window.isOpen())
    {
        sf::Event event;
        while (main_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                main_window.close();
            }
        }

        main_window.clear(background);
        main_window.draw(keyboard);
        main_window.display();
    }

    return 0;
}