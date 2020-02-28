#pragma once
#include <SFML\Graphics.hpp>
#include "Bounds.h"
#include "Force.h"
#include "Collision.h"
#include "Pair.h"

class Object
{

public:
	//TODO: Should every object have an on click event asociated with it? [old btw]

	Object();
	Object(float X, float Y, float Mass, float Width, float Height);

	//Updates the position of the object
	void Update(float frameTime, float g);

	void CollideWith(Object*);

	void setPosition(float X, float Y);
	sf::Vector2f pos();
	sf::Vector2f posCenter();

	float x();void x(float x);
	float y();void y(float y);

	float mass();void mass(float mass);

	void setDimensions(float Width, float Height);
	sf::Vector2f size();
	float width();void width(float width);
	float height();void height(float height);

	//Returns the radius of the object.
	float radius();

	float xSpeed();void xSpeed(float XSpeed);
	float ySpeed();void ySpeed(float XSpeed);
	sf::Vector2f Velocity();

	Force GetForce();
	Force ApplyForce(Force);

	std::string& name();

	float accelerationMagnitude();void accelerationMagnitude(float mag);
	float accelerationAngle();void accelerationAngle(float angle);
	bool showacceleration(); void showacceleration(bool ShowAcceleration);

	float bounciness(); void bounciness(float Bounciness);

	float coefficientOfFriction(); void coefficientOfFriction(float CoefficientOfFriction);

	Bounds GetBounds();

	bool isAffectedByGravity();void isAffectedByGravity(bool AffectedByGravity);

	bool isMoveable();void isMoveable(bool Moveable);

	bool isOnScreen();void isOnScreen(bool OnScreen);

	bool hasCollision(); void hasCollision(bool Collides);

	int collisionLayer(); void collisionLayer(int CollisionLayer);

	std::vector<sf::Vector2f> gettrail();
	float trailTimeInterval(); void trailTimeInterval(float TimeInterval);

	void setColor(sf::Color Color);
	sf::Color& color();

	void setTexture(sf::Texture Texture);
	sf::Texture& texture();

	sf::Shape& Shape();

	sf::RectangleShape& accelerationShape();

	int UID();

	static sf::Vector2f WorldOrigin;
	static int ObjectCount;

	Pair<int> Size;
	Pair<int> Position;
	Pair<double> Velocity;
	Pair<double> Acceleration;
private:


	float m_x, m_y;
	float m_mass;
	float m_width, m_height;
	float m_radius;
	float m_xSpeed, m_ySpeed;
	Bounds bounds;
	void SetBounds();
	int uID;
	std::string m_name;

	std::vector<Collision> collisions;
	void ApplyCollisions();

	float m_bounciness;
	float m_coefficientOfFriction;

	float m_accelerationMagnitude;
	float m_accelerationAngle;
	bool m_showacceleration;

	bool m_isAffectedByGravity = true;
	bool m_isMoveable = true;
	bool m_isOnScreen = true;

	bool m_hasCollision = true;
	int m_collisionLayer = 0;

	std::vector<sf::Vector2f> m_trail;
	float m_tempTime_trial;
	float m_trailTimeInterval;

	sf::Color m_color = sf::Color::White;
	sf::Texture m_texture;
	sf::RectangleShape m_shape;
	sf::RectangleShape m_accelerationShape;

	void Update_Position(float frameTime, float g);
	void Update_Acceleration();
	void Update_PopulateTrail(float frametime);
	void WindowEdgeCollisionCheck();

	//Creates the object class using data from the constructors.
	void Init(float X, float Y, float Mass, float Width, float Height);

	/* Sets the shapes position relative to the ::WorldOrigin and the objects position */
	/* Basically, sets the shape pixel position relative to the Object::WorldOffset*/
	void SetShapePosition(double, double);
	void SetShapePosition(sf::Vector2f);
};
