#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
#include "ErrorHandling.h"
#include "Window.h"
#include "Rectangle.h"


int main(int, char**) {
  SDL_Init(SDL_INIT_VIDEO);

  Window GameWindow;
  Rectangle Rect{SDL_Rect{50,50,50,50}};

  bool IsRunning = true;
  SDL_Event Event;

  while (IsRunning) { 							// Main-Loop



	  // 1. Process Events
    while (SDL_PollEvent(&Event)) {				// diese Schleife läuft, solange Events in PollEvent-Queue anstehen.
    	Rect.HandleEvent(Event);
    	if (Event.type == SDL_EVENT_QUIT) 					{ IsRunning = false; }

	  // 2. Update Objects

	  // 3. Render Changes
    	//Render Background Color
        GameWindow.Render();

        // Render everything else
        Rect.Render(GameWindow.GetSurface());

        GameWindow.Update(); // swap buffers
    }
  }

  SDL_Quit();
  return 0;
}
