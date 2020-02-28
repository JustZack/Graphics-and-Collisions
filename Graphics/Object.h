#pragma once
#include <SFML\Graphics.hpp>
#include "Bounds.h"
#include "Force.h"
#include "Pair.h"
#include "WorldMeta.h"

class Object
{

public:
	//TODO: Should every object have an on click event asociated with it? [old btw]

	Object();
	Object(double X, double Y, double Mass, double Width, double Height);

	//Updates the position of the object based on the current velocity.
	void UpdatePosition();

	/* 
		Compute the effect of colliding with obj

	*/
	void CollideWith(Object* obj);

	Force GetForce();
	Force ApplyForce(Force);

	float bounciness(); void bounciness(float Bounciness);

	float coefficientOfFriction(); void coefficientOfFriction(float CoefficientOfFriction);

	bool isAffectedByGravity();void isAffectedByGravity(bool AffectedByGravity);

	bool isMoveable();void isMoveable(bool Moveable);

	bool hasCollision(); void hasCollision(bool Collides);

	sf::Color Color(); void setColor(sf::Color Color);
	
	sf::Texture& texture(); void setTexture(sf::Texture Texture);

	Pair<> Size;
	Pair<> Position;
	Pair<> Velocity;
	Bounds Bound;
	double Mass(); void SetMass(double);
	int UID();
	sf::Shape* Shape();

	/* 
		Keeps track of how many objects have been instantiated. 
		Used to populate the uID member.
	*/
	static int ObjectCount;

	//Contains information every object needs about the world 
	static WorldMeta* WorldMeta;

private:
	Pair<> StagedVelocity;

	double mass;
	int uID;

	void AddPosition(Pair<>);
	void SetPosition(Pair<>);
	void UpdatePositions();

	void SetSize(Pair<>);
	void UpdateSizes();

	float m_bounciness;
	float m_coefficientOfFriction;
	bool m_isAffectedByGravity = true;
	bool m_isMoveable = true;
	bool m_hasCollision = true;

	sf::Color color;
	sf::Texture m_texture;
	sf::RectangleShape m_shape;

	//Creates the object class using data from the constructors.
	void Init(double X, double Y, double Mass, double , double Height);

	/* Sets the shapes position relative to the ::WorldOrigin and the objects position */
	/* Basically, sets the shape pixel position relative to the Object::WorldOffset*/
	void SetShapePosition();
};
