/*
 * Snake.h
 *
 *  Created on: 13.12.2025
 *      Author: mike
 */

#ifndef SNAKE_H_
#define SNAKE_H_

#include <list>

#include "Helper/Enums.h"
#include "Game/Position.h"

class Snake {

private:

	std::list<Position> snakeSegments_;
	Direction snakeDirection;

public:
	Snake();

	Position calculateNextHeadPos();

	void grow(Position nextHeadPos);


	void move(Position nextHeadPos);


	bool bite(Position nextHeadPos);


	bool eat(Position nextHeadPos, Position actualFood);


	std::list<Position> getSnakeSegments();

	void updateSnakeDirection(Direction newDirection);

};


#endif /* SNAKE_H_ */
