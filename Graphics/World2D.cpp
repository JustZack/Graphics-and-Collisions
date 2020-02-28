#include "World2D.h"
#include "UtilityMethods.h"

World2D::World2D(Pair<> worldOrigin) : World2D(){
	this->meta.Origin = worldOrigin;
}

World2D::World2D() {
	collisionGrid = CollisionGrid(6, 200);
	//Give object class a static pointer to the world meta
	Object::WorldMeta = &(this->meta);
	this->meta.Scale = 10;
}
World2D::~World2D() {
	for (Object* obj : this->objects) {
		delete obj;
	}
}

World2D::World2D(const World2D& world) {
	this->objects = world.objects;
	this->collisionGrid = world.collisionGrid;
	this->meta = world.meta;
}

void World2D::setWorldOrigin(double x, double y) {
	this->meta.Origin = Pair<>(x, y);
}

void World2D::AddObject(Object* object) {
	this->objects.push_back(object);
}

std::vector<Object*>& World2D::Objects() {
	return this->objects;
}

void World2D::Update(double timeElapsed) {
	//Update the world meta with the current frame time
	this->meta.FrameTime = timeElapsed;
	//Update each object
	for (Object* obj : this->objects) {
		obj->UpdatePosition();
	}
	//Process collisions
	collisionGrid.DoCollisions(this->objects);
}