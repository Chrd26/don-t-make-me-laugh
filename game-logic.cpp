#include "game.h"

void Player::StateSetter(int state)
{
    currentPlayerState = state;
}

void Player::PlayerAnimation()
{
    std::string extension = ".png";
    std::string currentFrontIdleAnim = "../Graphics/Player/Idling Front/YOU_idling-";
    std::string currentFrontWalkAnime = "../Graphics/Player/Walking Front/You_Walking_Ver2-";
    std::string currentBackIdleAnim = "../Graphics/Player/Idling Back/YOU_Idling_Back";
    std::string currentBackWalkAnim = "../Graphics/Player/Walking Back/YOU_Walking_Back-";
    std::string currentSideIdleAnim = "../Graphics/Player/Idling Side/YOU_idling_Side-";
    std::string currentSideWalkAnim = "Graphics/Player/Walking Side/YOU_Walking_Side-";

    int frontIdleFrame = 1, frontWalkFrame = 1;
    int sideIdleFrame = 1, sideWalkFrame = 1;
    int backWalkFrame = 1;

//    Use std::to string to convert to string
//    Source: https://stackoverflow.com/questions/5590381/how-to-convert-int-to-string-in-c
    currentFrontIdleAnim += std::to_string(frontIdleFrame) + extension;
    std::cout << currentFrontIdleAnim << std::endl;
}

void Game::StartMenu()
{

    menuFont = TTF_OpenFont("../Fonts/Aller_Rg.ttf", 35);

    SDL_SetRenderDrawColor(renderer,
                           0xFF,
                           0xFF,
                           0xFF,
                           0xFF);
    SDL_Rect menuHolder = {static_cast<int>((float)screenWidth * 0.1f),
                           static_cast<int>((float)screenHeight * 0.8f),
                           300,
                           100};
    SDL_RenderDrawRect(renderer,
                       &menuHolder);

    SDL_Rect startButton = {static_cast<int>((float)screenWidth * 0.12f),
                            static_cast<int>((float)screenHeight * 0.85f),
                            0,
                            0};

    SDL_Rect exitButton = {static_cast<int>((float)screenWidth * 0.25f),
                            static_cast<int>((float)screenHeight * 0.85f),
                            0,
                            0};

    SDL_Color selectedColor = {0x00,
                               0xFF,
                               0x00};
    SDL_Color unselectedColor = {0xFF,
                                 0xFF,
                                 0xFF};

    switch (currMainMenuSelection)
    {
        case startSelected:
            startGameSurface = TTF_RenderText_Solid(menuFont,
                                                    "Start",
                                                    selectedColor);
            startButton.h = startGameSurface->h;
            startButton.w = startGameSurface->w;
            startGameTexture = SDL_CreateTextureFromSurface(renderer,
                                                            startGameSurface);

            exitGameSurface = TTF_RenderText_Solid(menuFont,
                                                    "Exit",
                                                    unselectedColor);
            exitButton.h = exitGameSurface->h;
            exitButton.w = exitGameSurface->w;
            exitGameTexture = SDL_CreateTextureFromSurface(renderer,
                                                           exitGameSurface);

            SDL_RenderCopy(renderer,
                           exitGameTexture,
                           nullptr,
                           &exitButton);

            SDL_RenderCopy(renderer,
                           startGameTexture,
                           nullptr,
                           &startButton);

            SDL_FreeSurface(startGameSurface);
            SDL_FreeSurface(exitGameSurface);
            SDL_DestroyTexture(startGameTexture);
            SDL_DestroyTexture(exitGameTexture);
            TTF_CloseFont(menuFont);

            startGameSurface = nullptr;
            exitGameSurface = nullptr;
            startGameTexture = nullptr;
            exitGameTexture = nullptr;
            menuFont = nullptr;

            break;

        case exitSelected:
            startGameSurface = TTF_RenderText_Solid(menuFont,
                                                    "Start",
                                                    unselectedColor);
            startButton.h = startGameSurface->h;
            startButton.w = startGameSurface->w;
            startGameTexture = SDL_CreateTextureFromSurface(renderer,
                                                            startGameSurface);

            exitGameSurface = TTF_RenderText_Solid(menuFont,
                                                   "Exit",
                                                   selectedColor);
            exitButton.h = exitGameSurface->h;
            exitButton.w = exitGameSurface->w;
            exitGameTexture = SDL_CreateTextureFromSurface(renderer,
                                                           exitGameSurface);

            SDL_RenderCopy(renderer,
                           exitGameTexture,
                           nullptr,
                           &exitButton);

            SDL_RenderCopy(renderer,
                           startGameTexture,
                           nullptr,
                           &startButton);

            SDL_FreeSurface(startGameSurface);
            SDL_FreeSurface(exitGameSurface);
            SDL_DestroyTexture(startGameTexture);
            SDL_DestroyTexture(exitGameTexture);
            TTF_CloseFont(menuFont);

            startGameSurface = nullptr;
            exitGameSurface = nullptr;
            startGameTexture = nullptr;
            exitGameTexture = nullptr;
            menuFont = nullptr;

            break;
    }
}

bool Game::GameInit()
{
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0 || TTF_Init() < 0 || IMG_Init(IMG_INIT_PNG) < 0)
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

    if (renderer == nullptr)
    {
        std::cout << "Failed to create renderer" << std::endl;
        return false;
    }

    return true;
}

// Clean up
Game::~Game()
{
    TTF_CloseFont(font);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    font = nullptr;
    window = nullptr;
    renderer = nullptr;
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

                case SDL_KEYDOWN:

                    switch (eventHandler.key.keysym.sym)
                    {
                        case SDLK_LEFT:
                            if (currState == mainMenu)
                            {
                                currMainMenuSelection = startSelected;
                                break;
                            }

                        case SDLK_RIGHT:
                            if (currState == mainMenu)
                            {
                                currMainMenuSelection = exitSelected;
                                break;
                            }

                        case SDLK_RETURN:
                            if (currState == mainMenu && currMainMenuSelection == exitSelected)
                            {
                                quit = true;
                                break;
                            }

                            if (currState == mainMenu && currMainMenuSelection == startSelected)
                            {
                                currState = gamePlay;
                                break;
                            }

                        case SDLK_RETURN2:
                            if (currState == mainMenu && currMainMenuSelection == exitSelected)
                            {
                                quit = true;
                                break;
                            }

                            if (currState == mainMenu && currMainMenuSelection == startSelected)
                            {
                                currState = gamePlay;
                                break;
                            }
                    }

                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer,
                               0x00,
                               0x00,
                               0x00,
                               0x00);
        SDL_RenderClear(renderer);

        switch (currState)
        {
            case mainMenu:
                StartMenu();
                break;

            case gamePlay:
                break;

            case gamePaused:
                break;
        }

        SDL_RenderPresent(renderer);
    }
}