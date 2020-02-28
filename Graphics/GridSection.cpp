#include "GridSection.h"
#include "UtilityMethods.h"

GridSection::GridSection(int Gridx, int Gridy, int Size)
	: gridX(Gridx), gridY(Gridy), worldX(Gridx * Size), worldY(Gridy * Size), size(Size), 
	Bound(Pair<>(worldX + size/2, worldY + size/2), Pair<>(Size, Size)) {
}	

GridSection::GridSection(const GridSection& section) {
	gridX = section.gridX;
	gridY = section.gridY;
	worldX = section.worldX;
	worldY = section.worldY;
	size = section.size;
	Bound = section.Bound;
	objects = section.objects;
}

void GridSection::AddIfContains(Object* obj) {
	if (this->Contains(obj))
		this->AddObject(obj);
}
bool GridSection::Contains(Object* obj) {
	return this->Bound.Contains(obj->Bound);
}
void GridSection::AddObject(Object* obj) {
	this->objects.push_back(obj);
}

bool GridSection::hasObjects() {
	return this->objectCount() > 0;
}
int GridSection::objectCount() {
	return this->objects.size();
}

void GridSection::DoCollisions() {
	//if (this->objectCount() < 2) return;
	//For each object
	for (Object* obj : this->objects) {
		//Skip objects without collision
		if (!obj->hasCollision()) continue;
		//For each other object
		for (Object* other : this->objects) {
			//Skip idential objects
			if (obj->UID() == other->UID()) continue;
			//Check if the objects are touching/overlapping
			if (obj->Bound.AdjacentOrContains(other->Bound))
				obj->CollideWith(other); //Perform obj's collision onto other.
		}
	}
	//Calculation is over, no longer need to keep track of objects in section
	this->objects.clear();
}

void GridSection::operator()() {
	this->DoCollisions();
}

std::string GridSection::ToString() {
	return "World: " + std::to_string(worldX) + ", " + std::to_string(worldY) 
		+ " | Grid: " + std::to_string(gridX) + ", " + std::to_string(gridY);
}
