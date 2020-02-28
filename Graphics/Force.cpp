#include "Force.h"
Force::Force(float newtons, float radians) {
	AddForce(newtons, radians);
}

Force& Force::AddForce(Force force) {
	return this->AddForce(force.newtons);
}
Force& Force::AddForce(float newtons, float radians) {
	float xnewtons = sin(radians) * newtons;
	float ynewtons = cos(radians) * newtons;
	return this->AddForce(sf::Vector2f(xnewtons, ynewtons));
}
Force& Force::AddForce(sf::Vector2f force) {
	this->newtons += force;
	
	float x = this->newtons.x;
	float y = this->newtons.y;

	this->magnitude = sqrt(pow(x, 2) + pow(y, 2));
	this->radians = atan(x/y);

	return *this;
}

sf::Vector2f Force::GetVelocity(float mass) {
	sf::Vector2f vel = newtons / mass;
	return vel;
}
