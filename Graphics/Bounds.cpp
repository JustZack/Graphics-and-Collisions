#include "Bounds.h"
#include "UtilityMethods.h"

Bounds::Bounds() {
	Set(Pair<>(0, 0), Pair<>(0, 0));
}
Bounds::Bounds(const Bounds& bound) {
	this->corners = bound.corners;
}
Bounds::Bounds(Pair<> center, Pair<> size) {
	Set(center, size);
}

void Bounds::Set(Pair<> center, Pair<> size) {
	SetCenter(center);
	SetSize(size);
}

void Bounds::SetCenter(Pair<> center) {
	corners.SetCenter(center);
}
void Bounds::SetSize(Pair<> size) {
	corners.SetSize(size);
}

bool Bounds::AdjacentOrContains(Bounds& bounds) {
	return this->corners.IsAdjacentOrContains(bounds.corners);
}

bool Bounds::AdjacentTo(Bounds& bounds) {
	return this->corners.AdjacentToAny(bounds.corners);
}
bool Bounds::Contains(Bounds& bounds) {
	return this->corners.ContainsAny(bounds.corners);
}

sf::Vector2f Bounds::Center() {
	return this->corners.GetCenter();
}
sf::Vector2f Bounds::Size() {
	return this->corners.GetSize();
}