#pragma once
#include "SDL3/SDL_error.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_surface.h"

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>
#include <string>

class Text {
  public:
    Text(const std::string& Content,
         std::string fontPath, float Size = 25.0f)
        : Font{TTF_OpenFont(fontPath.c_str(),
                            Size)} {
        if (!Font) {
            std::cout << "Error loading font: "
                      << SDL_GetError() << '\n';
        }
        CreateSurface(Content);
    }

    void Render(SDL_Surface* DestinationSurface) {
        if (!TextSurface) return;
        SDL_BlitSurfaceScaled(
            TextSurface, &SourceRectangle,
            DestinationSurface,
            &DestinationRectangle,
            SDL_SCALEMODE_LINEAR);
    }

    void SetFontSize(float NewSize) {
        TTF_SetFontSize(Font, NewSize);
    }

    ~Text() {
        SDL_DestroySurface(TextSurface);
        if (TTF_WasInit()) {
            TTF_CloseFont(Font);
        }
    }

    Text(const Text&) = delete;
    Text& operator=(const Text&) = delete;

  private:
    void
    CreateSurface(const std::string& Content) {
        SDL_Surface* newSurface{
            TTF_RenderText_Blended(
                Font, Content.c_str(), 0,
                {255, 255, 255, 255})};

        if (newSurface) {
            SDL_DestroySurface(TextSurface);
            TextSurface = newSurface;
        } else {
            std::cout
                << "Error creating TextSurface: "
                << SDL_GetError() << '\n';
        }
        SourceRectangle = {0, 0, TextSurface->w,
                           TextSurface->h};

        DestinationRectangle = {50, 50,
                                TextSurface->w,
                                TextSurface->h};
    }

    TTF_Font* Font{nullptr};

    SDL_Surface* TextSurface{nullptr};
    SDL_Rect SourceRectangle{};
    SDL_Rect DestinationRectangle{};
};