#include "ScreenTitle.h"

TitleScreen::TitleScreen()
{
    // Load bg image
    for (int i = 1; i <= 8; i++)
    {
        sf::Texture background_frame;
        std::string fileName = "resources/images/title_screen/background_frames/background" + std::to_string(i) + ".jpg";

        if (!background_frame.loadFromFile(fileName))
            std::cout << "Cannot load " << fileName << std::endl;
        else
            p_backgroundFrames.push_back(background_frame);
    }

    // Load title and subtitle image
    if (!p_titleTexture.loadFromFile("resources/images/title_screen/title.png"))
        std::cout << "Cannot load " << "title.png" << std::endl;
    else
        p_title.setTexture(p_titleTexture);
    p_title.setRotation(-60);

    if (!p_subtitleTexture.loadFromFile("resources/images/title_screen/subtitle.png"))
        std::cout << "Cannot load " << "subtitle.png" << std::endl;
    else
        p_subtitle.setTexture(p_subtitleTexture);


    // Load and play bg music
    if (!p_backgroundMusic.openFromFile("resources/audios/background_title.mp3"))
    {
        std::cout << "Cannot load audio.wav" << std::endl;
    }
    p_backgroundMusic.setLoop(true);
    p_backgroundMusic.setVolume(25);
    p_backgroundMusic.play();


    // Load font
    p_buttonFont = std::make_shared<sf::Font>();
    if (!p_buttonFont->loadFromFile("resources/fonts/consolas.ttf"))
    {
        std::cout << "Cannot load consolas.ttf" << std::endl;
    }
}

void TitleScreen::draw(sf::RenderWindow& window)
{
    // Draw bg
    if (p_backgroundClock.getElapsedTime().asMilliseconds() >= 8000)
        p_backgroundClock.restart();

    sf::Time elapsed = p_backgroundClock.getElapsedTime();
    int idx = elapsed.asMilliseconds() / 1000;

    p_background.setTexture(p_backgroundFrames[idx]);
    window.draw(p_background);

    window.draw(p_subtitle);
    window.draw(p_title);

    // Draw buttons
    for (auto& button : p_buttons)
    {
        button.draw(window);
    }
}

void TitleScreen::handleInput(const sf::Event& event, sf::RenderWindow& window)
{
    // Handle resizing
    if (event.type == sf::Event::Resized)
    {
        handleResize(window);
    }

    // Handle button inputs
    for (auto& button : p_buttons)
    {
        button.handleEvent(event, window);
    }
}

// This should always be called once at the start
void TitleScreen::handleResize(sf::RenderWindow& window)
{
    sf::FloatRect visibleArea(0, 0, window.getSize().x, window.getSize().y);
    window.setView(sf::View(visibleArea));

    // Position title and subtitle
    p_title.setPosition(getPosition(0, 80, window));
    p_subtitle.setPosition(getPosition(5, 50, window));

    // Re-position buttons
    p_buttons.clear();

    p_buttons.emplace_back("Main Menu", sf::Color(108, 162, 91), p_buttonFont, 24, getPosition(75, 33, window), getSize(20, 10, window), 50);
    p_buttons.emplace_back("Customize Profile", sf::Color(91, 143, 162), p_buttonFont, 24, getPosition(75, 50, window), getSize(20, 10, window), 50);
    p_buttons.emplace_back("Settings", sf::Color(162, 110, 91), p_buttonFont, 24, getPosition(75, 66, window), getSize(20, 10, window), 50);
}
