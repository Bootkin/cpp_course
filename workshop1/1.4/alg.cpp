#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

// Создаем структуру Спрайт, которая состоит из:
struct Sprite
{
    //Текстуры
    //Спрайта
    //Позиции
};

// Инициализируем указатель и котенка
void init()
{
}

// Опрашиваем и обрабатываем доступные события в цикле.
void pollEvents()
{
}

// Обновляем позицию и масштаб котенка
void update()
{
}

// Рисуем и выводим один кадр
void redrawFrame()
{
}

// Основная часть программы
int main()
{
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "Kitten follows laser");

    while (window.isOpen())
    {
        pollEvents();
        update();
        redrawFrame();
    }
}