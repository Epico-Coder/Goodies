#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "Screen.h"
#include "../systems/ScreenManager.h"
#include "../utility/Button.h"
#include "../utility/Extra.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class TitleScreen : public Screen
{
public:
    TitleScreen();
    void init(sf::RenderWindow& window);
    void unScreen();
    void draw(sf::RenderWindow& window);
    void update(sf::Time delaTime);
    void handleInput(const sf::Event& event, sf::RenderWindow& window);
    void handleResize(sf::RenderWindow& window);
private:
    std::vector<sf::Texture> p_backgroundFrames;
    sf::Sprite p_background;
    sf::Clock p_backgroundClock;
    sf::Music p_backgroundMusic;

    sf::Texture p_titleTexture;
    sf::Sprite p_title;

    sf::Texture p_subtitleTexture;
    sf::Sprite p_subtitle;

    std::vector<Button> p_buttons;
    std::shared_ptr<sf::Font> p_buttonFont;
};
