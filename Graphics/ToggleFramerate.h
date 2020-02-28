#pragma once
#include "Action.h"
#include "SimpleWindow.h"

class ToggleFramerate : public Action {
public:
	ToggleFramerate(SimpleWindow& Window) : window(Window) { };
	void operator ()() override;

private:
	SimpleWindow& window;
};