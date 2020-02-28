#pragma once
#define _USE_MATH_DEFINES
#include <cmath> 
#include <SFML/System/Vector2.hpp>

class Force
{
public:
	Force() = default;
	Force(float newtons, float radians);

	Force& AddForce(float newtons, float radians);
	Force& AddForce(sf::Vector2f force);
	Force& AddForce(Force force);

	sf::Vector2f GetVelocity(float mass);
private:
	sf::Vector2f newtons;
	float radians = 0;
	float magnitude = 0;
};

