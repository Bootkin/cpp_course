#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;
    constexpr float BALL_SIZE = 40;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Wafe bouncing ball");
    sf::Clock clock;

    sf::CircleShape ball(BALL_SIZE);
    ball.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    const sf::Vector2f position = {0, 350};
    float speedX = 100.f;

    float time = 0;
    float x = 0;

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

        constexpr float amplitudeY = 80.f;
        constexpr float periodY = 2;

        const float dt = clock.restart().asSeconds();

        const float wafePhase = time * float(2 * M_PI);
        const float y = amplitudeY * std::sin(wafePhase / periodY);
        x += speedX * dt;

        const sf::Vector2f offset = {x, y};

        time += dt;

        ball.setPosition(position + offset);

        if (x + 2 * BALL_SIZE >= WINDOW_WIDTH)
        {
            speedX = -speedX;
        }
        if (x <= 0)
        {
            speedX = -speedX;
        }

        window.clear();
        window.draw(ball);
        window.display();
    }
}