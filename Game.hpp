#pragma once
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <iostream>
#include <memory>
#include "Functions.hpp"

class Game {
public:
	Game(const char* Title, int screenWidth, int screenHeight);
	bool InitWindow();
	void Tick();
	void Update();
	void Draw();
	inline bool Running() { return isRunning; }
	void DrawObjects();
	void HandleEvents();

private:
	// Window related
	int screenWidth, screenHeight;
	int windowFlags = SDL_RENDERER_ACCELERATED;
	const char* title;
	SDL_Window* window;
	SDL_Renderer* renderer;
	//
	bool isRunning;
	


};