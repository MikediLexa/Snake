#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Window.h"
#include "Image.h"
#include <iostream>

int main(int, char**) {
  SDL_Init(SDL_INIT_VIDEO);
  Window GameWindow;

  std::string BASE_PATH{SDL_GetBasePath()};
  std::string IMAGE_PATH{BASE_PATH + "/assets/pic2.bmp"};

  Image Example(
		  IMAGE_PATH,
		  GameWindow.GetSurface()->format
	  );

  bool IsRunning = true;
  SDL_Event Event;

  std::cout << SDL_GetBasePath();
  while (IsRunning) {
    while (SDL_PollEvent(&Event)) {
      if (Event.type == SDL_EVENT_QUIT) {
        IsRunning = false;
      }
      Example.Render(GameWindow.GetSurface());
    }

    GameWindow.Render();
    Example.Render(GameWindow.GetSurface());
    GameWindow.Update();
  }

  SDL_Quit();
  return 0;
}
;
