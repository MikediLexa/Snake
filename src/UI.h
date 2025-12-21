#pragma once
#include <SDL3/SDL.h>
#include "Header.h"
#include "Grid.h"
#include "Footer.h"

class UI {
public:
	void Render(SDL_Surface* Surface) const
	{
		TopMenu.Render(Surface);
		Rectangles.Render(Surface);
		BottomMenu.Render(Surface);
	}

	void HandleEvent(SDL_Event& E)
	{
		TopMenu.HandleEvent(E);
		Rectangles.HandleEvent(E);
		BottomMenu.HandleEvent(E);
	}

private:
	Header TopMenu;
	Grid Rectangles;
	Footer BottomMenu;

};
