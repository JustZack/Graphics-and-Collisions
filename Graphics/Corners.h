#pragma once
#define _USE_MATH_DEFINES
#include <cmath> 
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "Pair.h"

/*
Rationalle for this class:
	Bound's need corners, but the corners change often, so the data is frequently invalidated.
	Having the corners here means I can recalculate check if the bounds should be
	recomputed in the accessor (I.E. operator[]) instead of the function that accesses the corners.
*/
class Corners
{
public:
	Corners();
	Corners(double, double, double, double);
	Corners(Pair<> center, Pair<> size);

	Corners(const Corners&);
	Corners& operator=(const Corners&);

	void Set(Pair<> center, Pair<> size);
	void SetCenter(Pair<>);
	void SetSize(Pair<>);

	sf::Vector2i operator[](int) const;
	sf::Vector2i operator[](int);

	bool Contains(int, int);
	bool Contains(Pair<>);
	bool Contains(sf::Vector2i);

	//Which corners do these corners contain?
	std::vector<sf::Vector2i> Contains(Corners&);
	//Which corners do these corners contain?
	std::vector<sf::Vector2i> Contains(std::vector<sf::Vector2i>&);

	bool ContainsAny(Corners&);
	bool ContainsAll(Corners&);

	bool PointIsAbove(int, int);
	bool PointIsBelow(int, int);
	bool PointIsToRight(int, int);
	bool PointIsToLeft(int, int);

	bool AdjacentTo(int, int);
	bool AdjacentTo(Pair<>);
	bool AdjacentTo(sf::Vector2i);

	//Which corners are these corners adjacent to?
	std::vector<sf::Vector2i> AdjacentTo(Corners&);
	//Which corners are these corners adjacent to?
	std::vector<sf::Vector2i> AdjacentTo(std::vector<sf::Vector2i>&);

	bool AdjacentToAny(Corners&);
	
	bool IsAdjacentOrContains(Corners&);

	typedef std::vector<sf::Vector2i>::iterator iterator;
	typedef const std::vector<sf::Vector2i>::const_iterator const_iterator;

	iterator begin(); 
	const_iterator begin() const;
	iterator end(); 
	const_iterator end() const;

	sf::Vector2f GetCenter();
	sf::Vector2f GetSize();
private:
	bool PointInXSpace(int x);
	bool PointInYSpace(int y);

	bool PointAboveOrBelow(int x, int yDiff);
	bool PointToLeftOrRight(int xDiff, int y);

	void CreateCorners();
	std::vector<sf::Vector2i> corners;
	Pair<> Center;
	Pair<> Size;
};

