#include "ScreenManager.h"


ScreenManager* ScreenManager::p_instance = nullptr;


ScreenManager& ScreenManager::getInstance()
{
    if (p_instance == nullptr)
    {
        p_instance = new ScreenManager();
    }
    return *p_instance;
}


void ScreenManager::setWin(sf::RenderWindow* win)
{
    p_win = win;
}

void ScreenManager::addScreen(const std::string& name, std::unique_ptr<Screen> screen)
{
    p_screens[name] = std::move(screen);
}

void ScreenManager::setScreen(std::string screenName)
{
    if (p_currentScreen)
    {
        p_currentScreen->unScreen();
    }

    auto it = p_screens.find(screenName);
    if (it != p_screens.end()) 
    {
        p_currentScreen = it->second.get();
        p_currentScreen->init(*p_win);

        std::cout << "NEW SCREEN: " << screenName << std::endl;
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
