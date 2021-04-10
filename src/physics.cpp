//
// Created by loganj on 4/9/21.
//
#include "physics.h"

void gravity(sf::RectangleShape &rect, sf::Time t, float x)
{
    // gravity occurs along the y-axis
    auto new_pos = static_cast<float>((0.5)*(9.8)*t.asSeconds());
    rect.setPosition(x, new_pos);
}
