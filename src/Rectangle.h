/*
 * Rectangle.h
 *
 *  Created on: 20.12.2025
 *      Author: mike
 */

#pragma once
#include <SDL3/SDL.h>
#include <iostream>

class Rectangle {
public:
	Rectangle(
			const SDL_Rect& Rect
	)
		: Rect{Rect}
	{}


	void SetColor(const SDL_Color& NewColor) { Color = NewColor;}
	SDL_Color GetColor() const { return Color; }

	void SetHoverColor(const SDL_Color& NewColor){ HoverColor = NewColor; }
	SDL_Color GetHoverColor() const { return HoverColor; }

	void Render(SDL_Surface* Surface) const {
		auto [r,g,b,a] { isPointerHovering ? HoverColor : Color };

		const auto* Fmt = SDL_GetPixelFormatDetails(Surface->format);

		SDL_FillSurfaceRect(
			Surface,
			&Rect,
			SDL_MapRGB(Fmt, nullptr, r, g, b)
		);
	}

	void HandleEvent(SDL_Event& E)
	{
		if(E.type == SDL_EVENT_MOUSE_MOTION)
		{
			isPointerHovering = isWithinRect( (int)E.motion.x, (int)E.motion.y );
		}
		else if (E.type == SDL_EVENT_WINDOW_MOUSE_LEAVE)
		{
		  isPointerHovering = false;
		}
		else if (E.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (isPointerHovering
				&& E.button.button == SDL_BUTTON_LEFT)
			{
				std::cout << "A left-click happend on me!" << std::endl;
			}
		}
	}


private:
	SDL_Rect Rect;
	SDL_Color Color{255,0,0,255};
	SDL_Color HoverColor{0,0,255,255};

	bool isPointerHovering{false};
	bool isWithinRect(int x, int y) {
	    // Too far left
	    if (x < Rect.x) return false;
	    // Too far right
	    if (x > Rect.x + Rect.w) return false;
	    // Too far up
	    if (y < Rect.y) return false;
	    // Too far down
	    if (y > Rect.y + Rect.h) return false;
		return true;
	}
};

