#include <iostream>

#include "screen/ScreenManager.h"

#include <SFML/Graphics.hpp>

int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    int WIDTH = desktop.width;
    int HEIGHT = desktop.height;

    sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "Goodies", sf::Style::Default);

    ScreenManager& screenManager = ScreenManager::getInstance();
    screenManager.setScreen(std::make_unique<TitleScreen>());
    screenManager.handleResize(win);

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

            if (event.type == sf::Event::Resized)
            {
                screenManager.handleResize(win);
            }

            screenManager.handleInput(event, win);
        }

        win.clear();
        screenManager.draw(win);
        win.display();

        i++;
    }

    return 0;
}
