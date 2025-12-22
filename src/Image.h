#pragma once
#include <SDL3/SDL.h>
#include <string>
#include <iostream>

class Image {
public:
  Image(const std::string& File, SDL_PixelFormat PreferredFormat = SDL_PIXELFORMAT_UNKNOWN)
    : ImageSurface{SDL_LoadBMP(File.c_str())} {
    	if (!ImageSurface) {
    		std::cout << "Failed to load image " << File << ":\n" << SDL_GetError() << '\n';
    	} else {
    		SourceRectangle = {
    				0,
					0,
					ImageSurface->w,
					ImageSurface->h
    		};
    		SetDestinationRectangle({ 0, 0, 600, 300 });
    	}
    	if (PreferredFormat != SDL_PIXELFORMAT_UNKNOWN)
    	{
    		SDL_Surface* Converted{ SDL_ConvertSurface(ImageSurface, PreferredFormat) };
    		if (Converted) {
    			SDL_DestroySurface(ImageSurface);
    			ImageSurface = Converted;
    		} else {
    			std::cout << "Error converting surface: " << SDL_GetError() << '\n';
    		}
    	}
    }

  ~Image(){ if (ImageSurface) {  SDL_DestroySurface(ImageSurface);  } }

  Image(const Image&) = delete;
  Image& operator=(const Image&) = delete;


  void Render(SDL_Surface* DestinationSurface)
  {
    if (!ImageSurface) return;
    SDL_BlitSurfaceScaled(
    		ImageSurface,
			&SourceRectangle,
			DestinationSurface,
			&DestinationRectangle,
			SDL_SCALEMODE_LINEAR);
  }

  void SetDestinationRectangle( SDL_Rect Destination)
  {
	  float SourceRatio{ SourceRectangle.w / static_cast<float>(SourceRectangle.h) };
	  float DestinationRatio{ Destination.w / static_cast<float>(Destination.h) };
	  DestinationRectangle = Destination;

	  std::cout << "\n[Aspect Ratio] Source: " << SourceRatio
			  << ", Destination: " << DestinationRatio;
  }

private:
  SDL_Surface* ImageSurface{nullptr};
  SDL_Rect SourceRectangle{};
  SDL_Rect DestinationRectangle { 10, 5, 600, 300 };
};
