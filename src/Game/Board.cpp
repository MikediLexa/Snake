/*
 * Board.cpp
 *
 *  Created on: 13.12.2025
 *      Author: mike
 */

#include<iostream>
#include<list>
#include<vector>

#include "Game/Position.h"
#include "Game/Board.h"


Board::Board()
	: width_(100),
	  height_(100)
	{}

Board::Board(int width, int height)
	: width_(width),
	  height_(height),
	  cells_(width * height, CellType::empty) // alle Felder leer
	{}


	bool Board::isOutside(Position pos) const
	{
		return pos.x < 1 || pos.x > width_
				|| pos.y < 1 || pos.y > height_;
	}


