#pragma once
#include "SDL_image.h"

namespace Functions {

	constexpr auto LoadTexture = [](const char* _filename, SDL_Renderer* _renderer) {
		SDL_Surface* tempSurface = IMG_Load(_filename);
		SDL_Texture* object = SDL_CreateTextureFromSurface(_renderer, tempSurface);
		SDL_FreeSurface(tempSurface);
		return object;
		};
};