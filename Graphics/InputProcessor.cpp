#include "InputHandler.h"

InputProcessor::InputProcessor() {

}

InputProcessor::InputProcessor(InputAction& action) {
	this->AddAction(action);
}

void InputProcessor::AddAction(InputAction& newAction) {
	for (InputAction& action : this->actions) {
		if (newAction.Equals(action)) {
			//Moves the actions associated with 'newAction' to the existing action
			std::move(
				newAction.Actions().begin(), 
				newAction.Actions().end(), 
				std::back_inserter(action.Actions())
			);
		}
	}
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