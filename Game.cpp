#include "Game.hpp"

SDL_Texture* temple = nullptr;

Game::Game(const char* _title, int _screenWidth, int _screenHeight)
    : title(_title), screenWidth(_screenWidth), screenHeight(_screenHeight){

    Game::InitWindow();
}

bool Game::InitWindow() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, windowFlags);

    if (!window) {
        std::cerr << "Window could not be created. SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }


    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Failed to create renderer" << SDL_GetError() << std::endl;
        return false;
    }


    DrawObjects();

    return true;
}

void Game::DrawObjects() {

    temple = Functions::LoadTexture("assets/temple.png", renderer);

}

void Game::HandleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;

    }
}

void Game::Tick() {

    HandleEvents();

    Update();
    Draw();

}

void Game::Update() { // Game logic


}

void Game::Draw() {
    SDL_RenderClear(renderer);
    //

    SDL_RenderCopy(renderer, temple, NULL, NULL);

    ///
    SDL_RenderPresent(renderer);
}
