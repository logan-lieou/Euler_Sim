#include <SFML/Graphics.hpp>
#include <vector>

void updateShape(sf::RectangleShape &rect, sf::Vector2f pos) {
	rect.setPosition(pos);
}

int main() 
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Euler Fluid Simulation");
	const sf::Vector2f &size = sf::Vector2f(50.f, 50.f);
	sf::RectangleShape shape(size);
	shape.setFillColor(sf::Color::White);

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
			shape.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		window.clear();
		window.draw(shape);
		window.display();
	}
}
