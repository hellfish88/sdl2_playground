#pragma once 
#include "Functions.hpp"
#include "Game.hpp"

class Object {
public:
	Object(const char* _namefile, int _x, int _y);
	//Object(const char* _namefile, SDL_Renderer* _renderer, int _x, int _y);
	~Object();
	void Draw();
	void Update();
	// Setters
	void SetX(int, bool = false); // incremental
	void SetY(int, bool = false);
	// Getters
	inline int GetY() const { return dstRect.y; }
	inline int GetX() const { return dstRect.x; }
	inline int GetW() const { return dstRect.w; }

private:
	SDL_RendererFlip direction = SDL_FLIP_NONE;
	//double angle = 0;
	SDL_Texture* texture;
	//SDL_Renderer* renderer;
	int x, y;
	SDL_Rect srcRect{
		.x = 0,
		.y = 0,
		.w = 64,
		.h = 64
	};
	SDL_Rect dstRect {
		.x = x,
		.y = y,
		.w = srcRect.w * 2,
		.h = srcRect.h * 2
	};
};