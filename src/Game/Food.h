/*
 * Food.h
 *
 *  Created on: 13.12.2025
 *      Author: mike
 */

#ifndef FOOD_H_
#define FOOD_H_


#include "Game/Position.h"


class Food {

private:
	Position FoodPosition;


public:
	Food();
	Food(int x, int y);
	//~Food();

	void setNewFoodPosition(int x, int y);
	Position getFoodPostion();
};


#endif /* FOOD_H_ */
