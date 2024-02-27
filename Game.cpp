#include "Game.hpp"

//SDL_Texture* temple = nullptr;

std::shared_ptr<Object> Player = nullptr;

SDL_Renderer* Game::renderer = nullptr;
std::shared_ptr<Map> map = nullptr;



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

    Player = std::make_shared<Object>("assets/dog.png", 10, 10 );
    map = std::make_shared<Map>();

}

void Game::HandleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    keystate = SDL_GetKeyboardState(NULL);

    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    //case SDL_KEYDOWN:
    //    switch (event.key.keysym.sym) {
    //    case SDLK_RIGHT:
    //        Player->SetX(movementSpeed);
    //        break;
    //    case SDLK_LEFT:
    //        Player->SetX(movementSpeed * -1);
    //        break;
    //    case SDLK_UP:
    //        Player->SetY(movementSpeed * -1);
    //        break;
    //    case SDLK_DOWN:
    //        Player->SetY(movementSpeed);
    //        break;
    //    case (SDLK_DOWN && SDLK_RIGHT):
    //        Player->SetX(movementSpeed);
    //        Player->SetY(movementSpeed);
        //default:
        //    break;
        //}

    default:
        break;

    }
    
    if      (keystate[SDL_SCANCODE_RIGHT] && keystate[SDL_SCANCODE_DOWN]) { Player->SetX(movementSpeed); Player->SetY(movementSpeed); }
    else if (keystate[SDL_SCANCODE_RIGHT] && keystate[SDL_SCANCODE_UP]) { Player->SetX(movementSpeed); Player->SetY(movementSpeed * -1); }
    else if (keystate[SDL_SCANCODE_LEFT] && keystate[SDL_SCANCODE_UP]) { Player->SetX(movementSpeed * -1 ); Player->SetY(movementSpeed * -1); }
    else if (keystate[SDL_SCANCODE_LEFT] && keystate[SDL_SCANCODE_DOWN]) { Player->SetX(movementSpeed * -1); Player->SetY(movementSpeed); }
    else if (keystate[Settings::SDL_SCANCODE_DOWNN])  Player->SetY(movementSpeed);
    else if (keystate[Settings::SDL_SCANCODE_UPP]) Player->SetY(movementSpeed * -1);
    else if (keystate[Settings::SDL_SCANCODE_LEFTT]) Player->SetX(movementSpeed * -1);
    else if (keystate[Settings::SDL_SCANCODE_RIGHTT]) Player->SetX(movementSpeed);


}

void Game::Tick() {

    HandleEvents();

    Update();
    Draw();

}

void Game::Update() { // Game logic

    if (Player->GetX() + Player->GetW() >= screenWidth) {
        Player->SetX(0, true);
        Player->SetY(32);
    } else {

        //Player->SetX(1);
    }

}

void Game::Draw() {
    SDL_RenderClear(renderer);
    //
    map->Draw();

    //SDL_RenderCopy(renderer, temple, NULL, NULL);
    Player->Draw();

    ///
    SDL_RenderPresent(renderer);
}
