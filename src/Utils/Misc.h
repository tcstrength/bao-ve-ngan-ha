#ifndef MISC_H
#define MISC_H

#include <iostream>
#include <assert.h>
#include <cmath>
#include <SFML/Graphics.hpp>

const float PI = static_cast<float>(std::acos(-1));

const float RAD_UNIT = PI/190;

int randBetween(int min, int max);

float randf();

float deg2Rad(float deg);

float rad2Deg(float rad);

float sfDeg2Deg(float sfAngle);

float deg2sfDeg(float angle);

sf::Vector2f polarProjection(const sf::Vector2f& pos, const float& dist,const float& rad);

float radBetween2Vec(const sf::Vector2f& src, const sf::Vector2f& dst);
#endif // MISC_H
