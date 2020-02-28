#pragma once
#include <vector>
#include "GridSection.h"
#include "ThreadPool.h"

class Grid
{
public:
	Grid();
	Grid(int GridSize, int SectionSize);
	
	void DoCollisions(std::vector<Object*>& objects);
private:
	std::vector<GridSection> grid;
	int section_size;
	ThreadPool<GridSection> pool;
	void init(int GridSize, int SectionSize);
};

