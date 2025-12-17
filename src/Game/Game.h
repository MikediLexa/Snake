
#ifndef GAME_H
#define GAME_H

#include "Game/Position.h"

class Game{

private:
	bool gameOver;


public:
	Game();


	void setGameOver();

	void start();

	Position createRandomPosition();

	void checkCell();

};

#endif
