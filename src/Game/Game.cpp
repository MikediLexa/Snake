 /* Game.cpp
 *
 *  Created on: 13.12.2025
 *      Author: mike
 */

#include <iostream>
#include <random>
#include <list>

#include "Game/Position.h"
#include "Helper/Enums.h"
#include "Game/Game.h"
#include "Game/Snake.h"
#include "Game/Board.h"
#include "Game/Snake.h"
#include "Game/Food.h"
#include "gui/Window.h"



Game::Game()
	: gameOver(false)
	{}


void Game::setGameOver(){ this->gameOver=true; };

Position Game::createRandomPosition()
	{
		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution(1,6);

		return Position{distribution(generator),distribution(generator)};
	};


// check collisions
// Food shouldn't spawn on snake
//

void Game::start()
{
	Snake snake = Snake();
	Board board = Board(20, 20);
	Food food = Food(10, 10);
	Window window;

	Position nextHeadPos;
	Position nextFood;

	window.create(
			board.width_ * board.CELL_SIZE,
			board.height_ * board.CELL_SIZE
	);

	char userEingabe;

	while(!this->gameOver) {
		// set Timer für User Eingabe
		// while timer !0 - listen User Eingabe
		std::cin >> userEingabe;
		switch (userEingabe){
		case 'a': // Left Arrow
			snake.updateSnakeDirection(Direction::left);
			break;
		case 'w': // Up Arrow
			snake.updateSnakeDirection(Direction::up);
			break;
		case 'd': // Right Arrow
			snake.updateSnakeDirection(Direction::right);
			break;
		case 's': // Down Arrow
			snake.updateSnakeDirection(Direction::down);
			break;
		default:
			break;
		};



	nextHeadPos = snake.calculateNextHeadPos();

	if (snake.bite(nextHeadPos)) { this->gameOver = true; }

	else if (board.isOutside(nextHeadPos)) { this->gameOver = true;	}

	else if (snake.eat(nextHeadPos, food.getFoodPostion())) { snake.grow(nextHeadPos); }

	else {snake.move(nextHeadPos);};
	}}
