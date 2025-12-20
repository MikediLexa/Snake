/*
 * Window.h
 *
 *  Created on: 18.12.2025
 *      Author: mike
 */

#pragma once
#include <SDL3/SDL.h>


const char* GameName{"Snake"};

class Window {
public:
	Window() {
		SDLWindow = SDL_CreateWindow(
		  GameName,
		  GetWidth(), GetHeight(),
		  0
		);
	}

	int GetWidth() const { return 700; }
	int GetHeight() const { return 300; }


	void Render() {
		const auto* Fmt = SDL_GetPixelFormatDetails(
		  GetSurface()->format
		);

		SDL_FillSurfaceRect(
		  GetSurface(),
		  nullptr,
		  SDL_MapRGB(Fmt, nullptr, 50, 50, 50)
		);
	}


	void Update() {
		SDL_UpdateWindowSurface(SDLWindow);
	}


	  SDL_Surface* GetSurface() const {
		  return SDL_GetWindowSurface(SDLWindow);
	  }

	  Window(const Window&) = delete;
	  Window& operator=(const Window&) = delete;

	  ~Window() {
		if (SDLWindow && SDL_WasInit(SDL_INIT_VIDEO)) {
		  SDL_DestroyWindow(SDLWindow);
		}
	  }

private:
  SDL_Window* SDLWindow{nullptr};
};


