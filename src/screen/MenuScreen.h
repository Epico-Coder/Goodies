#pragma once

#include "Screen.h"
#include "../systems/ScreenManager.h"
#include "../utility/Button.h"
#include "../utility/Extra.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class MenuScreen : public Screen
{
public:
    MenuScreen();
    void init(sf::RenderWindow& window);
    void unScreen();
    void draw(sf::RenderWindow& window);
    void update(sf::Time delaTime);
    void handleInput(const sf::Event& event, sf::RenderWindow& window);
    void handleResize(sf::RenderWindow& window);
private:
    sf::Texture p_backgroundTexture;
    sf::Sprite p_background;

    std::vector<Button> p_buttons;
    std::shared_ptr<sf::Font> p_buttonFont;

    sf::Text p_title;
};

