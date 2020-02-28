#include "Corners.h"

Corners::Corners() : Corners(0, 0, 0, 0){
	
}
Corners::Corners(double x, double y, double width, double height) : Corners(Pair<>(x, y), Pair<>(width, height)){

}
Corners::Corners(Pair<> center, Pair<> size) {
	SetCenter(center);
	SetSize(size);
}

Corners::Corners(const Corners& corners) {
	this->operator=(corners);
}

Corners& Corners::operator=(const Corners& corners) {
	this->corners = corners.corners;
	this->Center = corners.Center;
	this->Size = corners.Size;
	return *this;
}

sf::Vector2i Corners::operator[](int index) const {
	if (corners.size() == 0) return sf::Vector2i();
	else return corners[index];
}

sf::Vector2i Corners::operator[](int index) {
	if (corners.size() == 0) CreateCorners();
	return corners[index];
}

void Corners::CreateCorners() {
	corners.clear();

	double x, y, w, h;
	w = Size.X();
	h = Size.Y();
	x = Center.X() - w / 2;
	y = Center.Y() - h / 2;

	corners.push_back(sf::Vector2i(x, y));
	corners.push_back(sf::Vector2i(x + w, y));
	corners.push_back(sf::Vector2i(x + w, y + h));
	corners.push_back(sf::Vector2i(x, y + h));
}

void Corners::Set(Pair<> center, Pair<> size) {
	SetCenter(center);
	SetSize(size);
}
void Corners::SetCenter(Pair<> center) {
	Center.Set(center);
	corners.clear();
}
void Corners::SetSize(Pair<> size) {
	Size.Set(size);
	corners.clear();
}

bool Corners::Contains(int x, int y) {
	return PointInXSpace(x) && PointInYSpace(y);
}

bool Corners::Contains(sf::Vector2i p) {
	return this->Contains(p.x, p.y);
}

bool Corners::Contains(Pair<> p) {
	return this->Contains(p.X(), p.Y());
}

std::vector<sf::Vector2i> Corners::Contains(Corners& corners) {
	return this->Contains(corners.corners);
}
std::vector<sf::Vector2i> Corners::Contains(std::vector<sf::Vector2i>& corners) {
	std::vector<sf::Vector2i> contained;
	for (sf::Vector2i p : corners) 
		if (this->Contains(p))
			contained.push_back(p);
	return contained;
}

bool Corners::ContainsAny(Corners& c) {
	for (sf::Vector2i p : c) {
		if (this->Contains(p))
			return true;
	}
	return false;
}
bool Corners::ContainsAll(Corners& c) {
	for (sf::Vector2i p : c)
		if (!this->Contains(p))
			return false;
	return true;
}

//Is the point between the min and max X coordinates?
bool Corners::PointInXSpace(int x) {
	return (x >= (*this)[0].x && x <= (*this)[1].x);
}
//Is the point between the min and max Y coordinates?
bool Corners::PointInYSpace(int y) {
	return (y >= (*this)[0].y && y <= (*this)[3].y);
}


bool Corners::AdjacentTo(int x, int y) {
	return PointIsAbove(x, y) || PointIsToRight(x, y) 
		|| PointIsBelow(x, y) || PointIsToLeft(x, y);
}
bool Corners::AdjacentTo(Pair<> p) {
	return this->AdjacentTo(p.X(), p.Y());
}
bool Corners::AdjacentTo(sf::Vector2i p) {
	return this->AdjacentTo(p.x, p.y);
}

std::vector<sf::Vector2i> Corners::AdjacentTo(Corners& corners) {
	return this->AdjacentTo(corners.corners);
}
std::vector<sf::Vector2i> Corners::AdjacentTo(std::vector<sf::Vector2i>& corners) {
	std::vector<sf::Vector2i> adjacent;
	for (sf::Vector2i p : corners)
		if (this->AdjacentTo(p))
			adjacent.push_back(p);
	return adjacent;
}

bool Corners::AdjacentToAny(Corners& c) {
	for (sf::Vector2i c : c.corners)
		if (this->AdjacentTo(c))
			return true;
	return false;
}

bool Corners::PointIsAbove(int x, int y) {
	int yDiff = y - (*this)[1].y;
	return PointAboveOrBelow(x, yDiff);
}
bool Corners::PointIsBelow(int x, int y) {
	int yDiff = (*this)[2].y - y;
	return PointAboveOrBelow(x, yDiff);
}
bool Corners::PointIsToRight(int x, int y) {
	int xDiff = x - (*this)[1].x;
	return PointToLeftOrRight(xDiff, y);
}
bool Corners::PointIsToLeft(int x, int y) {
	int xDiff = (*this)[0].x - x;
	return PointToLeftOrRight(xDiff, y);
}

bool Corners::IsAdjacentOrContains(Corners& corners) {
	return this->AdjacentToAny(corners) || this->ContainsAny(corners);
}


//Is the point above or below the point?
bool Corners::PointAboveOrBelow(int x, int yDiff) {
	return PointInXSpace(x) && yDiff >= 0 && yDiff <= 2;

}
//Is the point to the left or right of the point?
bool Corners::PointToLeftOrRight(int xDiff, int y) {
	return PointInYSpace(y) && xDiff >= 0 && xDiff <= 2;
}

Corners::iterator Corners::begin() {
	if (corners.size() == 0) CreateCorners();
	return corners.begin();
}
Corners::const_iterator Corners::begin() const {
	return corners.begin();
}
Corners::iterator Corners::end() {
	if (corners.size() == 0) CreateCorners();
	return corners.end();
}
Corners::const_iterator Corners::end() const {
	return corners.end();
}

sf::Vector2f Corners::GetCenter() {
	return this->Center.AsVector();
}
sf::Vector2f Corners::GetSize() {
	return this->Size.AsVector();
}