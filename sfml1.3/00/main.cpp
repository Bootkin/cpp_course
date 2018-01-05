#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({700, 600}), "House");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({300, 200});
    shape1.setPosition({200, 300});
    shape1.setFillColor(sf::Color(139, 69, 19));
    window.draw(shape1);

    sf::RectangleShape shape2;
    shape2.setSize({70, 150});
    shape2.setPosition({230, 350});
    shape2.setFillColor(sf::Color(70, 70, 70));
    window.draw(shape2);

    sf::ConvexShape shape3;
    shape3.setFillColor(sf::Color(128, 0x0, 0x0));
    shape3.setPosition({350, 200});
    shape3.setPointCount(4);
    shape3.setPoint(0, {-75, 0});
    shape3.setPoint(1, {+75, 0});
    shape3.setPoint(2, {+190, 100});
    shape3.setPoint(3, {-190, 100});
    window.draw(shape3);

    sf::RectangleShape shape4;
    shape4.setSize({20, 40});
    shape4.setPosition({410, 185});
    shape4.setFillColor(sf::Color(90, 90, 90));
    window.draw(shape4);

    sf::RectangleShape shape5;
    shape5.setSize({40, 25});
    shape5.setPosition({400, 165});
    shape5.setFillColor(sf::Color(90, 90, 90));
    window.draw(shape5);

    sf::CircleShape shape6(10);
    shape6.setPosition({420, 150});
    shape6.setFillColor(sf::Color(120, 120, 120));
    window.draw(shape6);

    sf::CircleShape shape7(13);
    shape7.setPosition({425, 131});
    shape7.setFillColor(sf::Color(120, 120, 120));
    window.draw(shape7);

    sf::CircleShape shape8(17);
    shape8.setPosition({430, 110});
    shape8.setFillColor(sf::Color(120, 120, 120));
    window.draw(shape8);

    sf::CircleShape shape9(22);
    shape9.setPosition({435, 85});
    shape9.setFillColor(sf::Color(120, 120, 120));
    window.draw(shape9);

    window.display();

    sf::sleep(sf::seconds(10));
}