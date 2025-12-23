#include "Image.h"
#include "SDL3/SDL_surface.h"

  Image::Image(const std::string& File)
  : ImageSurface{IMG_Load(File.c_str())} {
    if (!ImageSurface) {
      std::cout << "Failed to load image: "
        << File << ":\n  " << SDL_GetError() << '\n';
    }
	SDL_SetSurfaceBlendMode(
		ImageSurface, 
		SDL_BLENDMODE_BLEND
		); 
  }

  Image::Image(const Image& Source)
	: DestinationRectangle(Source.DestinationRectangle) {
		if (Source.ImageSurface){
		ImageSurface = SDL_ConvertSurface(Source.ImageSurface, Source.ImageSurface->format);
	    }
  }

	Image& Image::operator=(const Image& Source) {
		if (this == &Source) {
		return *this;
  	}
	if(ImageSurface) {
		SDL_DestroySurface(ImageSurface);
	}

if (Source.ImageSurface) {
	ImageSurface = SDL_ConvertSurface(ImageSurface, ImageSurface->format);
} else { ImageSurface = nullptr; }

DestinationRectangle = Source.DestinationRectangle;

	return *this;
  }


 Image::~Image() {
    if (ImageSurface) {
      SDL_DestroySurface(ImageSurface);
    }
  }