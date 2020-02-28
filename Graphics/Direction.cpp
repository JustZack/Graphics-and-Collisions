#include "Direction.h"

Direction::Direction(int type) {
	dir = (eDirection)type;
}
eDirection Direction::Opposite() {
	eDirection newType = NONE;
	switch (dir) {
	case ABOVE: newType = BELOW; break;
	case RIGHT: newType = LEFT; break;
	case BELOW: newType = ABOVE; break;
	case LEFT: newType = RIGHT; break;
	case NONE: newType = NONE; break;
	}
	return newType;
}
Direction Direction::operator!() {
	int newType = NONE;
	switch (dir) {
	case ABOVE: newType = BELOW; break;
	case RIGHT: newType = LEFT; break;
	case BELOW: newType = ABOVE; break;
	case LEFT: newType = RIGHT; break;
	case NONE: newType = NONE; break;
	}

	return Direction(Opposite());
}
eDirection Direction::Type() {
	return dir;
}
bool Direction::operator==(Direction d) {
	return dir == d.dir;
}
bool Direction::operator!=(Direction d) {
	return dir != d.dir;
}

bool Direction::MovingTowards(Direction d) {
	return !(*this) == d;
}
bool Direction::MovingAway(Direction d) {
	return !(*this) == d;
}

bool Direction::isHorizontal() {
	return dir == LEFT || dir == RIGHT;
}
bool Direction::isVertical() {
	return dir == ABOVE || dir == BELOW;
}
