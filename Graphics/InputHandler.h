#pragma once
#include <vector>
#include "InputAction.h"

class InputProcessor {
public:
	InputProcessor();
	InputProcessor(InputAction&);

	void AddAction(InputAction&);

	void ProcessInput();
private:
	std::vector<InputAction> actions;
};