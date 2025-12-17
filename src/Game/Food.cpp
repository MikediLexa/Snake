/*
 * Food.cpp
 *
 *  Created on: 13.12.2025
 *      Author: mike
 */


#include "Game/Food.h"

Food::Food()
	:FoodPosition(Position(15,15))
	{}

Food::Food(int x, int y)
	:FoodPosition(Position(x,y))
	{}


void Food::setNewFoodPosition(int x, int y)
{
	this->FoodPosition.x = x;
	this->FoodPosition.y = y;

};

Position Food::getFoodPostion()
{
	return this->FoodPosition;
};



