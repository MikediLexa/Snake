#pragma once
#include <SDL3/SDL.h>
#include "Rectangle.h"

class GreenRectangle : public Rectangle {
public:
	GreenRectangle(const SDL_Rect& Rect)
		: Rectangle{Rect}{
			SetColor({0,255,0,255});
		}

	void Render(SDL_Surface* Surface) const override
	{
		for (auto& Rectangle : Rectangles) { Rectangle->Render(Surface); }
	}
};
