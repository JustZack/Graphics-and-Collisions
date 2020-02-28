#include "Grid.h"
#include "UtilityMethods.h"
#include "Task.h"

Grid::Grid() : Grid(10, 50) { 

};
Grid::Grid(int GridSize, int SectionSize) {
	init(GridSize, SectionSize);
}

void Grid::DoCollisions(std::vector<Object*>& objects) {
	//Add the objects for each grid section
	for (GridSection& section : this->grid) {
		for (Object* obj : objects) {
			section.AddIfContains(obj);
		}
		//section.DoCollisions();
		pool.AddTask(Task<GridSection>(section));
	}
	pool.Run();
}

void Grid::init(int GridWidth, int SectionSize) {
	this->section_size = SectionSize;

	//Clear out old grid if needed
	if (this->grid.size() > 0) this->grid.clear();

	int size = this->section_size;
	//Ensure gridwidth is always even.
	if (GridWidth % 2 > 0) GridWidth++;
	//Start the grid half way past 0.
	int gridOffset = GridWidth / 2;
	for (int i = -gridOffset; i < gridOffset; i++) {
		for (int j = -gridOffset; j < gridOffset; j++) {
			grid.push_back(GridSection(i, j, size));
			//Utility::print("Grid Pos: " + grid[grid.size() - 1].ToString());
		}
	}
}

