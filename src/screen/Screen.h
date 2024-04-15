#pragma once

#include <SFML/Graphics.hpp>


class Screen
{
public:
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void handleInput(const sf::Event& event, sf::RenderWindow& window) = 0;
private:

};
