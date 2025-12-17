#include "config.h"
#include <iostream>
#include <vector>
#include <list>
#include <random>

#include "Game/Position.h"
#include "Game/Snake.h"



	Snake::Snake()
		:snakeSegments_{Position(4,2), Position(3,2), Position(2,2)},
		 snakeDirection( Direction::right )
		 {}

	Position Snake::calculateNextHeadPos()
	{
		Position nextHeadPos;


		switch (Snake::snakeDirection) {
			case Direction::up:
				nextHeadPos.x = Snake::snakeSegments_.front().x;
				nextHeadPos.y = Snake::snakeSegments_.front().y - 1;
				break;

			case Direction::down:
				nextHeadPos.x = Snake::snakeSegments_.front().x;
				nextHeadPos.y = Snake::snakeSegments_.front().y + 1;
				break;

			case Direction::left:
				nextHeadPos.x = Snake::snakeSegments_.front().x - 1;
				nextHeadPos.y = Snake::snakeSegments_.front().y;
				break;

			case Direction::right:
				nextHeadPos.x = Snake::snakeSegments_.front().x + 1;
				nextHeadPos.y = Snake::snakeSegments_.front().y;
				break;

			default:
				break;

			};
			return nextHeadPos;
	};


	void Snake::grow(Position nextHeadPos)
	{
		Snake::snakeSegments_.push_front(nextHeadPos);
	};

	void Snake::move(Position nextHeadPos)
	{
		Snake::snakeSegments_.push_front(nextHeadPos);
		Snake::snakeSegments_.pop_back();
	};

	bool Snake::bite(Position nextHeadPos)
	{
		// check here if nextHeadPos is at board, if not return true
		// bite means the snake bite itself or is out of the board = game over
		for (Position pos : Snake::snakeSegments_)
		{
			if (nextHeadPos == pos) return true;

		}
		return false;
	};

	bool Snake::eat(Position nextHeadPos, Position actualFood)
	{
		if (nextHeadPos == actualFood) return true;
		return false;
	};

	std::list<Position> Snake::getSnakeSegments()
	{
		return Snake::snakeSegments_;
	};

	void Snake::updateSnakeDirection(Direction newDirection)
	{
		Snake::snakeDirection = newDirection;
	};





