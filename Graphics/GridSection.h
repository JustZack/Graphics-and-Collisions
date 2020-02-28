#pragma once
#include "Object.h"
#include "Bounds.h"

class GridSection {
public:
	GridSection() = default;
	GridSection(int, int, int);
	GridSection(const GridSection&);

	void AddIfContains(Object* obj);
	bool Contains(Object* obj);
	void AddObject(Object* obj);
	
	bool hasObjects();
	int objectCount();

	void DoCollisions();
	void operator()();

	//The bounds of this section
	Bounds Bound;

	std::string ToString();
private:
	//The grid coordinates of this section in the grid
	int gridX, gridY;
	//The world coordinates of this section in the grid
	int worldX, worldY;
	//The width/height of this section of the grid.
	int size;
	
	//Objects contained in this section
	std::vector<Object*> objects;
};