#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({200, 600}), "traffic light");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({200, 600});
    shape1.setPosition({0, 0});
    shape1.setFillColor(sf::Color(192, 192, 192));
    window.draw(shape1);

    sf::CircleShape shape2(90);
    shape2.setPosition({10, 10});
    shape2.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape2);

    sf::CircleShape shape3(90);
    shape3.setPosition({10, 210});
    shape3.setFillColor(sf::Color(255, 255, 0x0));
    window.draw(shape3);

    sf::CircleShape shape4(90);
    shape4.setPosition({10, 410});
    shape4.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape4);

    window.display();

    sf::sleep(sf::seconds(5));
}