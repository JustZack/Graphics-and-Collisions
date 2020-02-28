#pragma once
#include <vector>
#include "Object.h"
#include "CollisionGrid.h"
#include "WorldMeta.h"

class World2D {
public:
	World2D();
	World2D(Pair<> worldOrigin);
	World2D(const World2D&);
	~World2D();

	//Set the offset (in pixels) for the location of the world on screen.
	void setWorldOrigin(double x, double y);

	/* Add an object */
	void AddObject(Object*);

	/* Get the objects */
	std::vector<Object*>& Objects();

	/* Updates the state of the world */	
	//timeElasped: time (in ms) since last update.
	void Update(double timeElapsed);
private:
	WorldMeta meta;
	std::vector<Object*> objects;
	CollisionGrid collisionGrid;
};