//
// Created by loganj on 4/9/21.
//

#ifndef EULER_SIM_PHYSICS_H
#define EULER_SIM_PHYSICS_H

// deps
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

// position something something another
int IX(int x, int y, int N);

// applying gravity since 13799997979 B.C.
void gravity(sf::RectangleShape &rect, sf::Time t, sf::Vector2f pos);

// direction gradient
sf::Vector2f direction(sf::RectangleShape rect, sf::Time t);

// velocity diff
sf::Vector2f velocity(sf::RectangleShape rect, sf::Time t);

// dot product
float dot(sf::Vector2f a, sf::Vector2f b);

// incompressibility condition
void incompressibility_condition(std::vector<float> u);

#endif //EULER_SIM_PHYSICS_H
