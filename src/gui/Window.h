/*
 * Window.h
 *
 *  Created on: 14.12.2025
 *      Author: mike
 */

#ifndef SDLAPP_WINDOW_H_
#define SDLAPP_WINDOW_H_

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Game/Board.h"

class Window{

private:

public:
	const int kScreenWidth;
	const int kScreenHeight;

	Window();
	~Window();

	int create(int screenWidth, int screenHeight);


};



#endif /* SDLAPP_WINDOW_H_ */
