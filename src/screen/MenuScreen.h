#pragma once

#include "Screen.h"

#include "../utility/Button.h"
#include "../utility/Extra.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class MenuScreen : public Screen
{
public:
    MenuScreen();
    void draw(sf::RenderWindow& window);
    void update(sf::Time delaTime);
    void handleInput(const sf::Event& event, sf::RenderWindow& window);
    void handleResize(sf::RenderWindow& window);
private:
    sf::Texture p_backgroundTexture;
    sf::Sprite p_background;
};

