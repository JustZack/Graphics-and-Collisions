#pragma once
#include <SFML/Window.hpp>
#include <functional>
#include "UtilityMethods.h"
#include "Action.h"

enum InputType {
	Key,
	Mouse,
	Other
};

class InputAction {
public:
	InputAction();
	~InputAction();
	InputAction(const InputAction&);
	InputAction(int keyCode, int inputType) : InputAction(keyCode, inputType, NULL) { };
	InputAction(int, int, Action*);
	
	void DoActions();
	void AddAction(Action*);

	int KeyCode() const { return this->keyCode; }
	InputType Type() const { return this->type; }
	double LastTimeExecuted() const { return this->lastTimeExecutedMS; }
	double TimeSinceLastExecution() const { return Utility::timeNow() - this->lastTimeExecutedMS; }
	std::vector<Action*>& Actions() { return this->actions; }

	bool isActive();
	bool Equals(InputAction&);
private:
	/* Must be a vector of action POINTERS since Actions are abstract */
	std::vector<Action*> actions;
	InputType type = InputType::Other;
	int keyCode = -1;
	double lastTimeExecutedMS = 0;
	int inputCooldownMS = 50;
	bool wasActive = false;
};