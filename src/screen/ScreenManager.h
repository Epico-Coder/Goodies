#pragma once

#include <iostream>
#include <memory>

#include "Screen.h"
#include "TitleScreen.h"
#include "MenuScreen.h"

#include <SFML/Graphics.hpp>

class ScreenManager
{
public:
    static ScreenManager& getInstance();

    ScreenManager(const ScreenManager&) = delete;
    ScreenManager& operator=(const ScreenManager&) = delete;

    void setScreen(std::unique_ptr<Screen> screen);
    void setScreen(std::string screenName);
    void handleInput(const sf::Event& event, sf::RenderWindow& window);
    void update(sf::Time deltaTime);
    void draw(sf::RenderWindow& window);
    void handleResize(sf::RenderWindow& window);
private:
    std::unique_ptr<Screen> p_currentScreen;
    static ScreenManager* instance;

    ScreenManager() {}
};
