#pragma once
#include "Action.h"
#include "World2D.h"
//https://www.sfml-dev.org/tutorials/2.5/graphics-draw.php
class RenderAction : public Action {
public:
	RenderAction() = default;
	RenderAction(const RenderAction&);
	
	void SetWindow(sf::RenderWindow*);
	void SetWorld(World2D*);

	void Render();

	void operator ()(double frameTime);
	void operator ()() override;

	bool IsSet() { return world && window; }

private:
	World2D* world;
	sf::RenderWindow* window;
	double frameTime = -1;
};