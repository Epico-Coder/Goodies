#include "MenuScreen.h"

MenuScreen::MenuScreen()
{
	// Load bg image
	if (!p_backgroundTexture.loadFromFile("resources/images/menu_screen/background.jpg"))
		std::cout << "Cannot load background.jpg" << std::endl;
	else
		p_background.setTexture(p_backgroundTexture);

	// Load font
	p_buttonFont = std::make_shared<sf::Font>();
	if (!p_buttonFont->loadFromFile("resources/fonts/consolas.ttf"))
		std::cout << "Cannot load consolas.ttf" << std::endl;

	// Initialize title text
	p_title.setFont(*p_buttonFont);
	p_title.setString("Menu");
	p_title.setCharacterSize(60);
	p_title.setFillColor(sf::Color::White);
}

void MenuScreen::init(sf::RenderWindow& window)
{
	handleResize(window);
}

void MenuScreen::unScreen()
{
}

void MenuScreen::draw(sf::RenderWindow& window)
{
	// Draw bg
	window.draw(p_background);

	// Draw title
	window.draw(p_title);

	// Draw buttons
	for (auto& button : p_buttons)
	{
		button.draw(window);
	}
}

void MenuScreen::update(sf::Time deltaTime)
{
	for (auto& button : p_buttons)
	{
		if ((button.getIsClicked()) && (button.getLinkedObject().size()))
		{
			ScreenManager::getInstance().setScreen(button.getLinkedObject());
			break;
		}
	}
}

void MenuScreen::handleInput(const sf::Event& event, sf::RenderWindow& window)
{
	// Handle button inputs
	for (auto& button : p_buttons)
	{
		button.handleInput(event, window);
	}
}

void MenuScreen::handleResize(sf::RenderWindow& window)
{
	sf::Vector2u windowSize = window.getSize();
	float titleHeight = p_title.getLocalBounds().height + 20;

	int rows = 3;
	int cols = 5;

	// Calculate button positions
	float spacingX = windowSize.x / 50.0f;
	float spacingY = windowSize.y / 25.0f;
	float paddingX = windowSize.x / 40.0f;
	float paddingY = windowSize.y / 20.0f;
	float buttonWidth = (windowSize.x - (paddingX * 2) - (spacingX * cols)) / float(cols);
	float buttonHeight = (windowSize.y - (paddingY * 2) - (spacingY * rows) - titleHeight) / float(rows);

	p_buttons.clear();
	for (int i = 0; i < (rows * cols); ++i)
	{
		int row = i / cols;
		int col = i % cols;

		std::cout << "Row: " << row << ", Column: " << col << std::endl;
		std::cout << paddingX + (col * (buttonWidth + spacingX)) << ", " << paddingY + titleHeight + (row * (buttonHeight + spacingY)) << std::endl;

		sf::Vector2f position(paddingX + (col * (buttonWidth + spacingX)), paddingY + titleHeight + (row * (buttonHeight + spacingY)));
		sf::Vector2f size(buttonWidth, buttonHeight);

		p_buttons.emplace_back("Game " + std::to_string(i + 1), sf::Color(108, 162, 91), p_buttonFont, 24, position, size, 10);
		p_buttons.back().linkObj("GameScreen" + std::to_string(i + 1));
	}

	p_title.setPosition((windowSize.x - p_title.getLocalBounds().width) / 2, 10);
}
