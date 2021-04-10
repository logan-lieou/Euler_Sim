#include <SFML/Graphics.hpp>
#include <iostream>
#define SCALE 5
#include "physics.h"

void Render(sf::RenderWindow &win, int size) {
    win.clear();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sf::RectangleShape rect;
            rect.setSize(sf::Vector2f(SCALE, SCALE));
            rect.setPosition(j * SCALE, i * SCALE);
            rect.setFillColor(sf::Color::Red);
            win.draw(rect);
        }
    }
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Euler Fluid Simulation");
	const sf::Vector2f &size = sf::Vector2f(5.f, 5.f);
	sf::RectangleShape shape(size);
	shape.setFillColor(sf::Color::White);

    sf::Clock clock;
    sf::Time delta_t;
    float y;

	while(window.isOpen())
	{
		sf::Event event;

		// handling events
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// for physics
        delta_t = clock.getElapsedTime();

        Render(window, 50);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
			shape.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		window.clear();
		window.draw(shape);
		window.display();
	}
}
