#pragma once
#include <vector>
#include "Grid.h"

class CollisionGrid {
public:
	CollisionGrid();
	CollisionGrid(int GridSize);
	CollisionGrid(int GridSize, int SectionSize);
	void DoCollisions(std::vector<Object*>& object);
private:
	Grid grid;
};