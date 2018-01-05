#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>

int main()
{
    constexpr int pointCount = 500;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({800, 600}), "Polar Rose",
        sf::Style::Default, settings);

    sf::ConvexShape PolarRose;
    PolarRose.setFillColor(sf::Color(0x00, 0x00, 0xFF));

    float angle2 = 0;

    PolarRose.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            200 * std::sin(6 * angle) * std::sin(angle),
            200 * std::sin(6 * angle) * std::cos(angle)};
        PolarRose.setPoint(pointNo, point);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        const float x = 100 * std::cos(angle2) + 400;
        const float y = 100 * std::sin(angle2) + 300;
        PolarRose.setPosition({x, y});

        angle2 += 0.0005;

        window.clear();
        window.draw(PolarRose);
        window.display();
    }
}