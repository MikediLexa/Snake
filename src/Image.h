#pragma once
#include "SDL3/SDL_blendmode.h"
#include "SDL3/SDL_surface.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <string>

class Image {
public:

  Image(const std::string& File); 

  void Render(SDL_Surface* DestinationSurface) {
    if (!ImageSurface) return;
    SDL_BlitSurfaceScaled(
      ImageSurface, nullptr,
      DestinationSurface, &DestinationRectangle,
SDL_SCALEMODE_LINEAR
    );
  }


void SaveToFill(const std::string& Location) const {
	if(!ImageSurface) return;
	IMG_SavePNG(ImageSurface, Location.c_str());
}

 
  Image(const Image&);
  Image& operator=(const Image&);

  ~Image(); 

private:
  SDL_Surface* ImageSurface{nullptr};
  SDL_Rect DestinationRectangle{200, 50, 200, 200};
};