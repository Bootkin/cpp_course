#include <SFML/Graphics.hpp>

void init(sf::Texture &texture, sf::Sprite &sprite)
{
    texture.loadFromFile("./cat.png");

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 38, 35));
    sprite.setPosition(381, 283);
}

void pollEvent(sf::RenderWindow &window, sf::Sprite &sprite)
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
        window.draw(sprite);
        window.display();
    }
}

int main()
{
    sf::Texture texture;
    sf::Sprite sprite;

    init(texture, sprite);

    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "Kitten");

    pollEvent(window, sprite);
}