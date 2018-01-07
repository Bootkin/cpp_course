#include <SFML/Graphics.hpp>
#include <cmath>

// Создаем структуру Спрайт, которая состоит из:
struct Sprite
{
    //Текстуры
    sf::Texture texture;
    //Спрайта
    sf::Sprite sprite;
    //Позиции
    sf::Vector2f position = {400, 300};
};

// Инициализируем указатель и котенка
void init(Sprite &point, Sprite &kitten)
{
    point.texture.loadFromFile("./red_pointer.png");
    point.sprite.setTexture(point.texture);
    point.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    point.sprite.setPosition(point.position);
    point.sprite.setOrigin(16, 16);

    kitten.texture.loadFromFile("./cat.png");
    kitten.sprite.setTexture(kitten.texture);
    kitten.sprite.setTextureRect(sf::IntRect(0, 0, 38, 35));
    kitten.sprite.setPosition(kitten.position);
    kitten.sprite.setOrigin(19, 17.5);
}

// Опрашиваем и обрабатываем доступные события в цикле.
void pollEvents(sf::RenderWindow &window, Sprite &point, bool &mouseButtonPressed)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            point.sprite.setPosition(event.mouseButton.x, event.mouseButton.y);
            point.position = {point.sprite.getPosition()};
            mouseButtonPressed = true;
            break;
        default:
            break;
        }
    }
}

// Обновляем позицию и масштаб котенка
void update(Sprite &point, Sprite &kitten, float deltaTime)
{
    const float speed = 200;
    const float potentialMove = speed * deltaTime;
    const sf::Vector2f delta = point.position - kitten.position;
    const float deltaMod = std::hypot(delta.x, delta.y);

    if (deltaMod != 0)
    {
        const sf::Vector2f direction = {delta.x / deltaMod, delta.y / deltaMod};
        kitten.position += direction * std::min(potentialMove, deltaMod);
    }

    if (delta.x < 0)
    {
        kitten.sprite.setScale(-1, 1);
    }
    else
    {
        kitten.sprite.setScale(1, 1);
    }

    kitten.sprite.setPosition(kitten.position);
}

// Рисуем и выводим один кадр
void redrawFrame(sf::RenderWindow &window, Sprite &point, Sprite &kitten, bool &mouseButtonPressed)
{
    window.clear(sf::Color(255, 255, 255));
    if (mouseButtonPressed == true)
    {
        window.draw(point.sprite);
    }
    //window.draw(point.sprite);
    window.draw(kitten.sprite);
    window.display();
}

// Основная часть программы
int main()
{
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "Kitten follows laser");

    sf::Clock clock;

    Sprite kitten;
    Sprite point;

    init(point, kitten);

    // Создаем логическую переменную на проверку первого нажатия мыши
    bool mouseButtonPressed = false;

    while (window.isOpen())
    {
        pollEvents(window, point, mouseButtonPressed);
        const float deltaTime = clock.restart().asSeconds();
        update(point, kitten, deltaTime);
        redrawFrame(window, point, kitten, mouseButtonPressed);
    }
}
