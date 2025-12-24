#include "SDL3/SDL_error.h"
#include "SDL3/SDL_filesystem.h"
#include "Text.h"
#include "Window.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>

int main(int, char**) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    if (!TTF_Init()) {
        std::cout
            << "Error initializing SDL_ttf: "
            << SDL_GetError();
    }

    std::string BASE_PATH{SDL_GetBasePath()};
    std::string FONT_PATH{
        BASE_PATH + "assets/LeagueSpartan.ttf"};

    Window GameWindow;
    Text TextExample{"Ich liebe meine Frau!",
                     FONT_PATH, 50.0f};

    bool IsRunning = true;
    SDL_Event Event;

    while (IsRunning) {
        while (SDL_PollEvent(&Event)) {
            if (Event.type == SDL_EVENT_QUIT) {
                IsRunning = false;
            }
        }

        GameWindow.Render();
        TextExample.Render(
            GameWindow.GetSurface());
        GameWindow.Update();
    }

    TTF_Quit();
    SDL_Quit();
    return 0;
};
