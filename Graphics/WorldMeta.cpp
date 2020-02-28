#include "WorldMeta.h"

WorldMeta::WorldMeta() : WorldMeta(Pair<>(0, 0)){

}
WorldMeta::WorldMeta(Pair<> p) : WorldMeta(p, -9.81) {

}
WorldMeta::WorldMeta(Pair<> worldOrigin, double gravity, double scale) {
	Origin = worldOrigin;
	Gravity = gravity;
	FrameTime = 0;
	Scale = scale;
}
