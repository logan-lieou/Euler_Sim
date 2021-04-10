//
// Created by loganj on 4/9/21.
//
#include "physics.hpp"

void gravity(sf::RectangleShape &rect, sf::Time t, sf::Vector2f pos)
{
  auto new_pos = pos.y += static_cast<float>((0.5)*(9.8)*t.asSeconds());
  rect.setPosition(pos.x, new_pos);
}

int IX(int x, int y, int N)
{
  (x < 0) ? x=0 : x=x;
  (x > N-1) ? x=N-1 : x=x;
  (y < 0) ? y=0 : y=y;
  (y > N-1) ? y=N-1 : y=y;

  return (y*N) + x;
}
