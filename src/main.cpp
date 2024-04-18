#include <iostream>

#include "systems/ScreenManager.h"
#include "screen/TitleScreen.h"
#include "screen/MenuScreen.h"

#include <SFML/Graphics.hpp>

/*
int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    int WIDTH = desktop.width;
    int HEIGHT = desktop.height;

    sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "Goodies", sf::Style::Default);

    ScreenManager screenManager;
    screenManager.setScreen(std::make_unique<TitleScreen>(&screenManager));
    screenManager.handleResize(win);

    int i = 0;

    while (win.isOpen()) 
    {
        std::cout << "Run " << i << std::endl;

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
*/

int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    int WIDTH = desktop.width;
    int HEIGHT = desktop.height;

    sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "Goodies", sf::Style::Default);

    ScreenManager::getInstance().setWin(&win);

    ScreenManager::getInstance().addScreen("TitleScreen", std::make_unique<TitleScreen>());
    ScreenManager::getInstance().addScreen("MenuScreen", std::make_unique<MenuScreen>());

    ScreenManager::getInstance().setScreen("TitleScreen");
    ScreenManager::getInstance().handleResize(win);


    int i = 0;
    sf::Clock deltaClock;
    sf::Time deltaTime;
    while (win.isOpen())
    {
        std::cout << "Run " << i << std::endl;

        ScreenManager::getInstance().update(deltaTime);

        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }

            if (event.type == sf::Event::Resized)
            {
                ScreenManager::getInstance().handleResize(win);
            }

            ScreenManager::getInstance().handleInput(event, win);
        }

        win.clear();
        ScreenManager::getInstance().draw(win);
        win.display();


        deltaTime = deltaClock.restart();
        i++;
    }

    return 0;
}
