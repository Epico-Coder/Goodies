#include "MenuScreen.h"

MenuScreen::MenuScreen()
{
	if (!p_backgroundTexture.loadFromFile("resources/images/menu_screen/background1.jpg"))
		std::cout << "Cannot load " << "background.jpg" << std::endl;
	else
		p_background.setTexture(p_backgroundTexture);
}

void MenuScreen::draw(sf::RenderWindow& window)
{
	// Draw bg
	window.draw(p_background);
}

void MenuScreen::update(sf::Time deltaTime)
{
}

void MenuScreen::handleInput(const sf::Event& event, sf::RenderWindow& window)
{
}

void MenuScreen::handleResize(sf::RenderWindow& window)
{
}
