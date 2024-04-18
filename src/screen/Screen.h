#pragma once

#include <SFML/Graphics.hpp>


class Screen
{
public:
	virtual ~Screen() = default;
	virtual void init(sf::RenderWindow& window) = 0;
	virtual void unScreen() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update(sf::Time deltaTime) = 0;
	virtual void handleInput(const sf::Event& event, sf::RenderWindow& window) = 0;
	virtual void handleResize(sf::RenderWindow& window) = 0;
private:
};
