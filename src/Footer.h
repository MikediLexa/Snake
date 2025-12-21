#pragma once
#include <SDL3/SDL.h>

#include "Rectangle.h"

class Footer {
public:
	Footer()
	{ Background.SetColor({100, 100, 100, 255});}


	void Render(SDL_Surface* Surface) const
	{
		Background.Render(Surface);
	}

	void HandleEvent(SDL_Event& E)
	{
		Background.HandleEvent(E);
	}
private:

	Rectangle Background{SDL_Rect{0, 250, 700, 50}};

};
