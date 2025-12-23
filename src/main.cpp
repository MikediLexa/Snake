#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "Window.h"
#include "Image.h"

int main(int, char**) {
  SDL_Init(SDL_INIT_VIDEO);
  Window GameWindow;

  std::string BASE_PATH{SDL_GetBasePath()};
  std::string IMAGE_PATH{BASE_PATH + "assets/example.png"};
  Image Example(  IMAGE_PATH  );

  bool IsRunning = true;
  SDL_Event Event;

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
