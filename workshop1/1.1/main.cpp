#include <SFML/Graphics.hpp>

void init(sf::ConvexShape &point)
{
    point.setFillColor(sf::Color(255, 255, 0));
    point.setOutlineColor(sf::Color(0, 0, 0));
    point.setOutlineThickness(3);

    point.setPosition({400, 200});
    point.setPointCount(7);
    point.setPoint(0, {0, 0});
    point.setPoint(1, {-100, +100});
    point.setPoint(2, {-50, +100});
    point.setPoint(3, {-50, +200});
    point.setPoint(4, {+50, +200});
    point.setPoint(5, {+50, +100});
    point.setPoint(6, {+100, +100});
}

void pollEvent(sf::RenderWindow &window, sf::ConvexShape &point)
{
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

        window.clear(sf::Color(255, 255, 255));
        window.draw(point);
        window.display();
    }
}

int main()
{
    sf::ConvexShape point;

    init(point);

    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "Pointer");

    pollEvent(window, point);
}