#pragma once
#include "Functions.hpp"
#include "Game.hpp"

class Map {
public:
	Map();
	~Map();
	void Draw();
	void Load(int arr[20][25]);

private:
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];

};