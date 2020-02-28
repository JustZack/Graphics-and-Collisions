#include "Object.h"
#include <math.h>
#include <iostream>
#include "UtilityMethods.h"
#define _USE_MATH_DEFINES 


void Object::Init(float X, float Y, float Mass, float Width, float Height)
{
	uID = Object::ObjectCount++;
	setPosition(X, Y);
	mass(Mass);
	setDimensions(Width, Height);
	SetBounds();


	float f = .0f;
	xSpeed(f);
	ySpeed(f);

	f = .5f;
	bounciness(f);
	coefficientOfFriction(f);

	trailTimeInterval(f - .25f);

	m_shape.setSize(size());
	SetShapePosition(pos());
	m_shape.setFillColor(color());

	m_accelerationShape.setFillColor(sf::Color::Red);
}
Object::Object()
{
	float f = 10.f;
	Init(f, f, f, f, f);
}
Object::Object(float X, float Y, float Mass, float Width, float Height)
{
	Init(X, Y, Mass, Width, Height);
}

int Object::UID() {
	return this->uID;
}

void Object::CollideWith(Object* other) {
	//Collisions dont matter if the object cant be moved
	if (!this->isMoveable()) return;

	Collision newCollision = Collision(this, other);
	
	//ensure duplicate collisions are not added
	for (Collision c : this->collisions)
		if (c.Equals(newCollision))
			return;

	this->collisions.push_back(Collision(this, other));
}

void Object::ApplyCollisions() {
	Force result;
	for (Collision c : this->collisions) {
		result.AddForce(c.ComputeForce());
	}
	this->ApplyForce(result);

}

void Object::Update(float frameTime, float g)
{
	Update_Position(frameTime, g);
	Update_Acceleration();
	Update_PopulateTrail(frameTime);
	//WindowEdgeCollisionCheck();
}
void Object::Update_Position(float frameTime, float g)
{
	//Check if the object is affected by gravity...
	if (!isAffectedByGravity())
	{
		//Do not change the value of ySpeed because gravity does not act on this object.
	}
	else
	{
		//It is affected by gravity so make gravity act on it.
		ySpeed(ySpeed() + g * frameTime);
	}
	//Save temp x and y values to send to the setPosition() method afterwards.
	x(x() + xSpeed() * frameTime);
	y(y() + ySpeed() * frameTime);
	SetBounds();
	SetShapePosition(pos());
}
void Object::Update_Acceleration()
{
	//Object is moving straight down or up.
	if (abs(xSpeed()) == 0 && abs(ySpeed()) > 0)
	{
		accelerationMagnitude(ySpeed());
		//Object is moving down
		if (ySpeed() > 0)
		{
			accelerationAngle(0.f);
		}
		//Object is moving up
		else if (ySpeed() < 0)
		{
			accelerationAngle(0.f);
		}

	}
	//Object is moving straight left or right.
	else if (abs(ySpeed()) == 0 && abs(xSpeed()) > 0)
	{
		accelerationMagnitude(xSpeed());
		//Object is moving right
		if (xSpeed() > 0)
		{
			accelerationMagnitude(270.f);
		}
		//Object is moving left
		else if (xSpeed() < 0)
		{
			accelerationMagnitude(270.f);
		}
	}
	//Object is not moving at all.
	else if (abs(ySpeed()) == 0 && abs(xSpeed()) == 0)
	{
		accelerationMagnitude(0.f);
		accelerationAngle(0.f);
	}
	//Object is moving in both directions
	else if (abs(ySpeed()) > 0 && abs(xSpeed()) > 0)
	{
		//Calculate the acceleration magnitude as a vector (hypotonuse) of the x and y speed.
		accelerationMagnitude(abs(sqrt((xSpeed() * xSpeed()) + (ySpeed() * ySpeed()))));
		//Calculate the acceleration angle from the the triangle that is formed by the x and y speed.
		accelerationAngle((atan2(ySpeed(), xSpeed()) * 180 / M_PI));
		if (xSpeed() > 0 && -ySpeed() > 0)
		{
			//First quadrant
			accelerationAngle( accelerationAngle() - 90);
		}
		if (xSpeed() < 0 && -ySpeed() > 0)
		{
			//Second Quadrant
			accelerationAngle(accelerationAngle() + 270);
		}
		if (xSpeed() < 0 && -ySpeed() < 0)
		{
			//Third Quadrant
			accelerationAngle(accelerationAngle() + 270);
		}
		if (xSpeed() > 0 && -ySpeed() < 0)
		{
			//Fourth Quadrant
			accelerationAngle(accelerationAngle() + 270);
		}
	}
	if (isOnScreen())
	{
		if (showacceleration())
		{
			accelerationShape().setSize(sf::Vector2f(1.f, accelerationMagnitude()));
			accelerationShape().setRotation(accelerationAngle());
		}
	}
}
void Object::Update_PopulateTrail(float frameTime)
{
	m_tempTime_trial += frameTime;
	if (m_tempTime_trial >= m_trailTimeInterval)
	{
		m_tempTime_trial = 0.f;
		m_trail.push_back(posCenter());
	}
}

