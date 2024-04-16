#include "Button.h"

Button::Button(const std::string& label, sf::Color button_color, std::shared_ptr<sf::Font> font, unsigned int fontSize, const sf::Vector2f& position, const sf::Vector2f& size, float radius, sf::Color text_color) :
    p_color(button_color), p_font(font), p_isHovered(false)
{
    // Initialize text
    p_text.setFont(*p_font);
    p_text.setString(label);
    p_text.setCharacterSize(fontSize);
    p_text.setFillColor(text_color);
    p_text.setPosition(position + sf::Vector2f((size.x - p_text.getLocalBounds().width) / 2, (size.y - p_text.getLocalBounds().height) / 2));

    p_buildButtonShape(position, size, radius);

    // Load button audios
    if (!p_buttonHoverBuffer.loadFromFile("resources/audios/button_hover.wav"))
    {
        std::cout << "Cannot load audio.wav" << std::endl;
    }

    if (!p_buttonClickBuffer.loadFromFile("resources/audios/button_click.wav"))
    {
        std::cout << "Cannot load audio.wav" << std::endl;
    }
}

void Button::draw(sf::RenderWindow& window)
{
    for (auto& rectangle : p_rectangles)
        window.draw(rectangle);

    for (auto& corner : p_corners)
        window.draw(corner);

    window.draw(p_text);
}

void Button::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{
    if (event.type == sf::Event::MouseMoved)
    {
        bool collided = false;

        for (auto& rectangle : p_rectangles)
            if (rectangle.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                collided = true;

        for (auto& corner : p_corners)
            if (corner.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                collided = true;

        if (collided)
        {
            if (!p_isHovered)
            {
                p_buttonHover.setBuffer(p_buttonHoverBuffer);
                p_buttonHover.play();
            }

            for (auto& rectangle : p_rectangles)
                rectangle.setFillColor(sf::Color(std::min(p_color.r + 50, 255), std::min(p_color.g + 50, 255), std::min(p_color.b + 50, 255), p_color.a));

            for (auto& corner : p_corners)
                corner.setFillColor(sf::Color(std::min(p_color.r + 50, 255), std::min(p_color.g + 50, 255), std::min(p_color.b + 50, 255), p_color.a));

            p_isHovered = true;

        }
        else
        {
            for (auto& rectangle : p_rectangles)
                rectangle.setFillColor(p_color);

            for (auto& corner : p_corners)
                corner.setFillColor(p_color);

            p_isHovered = false;
        }
    }

    if (event.type == sf::Event::MouseButtonPressed && p_isHovered)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            std::cout << "Button " << p_text.getString().toAnsiString() << " pressed!" << std::endl;
            
            p_buttonClick.setBuffer(p_buttonClickBuffer);
            p_buttonClick.play();

            if (onClick)
            {
                onClick();
                screenChanged = true;
            }
        }
    }
}

void Button::p_buildButtonShape(const sf::Vector2f& position, const sf::Vector2f& size, float radius)
{
    // Create the top and bottom
    p_rectangles.push_back(sf::RectangleShape(sf::Vector2f(size.x - 2 * radius, size.y)));
    p_rectangles.back().setPosition(position.x + radius, position.y);
    p_rectangles.back().setFillColor(p_color);

    // Create the left and right
    p_rectangles.push_back(sf::RectangleShape(sf::Vector2f(size.x, size.y - 2 * radius)));
    p_rectangles.back().setPosition(position.x, position.y + radius);
    p_rectangles.back().setFillColor(p_color);

    // Create the corner circles

    for (int i = 0; i < 4; ++i)
    {
        p_corners.push_back(sf::CircleShape(radius));
        p_corners.back().setFillColor(p_color);
        p_corners.back().setPointCount(30);
    }

    // Set the position of the corners
    p_corners[0].setPosition(position.x, position.y);
    p_corners[1].setPosition(position.x + size.x - 2 * radius, position.y);
    p_corners[2].setPosition(position.x, position.y + size.y - 2 * radius);
    p_corners[3].setPosition(position.x + size.x - 2 * radius, position.y + size.y - 2 * radius);

}

