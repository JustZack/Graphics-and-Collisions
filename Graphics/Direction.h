#pragma once
enum eDirection {
	ABOVE,
	RIGHT,
	BELOW,
	LEFT,
	NONE
};
class Direction
{
public:
	Direction(int type);



	Direction operator!();
	eDirection Opposite();
	eDirection Type();

	bool operator==(Direction);
	bool operator!=(Direction);

	bool MovingTowards(Direction d);
	bool MovingAway(Direction d);
	
	bool isHorizontal();
	bool isVertical();

private:
	eDirection dir;
};