void Object::setPosition(float X, float Y)
{
	x(X);
	y(Y);
}
sf::Vector2f Object::pos()
{
	return sf::Vector2f(x(), y());
}
sf::Vector2f Object::posCenter()
{
	return sf::Vector2f(x() + (width() / 2), y() + (height() / 2));
}
float Object::x()
{
	return m_x;
}
void Object::x(float x)
{
	m_x = x;
}
float Object::y()
{
	return m_y;
}
void Object::y(float y)
{
	m_y = y;
}

float Object::mass()
{
	return m_mass;
}
void Object::mass(float mass)
{
	m_mass = mass;
}

void Object::setDimensions(float Width, float Height)
{
	width(Width);
	height(Height);
	m_shape.setSize(sf::Vector2f(width(), height()));
	m_radius = sqrt(((height() / 2) * (height() / 2)) + ((width() / 2) + (width() / 2)));

}
sf::Vector2f Object::size()
{
	return sf::Vector2f(width(), height());
}
float Object::width()
{
	return m_width;
}
void Object::width(float width)
{
	m_width = width;
}
float Object::height()
{
	return m_height;
}
void Object::height(float height)
{
	m_height = height;
}

float Object::radius()
{
	return m_radius;
}

void Object::xSpeed(float XSpeed)
{
	m_xSpeed = XSpeed;
}
float Object::xSpeed()
{
	return m_xSpeed;
}
void Object::ySpeed(float YSpeed)
{
	m_ySpeed = YSpeed;
}
float Object::ySpeed()
{
	return m_ySpeed;
}

sf::Vector2f Object::Velocity() {
	return sf::Vector2f(xSpeed(), ySpeed());
}


Force Object::GetForce() {
	return Force(mass() * accelerationMagnitude(), accelerationAngle());
}
Force Object::ApplyForce(Force force) {

}

std::string& Object::name()
{
	return m_name;
}

float Object::accelerationMagnitude()
{
	return m_accelerationMagnitude;
}
void Object::accelerationMagnitude(float mag) {
	m_accelerationMagnitude = mag;
}
float Object::accelerationAngle()
{
	return m_accelerationAngle;
}
void Object::accelerationAngle(float angle) {
	m_accelerationAngle = angle;
}
void Object::showacceleration(bool ShowAcceleration)
{
	m_showacceleration = ShowAcceleration;
}
bool Object::showacceleration()
{
	return m_showacceleration;
}

void Object::bounciness(float Bounciness)
{
	m_bounciness = Bounciness;
}
float Object::bounciness()
{
	return m_bounciness;
}

void Object::coefficientOfFriction(float CoefficientOfFriction)
{
	m_coefficientOfFriction = CoefficientOfFriction;
}
float Object::coefficientOfFriction()
{
	return m_coefficientOfFriction;
}

void Object::isAffectedByGravity(bool AffectedByGravity)
{
	m_isAffectedByGravity = AffectedByGravity;
}
bool Object::isAffectedByGravity()
{
	return m_isAffectedByGravity;
}

void Object::isMoveable(bool Moveable)
{
	m_isMoveable = Moveable;
}
bool Object::isMoveable()
{
	return m_isMoveable;
}

void Object::isOnScreen(bool OnScreen)
{
	m_isOnScreen = OnScreen;
}
bool Object::isOnScreen()
{
	return m_isOnScreen;
}

void Object::hasCollision(bool Collides)
{
	m_hasCollision = Collides;
}
bool Object::hasCollision()
{
	return m_hasCollision;
}

void Object::collisionLayer(int CollisionLayer)
{
	m_collisionLayer = CollisionLayer;
}
int Object::collisionLayer()
{
	return m_collisionLayer;
}

std::vector<sf::Vector2f> Object::gettrail()
{
	return m_trail;
}
void Object::trailTimeInterval(float TimeInterval)
{
	m_trailTimeInterval = TimeInterval;
}
float Object::trailTimeInterval()
{
	return m_trailTimeInterval;
}
void Object::setColor(sf::Color Color)
{
	color() = Color;
	m_shape.setFillColor(color());
}
sf::Color& Object::color()
{
	return m_color;
}

void Object::setTexture(sf::Texture Texture)
{
	texture() = Texture;
}
sf::Texture& Object::texture()
{
	return m_texture;
}

sf::Shape& Object::Shape()
{
	return m_shape;
}

sf::RectangleShape& Object::accelerationShape()
{
	return m_accelerationShape;
}

void Object::SetShapePosition(double x, double y) {
	SetShapePosition(sf::Vector2f(x, y));
}
void Object::SetShapePosition(sf::Vector2f pos) {
	sf::Vector2f newPos;
	if (isOnScreen()) {
		newPos = this->WorldOrigin;
		//Adjust so object 'sits' on top of origin
		newPos.y -= this->height();
		newPos.x -= this->width() / 2;
		//Change the position to the passed position
		newPos.x += pos.x;
		newPos.y -= pos.y;
	}
	else {
		//Put the object just out of view in the top left corner.
		newPos = sf::Vector2f(-width(), -height());
	}
	m_shape.setPosition(newPos);

	if (showacceleration()) 
		m_accelerationShape.setPosition(newPos);
}

Bounds Object::GetBounds() {
	return this->bounds;
}
void Object::SetBounds() {
	bounds.Set(x(), y(), width(), height());
}

sf::Vector2f Object::WorldOrigin = sf::Vector2f(0, 0);
int Object::ObjectCount = 0;
