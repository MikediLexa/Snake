/*
 * main.cpp
 *
 *  Created on: 13.12.2025
 *      Author: mike
 */

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
// #include <SDL3_image/SDL_image.h>
// #include <SDL3_ttf/SDL_ttf.h>

int main(int, char**) {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window* Window{SDL_CreateWindow(
    "Hello Window", 800, 300, 0
  )};

  bool IsRunning = true;
  SDL_Event Event;
  while (IsRunning) {
    while (SDL_PollEvent(&Event)) {
      if (Event.type == SDL_EVENT_QUIT) {
        IsRunning = false;
      }
    }
  }

  SDL_DestroyWindow(Window);
  SDL_Quit();

  return 0;
}

//#include <iostream>
//
//
//#include "config.h"
//
//
//#include"Game/Game.h"
//#include "gui/Window.h"
//
//
//int main(int argc, char **argv)
//{
//	std::cout << "This is Snake" << std::endl;
//	std::cout << "Version " << Snake_VERSION_MAJOR << "." << Snake_VERSION_MINOR << std::endl;
//
////	Game game;
////	game.start();
//	Window window;
//	window.create(800, 100);
//	std::cout << "Something should have happened!" << std::endl;
//
//	Game newGame = Game();
//
//
//
//	return 0;
//}

