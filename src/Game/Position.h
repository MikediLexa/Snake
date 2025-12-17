#ifndef POSITION_H
#define POSITION_H


struct Position 
{
	int x;
	int y;

	Position ();
	Position (int x, int y);

	bool operator==( const Position& other) const;

};

#endif