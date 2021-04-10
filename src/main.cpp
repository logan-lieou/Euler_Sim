#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include <vector>
#include "physics.hpp"
#define SCALE 8

// WIP
void Render(sf::RenderWindow &win, int size) {
    win.clear();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sf::RectangleShape rect;
            rect.setSize(sf::Vector2f(SCALE, SCALE));
            rect.setPosition(j * SCALE, i * SCALE);
            rect.setFillColor(sf::Color(255, 255, 255, 255));
            win.draw(rect);
        }
    }
}

sf::RectangleShape SpawnParticle(sf::RenderWindow &window, sf::Vector2f pos, sf::Time t)
{
  sf::RectangleShape rect; // init rect
  rect.setSize(sf::Vector2f(8.f, 8.f)); // 8x8 px's
  rect.setPosition(pos); // update position
  rect.setFillColor(sf::Color::White); // fill color is white
  gravity(rect, t, pos);
  window.draw(rect); // draw rectangle to the window
  return rect;
}

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Euler Fluid Simulation");
  sf::Clock clock; sf::Time t;
  std::vector<sf::RectangleShape> rects;
  std::vector<sf::RectangleShape>::iterator i = rects.begin();

  while(window.isOpen())
  {
		sf::Event event;

		// handling events
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

    t = clock.getElapsedTime();

		// if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			// shape.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));

	  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	    rects.insert(i, SpawnParticle(window, static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)), t));
      i += 1;
    
    for (int j = 0; j < rects.size(); j++)
    {
      gravity(rects.at(j), t, rects.at(j).getPosition());
    }

		window.display();
	}
}
