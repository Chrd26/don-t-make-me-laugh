#include "game.h"

bool Game::GameInit()
{
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0 || TTF_Init() < 0)
    {
        std::cout << "Failed to initialise SDL" << std::endl;
        return false;
    }

//    Set up window
    window = SDL_CreateWindow("Don't make me laugh",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              screenWidth,
                              screenHeight,
                              SDL_WINDOW_SHOWN);

//    Set up Font
    font = TTF_OpenFont("../Fonts/Aller_Rg.ttf", 20);

    if (font == nullptr)
    {
        std::cout << "Failed to open fonts" << std::endl;
        return false;
    }

//    Renderer

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    return true;
}


Game::~Game()
{
    TTF_CloseFont(font);
    SDL_DestroyWindow(window);
}


Game::Game()
{
    if(!GameInit())
    {
        exit(-1);
    }

    bool quit = false;
    SDL_Event eventHandler;


    while (!quit)
    {
        while(SDL_PollEvent(&eventHandler) != 0)
        {
            switch (eventHandler.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
            }
        }

    }
}