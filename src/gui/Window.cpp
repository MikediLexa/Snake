/*
 * Window.cpp
 *
 *  Created on: 14.12.2025
 *      Author: mike
 */

#include<iostream>

#include "../gui/Window.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

Window::Window()
	: kScreenHeight{ 480 },
	  kScreenWidth{ 640 }
{}

Window::~Window()
{}



int Window::create(int screenWidth, int screenHeight)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* win{ SDL_CreateWindow(
			"Grias Ench!", 800, 400, 0)
	};

	SDL_Event e;
	bool quit = false;

	while (!quit)
	{

		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_EVENT_QUIT) { quit = true; }
		}

	}

	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}






