#include "Object.h"
#include <math.h>
#include <iostream>
#include "UtilityMethods.h"
#define _USE_MATH_DEFINES 


void Object::Init(double x, double y, double mass, double width, double height)
{
	uID = Object::ObjectCount++;
	SetPosition(Pair<>(x, y));
	SetSize(Pair<>(width, height));
	Velocity = Pair<>(0.f, 0.f);
	
	SetMass(mass);

	bounciness(0.f);
	coefficientOfFriction(0.f);

	setColor(sf::Color::White);
}
Object::Object()
{
	float f = 10.f;
	Init(f, f, f, f, f);
}
Object::Object(double X, double Y, double Mass, double Width, double Height)
{
	Init(X, Y, Mass, Width, Height);
}

double Object::Mass() {
	return this->mass;
}
void Object::SetMass(double NewMass) {
	this->mass = NewMass;
}

int Object::UID() {
	return this->uID;
}
sf::Shape* Object::Shape() {
	return &this->m_shape;
}

void Object::UpdatePosition()
{
	//Velocity += StagedVelocity;
	//StagedVelocity.Zero();
	if (isAffectedByGravity())
		Velocity.YPlus(WorldMeta->Gravity * WorldMeta->FrameTime);


	AddPosition(Velocity * WorldMeta->FrameTime * WorldMeta->Scale);
}

void Object::CollideWith(Object* obj) {
	float totalBounciness = (obj->bounciness() + this->bounciness()) / 2;
	//Utility::print("-----------------------------------");
	//Utility::print("Collision: " + std::string(std::to_string(UID()) + " -> " + std::to_string(obj->UID())));
	//Utility::print("Position: ", Position.AsVector());
	//Utility::print("Velocity: ", Velocity.AsVector());
	Velocity.Set(0,15);
	//Velocity.Set(Velocity.X(), -(Velocity.Y() * totalBounciness));
	//StagedVelocity = Velocity;
	//StagedVelocity.YPlus(-Velocity.Y() * obj->bounciness());
}

Force Object::GetForce() {
	return Force();
}
Force Object::ApplyForce(Force force) {
	return force;
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

void Object::hasCollision(bool Collides)
{
	m_hasCollision = Collides;
}
bool Object::hasCollision()
{
	return m_hasCollision;
}

void Object::setColor(sf::Color Color)
{
	this->color = Color;
	m_shape.setFillColor(this->color);
}
sf::Color Object::Color()
{
	return color;
}

void Object::setTexture(sf::Texture Texture)
{
	texture() = Texture;
}
sf::Texture& Object::texture()
{
	return m_texture;
}

void Object::AddPosition(Pair<double> addPos) {
	Position += addPos;
	UpdatePositions();
}
void Object::SetPosition(Pair<double> pos) {
	Position = pos;
	UpdatePositions();
}
void Object::UpdatePositions() {
	Bound.SetCenter(Position);
	SetShapePosition();
}

void Object::SetSize(Pair<double> size) {
	Size = size;
	UpdateSizes();
}
void Object::UpdateSizes() {
	Bound.SetSize(Size);
	m_shape.setSize(Size.AsVector());
}

void Object::SetShapePosition() {
	sf::Vector2f newPos;
	newPos = this->WorldMeta->Origin.AsVector();
	//Adjust so object is at the world origin
	newPos.x -= Size.X() / 2;
	newPos.y -= Size.Y() / 2;
	//Change the position to the passed position
	newPos.x += Position.X();
	newPos.y -= Position.Y();
	//Set the objects position
	m_shape.setPosition(newPos);
}

WorldMeta* Object::WorldMeta;
int Object::ObjectCount = 0;
