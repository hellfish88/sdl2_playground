#pragma once
#include "SDL_image.h"
//#include "Game.hpp"

namespace Functions {

	constexpr auto LoadTexture = [](const char* _filename, SDL_Renderer* _renderer) {
		SDL_Surface* tempSurface = IMG_Load(_filename);
		SDL_Texture* object = SDL_CreateTextureFromSurface(_renderer, tempSurface);
		SDL_FreeSurface(tempSurface);
		return object;
		};

	constexpr auto Draw = [](SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect) {
		SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
		};
};