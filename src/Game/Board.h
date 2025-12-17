/*
 * Board.h
 *
 *  Created on: 13.12.2025
 *      Author: mike
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <vector>

#include "Helper/Enums.h"
#include "Game/Position.h"


class Board {

private:
	std::vector<CellType> cells_;

public:
	int width_;
	int height_;

	const int CELL_SIZE = 32;

	Board();
	Board(int width, int height);


	bool isOutside(Position pos) const;

};




#endif /* BOARD_H_ */
