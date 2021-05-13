#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include <vector>
#include "physics.hpp"
#define SCALE 8

int main()
{
    // main window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Euler Fluid Simulation");
    // time for physics
    sf::Clock clock; sf::Time t;

    // man where's the constructor?
    sf::RectangleShape rect;
    rect.setFillColor(sf::Color::White);
    rect.setSize(sf::Vector2f{50.f, 50.f});

    while(window.isOpen())
    {
        sf::Event event{};

        // handling events
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // basic setup
        window.draw(rect);
        window.display();
    }
}
