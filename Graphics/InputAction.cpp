#include "InputAction.h"
#include "UtilityMethods.h"

InputAction::InputAction() {

}

InputAction::~InputAction() {
	for (Action* action : this->actions) {
		delete action;
	}
}

InputAction::InputAction(const InputAction& inputAction) {
	this->actions = inputAction.actions;
	this->type = inputAction.type;
	this->keyCode = inputAction.keyCode;
}

InputAction::InputAction(int keyCode, int inputType, Action* action) {
	this->keyCode = keyCode;
	this->type = InputType(inputType);
	this->AddAction(action);
}

void InputAction::AddAction(Action* action) {
	
	if (action != NULL) 
		this->actions.push_back(action);
}

void InputAction::DoActions() {
	wasActive = true;
	lastTimeExecutedMS = Utility::timeNow();
	for (Action* action : this->actions)
		(*action)();
}

bool InputAction::isActive() {
	bool active = false;

	//Check if the button for this action is pressed
	switch (this->type) {
	case Key:
		active = sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyCode));
		break;
	case Mouse:
		active = sf::Mouse::Button(sf::Mouse::Button(this->keyCode));
	default:
		return false;
		break;
	}
	
	//If the button was pressed previously.
	if (wasActive) { 
		//The button is being held, so the action already went off. Do nothing.
		if (active) return false;
		//Otherwise keep track that the button is no longer being held.
		else        wasActive = false;
	}
	//Ensure the buttons 'cooldown' is complete. (this makes buttons less spamable)
	active = active && this->TimeSinceLastExecution() > this->inputCooldownMS;

	return active;
}

bool InputAction::Equals(InputAction& action) {
	return this->type == action.type
		   && this->keyCode == action.keyCode
		   && this->inputCooldownMS == action.inputCooldownMS;
}
