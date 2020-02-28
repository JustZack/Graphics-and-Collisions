#pragma once
#include "Pair.h"
class WorldMeta
{
public:
	WorldMeta();
	WorldMeta(Pair<>);
	WorldMeta(Pair<>, double, double scale = 1);
	Pair<> Origin;
	double Gravity;
	double FrameTime;
	double Scale;
};

