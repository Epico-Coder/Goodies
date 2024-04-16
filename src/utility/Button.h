#pragma once

#include <string>
#include <iostream>
#include <memory>
#include <cmath>
#include <functional>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Button
{
public:
    Button(const std::string& label, sf::Color button_color, std::shared_ptr<sf::Font> font, unsigned int fontSize, const sf::Vector2f& position, const sf::Vector2f& size, float radius = 0, sf::Color text_color = sf::Color::White);
    void draw(sf::RenderWindow& window);
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
public:
    std::function<void()> onClick;
    bool screenChanged = false;
private:
    void p_buildButtonShape(const sf::Vector2f& position, const sf::Vector2f& size, float radius);
private:
    sf::Color p_color;
    std::shared_ptr<sf::Font> p_font;
    sf::Text p_text;
    std::vector<sf::RectangleShape> p_rectangles;
    std::vector<sf::CircleShape> p_corners;
    sf::SoundBuffer p_buttonHoverBuffer;
    sf::Sound p_buttonHover;
    sf::SoundBuffer p_buttonClickBuffer;
    sf::Sound p_buttonClick;
    bool p_isHovered;
};

