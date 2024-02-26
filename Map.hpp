#pragma once
#include "Functions.hpp"
#include "Game.hpp"

class Map {
public:
	Map();
	~Map(){}
	void Draw();

private:
	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect dstRect;



};