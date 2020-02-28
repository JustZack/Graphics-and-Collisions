#include "RenderAction.h"
#include <iostream>

void RenderAction::SetWindow(sf::RenderWindow* window) {
	this->window = window;
}
void RenderAction::SetWorld(World2D* world) {
	this->world = world;
}
void RenderAction::Render() {
	for (Object* obj : this->world->Objects()) {
		this->window->draw(*obj->Shape());
	}
}

void RenderAction::operator()(double frameTime) {
	this->frameTime = frameTime;
	(*this)();
}
void RenderAction::operator()() {
	world->Update(this->frameTime);
	this->Render();
	this->UpdateStats();
}
RenderAction::RenderAction(const RenderAction& action) {
	this->world = action.world;
	this->window = action.window;
	this->frameTime = action.frameTime;
}