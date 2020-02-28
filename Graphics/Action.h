#pragma once
#include "UtilityMethods.h"

enum ActionType {
	Unset,
	Input,
	Drawing
};

class Action {
public:
	Action() = default;
	Action(const Action&);
	virtual void operator ()() = 0;
	void UpdateStats();

	double TimeSinceLastExecution();
	double LastExecuted() { return lastExecuted; }
	double TimesExecuted() { return timesExecuted; }
private:
	double lastExecuted = 0;
	double timesExecuted = 0;

};