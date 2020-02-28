#include "InputProcessor.h"

InputProcessor::InputProcessor() {

}

InputProcessor::InputProcessor(InputAction& action) {
	this->AddAction(action);
}

void InputProcessor::AddAction(InputAction& newAction) {
	this->actions.push_back(newAction);
}

void InputProcessor::ProcessInput() {
	/* Execute any actions for the active input options */
	for (InputAction& action : actions) {
		if (action.isActive()) {
			action.DoActions();
		}
	}
}