#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>

#include "../screen/Screen.h"

#include <SFML/Graphics.hpp>

class ScreenManager
{
public:
    static ScreenManager& getInstance();

    void setWin(sf::RenderWindow* win);
    void addScreen(const std::string& name, std::unique_ptr<Screen> screen);
    void setScreen(std::string screenName);
    void handleInput(const sf::Event& event, sf::RenderWindow& window);
    void update(sf::Time deltaTime);
    void draw(sf::RenderWindow& window);
    void handleResize(sf::RenderWindow& window);
private:
    sf::RenderWindow* p_win;
    static ScreenManager* p_instance;
    std::unordered_map<std::string, std::unique_ptr<Screen>> p_screens;
    Screen* p_currentScreen = nullptr;
};
