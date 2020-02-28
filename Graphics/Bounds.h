#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "Direction.h"
#include "Pair.h"
#include "Corners.h"

class Bounds {
public:
	Bounds();
	Bounds(const Bounds&);
	Bounds(Pair<> center, Pair<> size);
	
	void Set(Pair<> center, Pair<> size);

	void SetCenter(Pair<>);
	void SetSize(Pair<>);

	bool AdjacentOrContains(Bounds&);
	bool AdjacentTo(Bounds&);
	bool Contains(Bounds&);

	sf::Vector2f Center();
	sf::Vector2f Size();
private:
	//The corners of the bounds in a nicely managed object.
	Corners corners;

};