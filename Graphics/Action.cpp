#include "Action.h"

Action::Action(const Action& action) {
	this->lastExecuted = action.lastExecuted;
	this->timesExecuted = action.timesExecuted;
}

void Action::UpdateStats() {
	lastExecuted = Utility::timeNow();
	timesExecuted++;
}
double Action::TimeSinceLastExecution() {
	double now = Utility::timeNow();
	return now - this->lastExecuted;
}