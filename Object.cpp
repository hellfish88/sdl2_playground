#include "Object.hpp"

Object::Object(const char* _filename, int _x, int _y)
	: x(_x), y(_y){
	texture = Functions::LoadTexture(_filename, Game::renderer);
}
Object::~Object() {
	SDL_DestroyTexture(texture);
}

void Object::Draw() {
	SDL_RenderCopyEx(Game::renderer, texture, nullptr, &dstRect, 0, NULL, direction);
	//SDL_RenderCopy(renderer, texture, NULL, NULL);
}

void Object::Update() {
	dstRect.x = x;
	dstRect.y = y;
}

void Object::SetX(int _x, bool definitePos) {

	if (_x < 0) {
		direction = SDL_FLIP_NONE;
	} else {
		direction = SDL_FLIP_HORIZONTAL;
	}

	if (definitePos) 
		x = _x;
	else 
		x += _x;
	Update();
}

void Object::SetY(int _y, bool definitePos) {
	if (definitePos)
		y = _y;
	else 
		y += _y;
	Update();
}