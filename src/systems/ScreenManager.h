#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>

#include "../screen/TitleScreen.h"
#include "../screen/MenuScreen.h"

#include <SFML/Graphics.hpp>

class ScreenManager : public Observer
{
public:
    ScreenManager();

    void onNotify(const std::string& event, const std::string& data) override;
    void setScreen(std::unique_ptr<Screen> screen);
    void setScreen(std::string screenName);
    void handleInput(const sf::Event& event, sf::RenderWindow& window);
    void update(sf::Time deltaTime);
    void draw(sf::RenderWindow& window);
    void handleResize(sf::RenderWindow& window);

private:
    std::unordered_map<std::string, std::unique_ptr<Screen>> p_screens;
    std::unique_ptr<Screen> p_currentScreen;
};
