#include "CollisionGrid.h"
#include "UtilityMethods.h"

CollisionGrid::CollisionGrid() : CollisionGrid(50) { };
CollisionGrid::CollisionGrid(int GridSize) : CollisionGrid(GridSize, 50) { };
CollisionGrid::CollisionGrid(int GridSize, int sectionsize) : grid(GridSize, sectionsize) { };
void CollisionGrid::DoCollisions(std::vector<Object*>& objects) {
	grid.DoCollisions(objects);
}