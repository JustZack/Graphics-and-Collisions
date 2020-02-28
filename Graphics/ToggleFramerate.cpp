#include "ToggleFramerate.h"

void ToggleFramerate::operator()() {
	this->window.ToggleFramerate();
	this->UpdateStats();
}