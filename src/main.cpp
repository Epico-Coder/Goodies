#include <iostream>

#include "screen/ScreenTitle.h"

#include <SFML/Graphics.hpp>

int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    int WIDTH = desktop.width;
    int HEIGHT = desktop.height;

    sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "Goodies", sf::Style::Default);

    TitleScreen titleScreen;
    titleScreen.handleResize(win);

    int i = 0;

    while (win.isOpen()) 
    {
        //std::cout << "Run " << i << std::endl;

        sf::Event event;
        while (win.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }

            titleScreen.handleInput(event, win);
        }

        win.clear();
        titleScreen.draw(win);
        win.display();

        i++;
    }

    return 0;
}
