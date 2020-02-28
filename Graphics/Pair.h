#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <SFML/System/Vector2.hpp>
#include "UtilityMethods.h"

template <class T = double>
class Pair {
public:
	Pair();
	Pair(T, T);
	Pair(const Pair<T>&);
	Pair<T>& operator=(const Pair<T>&);

	T X() const;
	T Y() const;

	T XPlus(T);
	T YPlus(T);

	void Set(T, T);
	void Set(Pair<T>);
	void Zero();

	sf::Vector2f AsVector();

	double Magnitude();
	double Angle();

	bool operator==(Pair<T>&);
	bool operator==(T);
	bool operator!=(Pair<T>&);

	Pair<T> operator+(Pair<T>);
	Pair<T> operator-(Pair<T>);
	Pair<T> operator*(Pair<T>);
	Pair<T> operator/(Pair<T>);

	Pair<T>& operator+=(Pair<T>);
	Pair<T>& operator-=(Pair<T>);
	Pair<T>& operator*=(Pair<T>);
	Pair<T>& operator/=(Pair<T>);

	Pair<T> operator+(T);
	Pair<T> operator-(T);
	Pair<T> operator*(T);
	Pair<T> operator/(T);

	Pair<T>& operator+=(T);
	Pair<T>& operator-=(T);
	Pair<T>& operator*=(T);
	Pair<T>& operator/=(T);

	static long long objCount;

private:
	/*
	void doCalculations();
	double magnitude = 0;
	float degrees = 0;
	*/
	T x, y;
};

template <class T>
long long Pair<T>::objCount = 0;

template <class T>
Pair<T>::Pair() : Pair(0, 0) {

}
template <class T>
Pair<T>::Pair(const Pair<T>& p) : Pair(p.x, p.y) {

}
template <class T>
Pair<T>::Pair(T x, T y) {
	this->Set(x, y);
}
template <class T>
Pair<T>& Pair<T>::operator=(const Pair<T>& p) {
	this->Set(p);
	return *this;
}

template <class T>
bool Pair<T>::operator==(T n) {
	return (x == n && y == n);// || (magnitude == n);
}

template <class T>
T Pair<T>::X() const {
	return this->x;
}
template <class T>
T Pair<T>::Y() const {
	return this->y;
}
template <class T>
T Pair<T>::XPlus(T n) {
	return (this->x += n);
}
template <class T>
T Pair<T>::YPlus(T n) {
	return (this->y += n);
}

template <class T>
void Pair<T>::Set(T x, T y) {
	this->x = x;
	this->y = y;
	//doCalculations();
}
template <class T>
void Pair<T>::Set(Pair<T> p) {
	this->Set(p.x, p.y);
}
template <class T>
void Pair<T>::Zero() {
	Set(0, 0);
}


template <class T>
sf::Vector2f Pair<T>::AsVector() {
	return sf::Vector2f(x, y);
}
template <class T>
double Pair<T>::Magnitude() {
	return this->magnitude;
}
template <class T>
double Pair<T>::Angle() {
	return this->degrees;
}

template <class T>
bool Pair<T>::operator==(Pair<T>& p) {
	return x == p.x && y == p.y;
}
template <class T>
bool Pair<T>::operator!=(Pair<T>& p) {
	return x != p.x || y != p.y;
}

template <class T>
Pair<T> Pair<T>::operator+(Pair<T> p) {
	return Pair<T>(x + p.x, y + p.y);
}
template <class T>
Pair<T> Pair<T>::operator-(Pair<T> p) {
	return Pair<T>(x - p.x, y - p.y);
}
template <class T>
Pair<T> Pair<T>::operator*(Pair<T> p) {
	return Pair<T>(x * p.x, y * p.y);
}
template <class T>
Pair<T> Pair<T>::operator/(Pair<T> p) {
	return Pair<T>(x / p.x, y / p.y);
}

template <class T>
Pair<T> Pair<T>::operator+(T n) {
	return this->operator+(Pair<T>(n, n));
}
template <class T>
Pair<T> Pair<T>::operator-(T n) {
	return this->operator-(Pair<T>(n, n));
}
template <class T>
Pair<T> Pair<T>::operator*(T n) {
	return this->operator*(Pair<T>(n, n));
}
template <class T>
Pair<T> Pair<T>::operator/(T n) {
	return this->operator/(Pair<T>(n, n));
}

template <class T>
Pair<T>& Pair<T>::operator+=(Pair<T> p) {
	this->x += p.x;
	this->y += p.y;
	return *this;
}
template <class T>
Pair<T>& Pair<T>::operator-=(Pair<T> p) {
	this->x -= p.x;
	this->y -= p.y;
	return *this;
}
template <class T>
Pair<T>& Pair<T>::operator*=(Pair<T> p) {
	this->x *= p.x;
	this->y *= p.y;
	return *this;
}
template <class T>
Pair<T>& Pair<T>::operator/=(Pair<T> p) {
	this->x /= p.x;
	this->y /= p.y;
	return *this;
}

template <class T>
Pair<T>& Pair<T>::operator+=(T n) {
	this->x += n;
	this->y += n;
	return *this;
}
template <class T>
Pair<T>& Pair<T>::operator-=(T n) {
	this->x -= n;
	this->y -= n;
	return *this;
}
template <class T>
Pair<T>& Pair<T>::operator*=(T n) {
	this->x *= n;
	this->y *= n;
	return *this;
}
template <class T>
Pair<T>& Pair<T>::operator/=(T n) {
	this->x /= n;
	this->y /= n;
	return *this;
}

/*
template <class T>
void Pair<T>::doCalculations() {
	if (x == 0 && y == 0) return;

	magnitude = sqrt(pow(x, 2) + pow(y, 2));
	degrees = fabs(atan(y / x) * (180 / M_PI));
	//Catches: x < 0, and implicitly x < 0 && y < 0
	if (x < 0) degrees += 180;
	else if (y < 0 && x > 0) degrees += 360;
}
*/
