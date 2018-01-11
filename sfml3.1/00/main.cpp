#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

void init(sf::ConvexShape &point)
{
    point.setPointCount(3);
    point.setPoint(0, {50, 0});
    point.setPoint(1, {-30, -30});
    point.setPoint(2, {-30, 30});
    point.setPosition({400, 300});
    point.setFillColor(sf::Color(0xFF, 0x80, 0x00));
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x =" << event.x << ", y =" << event.y << std::endl;

    mousePosition = {float(event.x), float(event.y)};
}

void update(const sf::Vector2f &mousePosition, sf::ConvexShape &point, float deltaTime)
{
    const sf::Vector2f delta = mousePosition - point.getPosition();
    float angle = atan2(delta.y, delta.x);

    if (angle < 0)
    {
        angle += 2 * M_PI;
    }

    const float mouseRotation = toDegrees(angle);
    const float maxRotation = deltaTime * 15;

    float Degr = std::min(std::abs(mouseRotation - maxRotation), maxRotation);
    if (mouseRotation > point.getRotation())
    {
        if ((mouseRotation - 180) > point.getRotation())
        {
            point.setRotation(point.getRotation() - Degr);
        }
        else
        {
            point.setRotation(point.getRotation() + Degr);
        }
    }
    else
    {
        if ((mouseRotation + 180) < point.getRotation())
        {
            point.setRotation(point.getRotation() + Degr);
        }
        else
        {
            point.setRotation(point.getRotation() - Degr);
        }
    }
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &point)
{
    window.clear();
    window.draw(point);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Arrow follows mouse", sf::Style::Default, settings);
    sf::Clock clock;

    sf::ConvexShape point;
    sf::Vector2f mousePosition;

    init(point);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        const float deltaTime = clock.restart().asSeconds();
        update(mousePosition, point, deltaTime);
        redrawFrame(window, point);
    }
}