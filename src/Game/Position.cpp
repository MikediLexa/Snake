#include "Game/Position.h"


Position::Position()
	:x(0), y(0)
{}

Position::Position(int x, int y)
	:x(x), y(y)
{}

bool Position::operator==(const Position& other) const
{
	return x == other.x && y == other.y;
}
