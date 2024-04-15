#include "Extra.h"

sf::Vector2f getSize(float xPercent, float yPercent, const sf::RenderWindow& window)
{
	return sf::Vector2f(window.getSize().x * (xPercent / 100.0f), window.getSize().y * (yPercent / 100.0f));
}

sf::Vector2f getPosition(float xPercent, float yPercent, const sf::RenderWindow& window)
{
	return sf::Vector2f(window.getSize().x * (xPercent / 100.0f), window.getSize().y * (yPercent / 100.0f));
}
