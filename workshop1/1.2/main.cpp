#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

void init(sf::ConvexShape &point)
{
    point.setFillColor(sf::Color(255, 255, 0));
    point.setOutlineColor(sf::Color(0, 0, 0));
    point.setOutlineThickness(3);

    point.setPosition({400, 300});
    point.setPointCount(7);
    point.setPoint(0, {+100, 0});
    point.setPoint(1, {0, -100});
    point.setPoint(2, {0, -50});
    point.setPoint(3, {-100, -50});
    point.setPoint(4, {-100, +50});
    point.setPoint(5, {0, +50});
    point.setPoint(6, {0, +100});
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;

    mousePosition = {float(event.x), float(event.y)};
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

void update(const sf::Vector2f &mousePosition, sf::ConvexShape &point, float deltaTime)
{
    const float AngularSpeed = 90;
    const float LinearSpeed = 20;
    const sf::Vector2f delta = mousePosition - point.getPosition();
    float angle = atan2(delta.y, delta.x);
    if (angle < 0)
    {
        angle += 2 * M_PI;
    }

    const float pointRotation = point.getRotation();
    const float mouseRotation = toDegrees(angle);
    const float maxRotation = AngularSpeed * deltaTime;
    float Rotation = std::min(std::abs(mouseRotation - maxRotation), maxRotation);
    if (mouseRotation < pointRotation)
    {
        if ((mouseRotation + 180) < pointRotation)
        {
            point.setRotation(pointRotation + Rotation);
        }
        else
        {
            point.setRotation(pointRotation - Rotation);
        }
    }
    else
    {
        if ((mouseRotation - 180) > pointRotation)
        {
            point.setRotation(pointRotation - Rotation);
        }
        else
        {
            point.setRotation(pointRotation + Rotation);
        }
    }

    const float deltaMod = std::hypot(delta.x, delta.y);
    const float PotentialMove = LinearSpeed * deltaTime;
    const sf::Vector2f direction = {delta.x / deltaMod, delta.y / deltaMod};

    sf::Vector2f pointPosition = point.getPosition();

    if (deltaMod != 0)
    {
        pointPosition += direction * std::min(PotentialMove, deltaMod);
    }

    point.setPosition(pointPosition);
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &point)
{
    window.clear(sf::Color(255, 255, 255));
    window.draw(point);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Point follows mouse");
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