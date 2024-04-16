#include "ScreenManager.h"


ScreenManager::ScreenManager()
{
}



void ScreenManager::onNotify(const std::string& event, const std::string& data)
{
    if (event == "ButtonClicked") 
    {
        std::cout << data << std::endl;
        setScreen(data);
    }
}

void ScreenManager::setScreen(std::unique_ptr<Screen> screen)
{
    p_currentScreen.release();
    p_currentScreen = std::move(screen);
}

void ScreenManager::setScreen(std::string screenName)
{
    if (screenName == "TITLE")
    {
        setScreen(std::make_unique<TitleScreen>(this));
    }
    else if (screenName == "MenuScreen")
    {
        setScreen(std::make_unique<MenuScreen>());
    }
}

void ScreenManager::handleInput(const sf::Event& event, sf::RenderWindow& window)
{
    if (p_currentScreen)
    {
        p_currentScreen->handleInput(event, window);
    }
}

void ScreenManager::update(sf::Time deltaTime)
{
    if (p_currentScreen)
    {
        p_currentScreen->update(deltaTime);
    }
}

void ScreenManager::draw(sf::RenderWindow& window)
{
    if (p_currentScreen)
    {
        p_currentScreen->draw(window);
    }
}

void ScreenManager::handleResize(sf::RenderWindow& window)
{
    if (p_currentScreen)
    {
        p_currentScreen->handleResize(window);
    }
}
