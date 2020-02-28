#include <iostream>
#include <functional>
#include "SimpleWindow.h"
#include "ToggleFramerate.h"
//https://stackoverflow.com/questions/7582546/using-generic-stdfunction-objects-with-member-functions-in-one-class
int wmain()
{
	//Create a Window and 2D World
	SimpleWindow window("Test", 800, 800, 60); World2D world;
	//Set the worlds origin to the bottom middle of the window
	world.setWorldOrigin(800 / 2, 800);
	//Hook the world into the worlds renderer.
	window.onRender.SetWorld(&world);
	
	//Create an InputAction for the space bar, and the action is the ToggleFramerate FUNCTOR
	InputAction tgl(sf::Keyboard::Space, InputType::Key, new ToggleFramerate(window));
	//Add the action to the input handler
	window.InputHandler.AddAction(tgl);
	
	Object* obj = new Object(0, 200, 20, 25, 25);
	obj->isMoveable(true);
	obj->setColor(sf::Color::Red);
	obj->isAffectedByGravity(true);
	obj->bounciness(.9);
	obj->Velocity.Set(0, -20);

	Object* obj1 = new Object(0, 150, 20, 25, 25);
	obj1->isMoveable(true);
	obj1->setColor(sf::Color::Red);
	obj1->isAffectedByGravity(true);
	obj1->bounciness(.9);
	obj1->Velocity.Set(0, 15);

	Object* obj2 = new Object(0, 100, 20, 25, 25);
	obj2->isMoveable(true);
	obj2->setColor(sf::Color::Red);
	obj2->isAffectedByGravity(true);
	obj2->bounciness(.9);

	Object* floor = new Object(0, 30, 50, 50, 50);
	floor->setColor(sf::Color::Color(25, 210, 215, 200));
	floor->isMoveable(false);
	floor->hasCollision(true);
	floor->isAffectedByGravity(false);
	floor->bounciness(.8);

	world.AddObject(floor);
	world.AddObject(obj);
	world.AddObject(obj1);
	world.AddObject(obj2);

	window.Start();

	delete obj;

	return 0;
}

