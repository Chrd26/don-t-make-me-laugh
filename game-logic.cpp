#include "game.h"

template<>
void Player<SDL_Surface, SDL_Texture, SDL_Renderer, SDL_Rect >::StateSetter(int state)
{
    currentPlayerState = state;
}

template<>
void Player<SDL_Surface, SDL_Texture, SDL_Renderer, SDL_Rect >::LoadPlayerFrames(SDL_Renderer *renderer)
{
    std::string extension = ".png";
    std::string frontIdleAnimName = "../Graphics/Player/Idling Front/YOU_idling-";
    std::string frontWalkAnimName = "../Graphics/Player/Walking Front/You_Walking_Ver2-";
    std::string backIdleAnimName = "../Graphics/Player/Idling Back/YOU_Idling_Back.png";
    std::string backWalkAnimName = "../Graphics/Player/Walking Back/YOU_Walking_Back-";
    std::string sideIdleAnimName = "../Graphics/Player/Idling Side/YOU_idling_Side-";
    std::string sideWalkAnimName = "Graphics/Player/Walking Side/YOU_Walking_Side-";

    int frontIdleFrame = 1, frontWalkFrame = 1;
    int sideIdleFrame = 1, sideWalkFrame = 1;
    int backWalkFrame = 1;


//      Load Front Anim Idle
    while (frontIdleFrame < 12)
    {
//      Use std::to string to convert to string
//      Source: https://stackoverflow.com/questions/5590381/how-to-convert-int-to-string-in-c
        std::string currentFrontIdleAnim = frontIdleAnimName;
        currentFrontIdleAnim.append(std::to_string(frontIdleFrame));
        currentFrontIdleAnim.append(extension);
        frontAnimIdleFrameTexture[frontIdleFrame] = IMG_LoadTexture(renderer, currentFrontIdleAnim.c_str());
        frontIdleFrame++;
    }

//     Load Front Anim Walk
    while (frontWalkFrame < 18)
    {
        std::string currentFrontWalkAnim = frontWalkAnimName;
        currentFrontWalkAnim.append(std::to_string(frontWalkFrame));
        currentFrontWalkAnim.append(extension);
        frontAnimWalkFrameTexture[frontWalkFrame] = IMG_LoadTexture(renderer, currentFrontWalkAnim.c_str());
        frontWalkFrame++;
    }

//    Load Back Anim Idle
    backAnimIdleFrameTexture = IMG_LoadTexture(renderer, backIdleAnimName.c_str());

//    Load Back Anim Walk
    while (backWalkFrame < 5)
    {
        std::string currentBackWalkAnim = backWalkAnimName;
        currentBackWalkAnim.append(std::to_string(backWalkFrame));
        currentBackWalkAnim.append(extension);
        backAnimWalkFrameTexture[backWalkFrame] = IMG_LoadTexture(renderer, currentBackWalkAnim.c_str());
        backWalkFrame++;
    }

//    Load Side Anim Idle
    while (sideIdleFrame < 10)
    {
        std::string currentSideIdleAnim = sideIdleAnimName;
        currentSideIdleAnim.append(std::to_string(sideIdleFrame));
        currentSideIdleAnim.append(extension);
        sideAnimIdleFrameTexture[sideIdleFrame] = IMG_LoadTexture(renderer, currentSideIdleAnim.c_str());
        sideIdleFrame++;
    }

//    Load Side Anim Walk
    while (sideWalkFrame < 19)
    {
        std::string currentSideWalkAnim = sideWalkAnimName;
        currentSideWalkAnim.append(std::to_string(sideWalkFrame));
        currentSideWalkAnim.append(extension);
        sideAnimIdleFrameTexture[sideWalkFrame] = IMG_LoadTexture(renderer, currentSideWalkAnim.c_str());
        sideWalkFrame++;
    }

    areTexturesLoaded = true;
}

template<>
void Player<SDL_Surface, SDL_Texture, SDL_Renderer, SDL_Rect>::PlayerAnimation(SDL_Surface *surface, SDL_Texture *texture)
{
    switch (currentPlayerState)
    {
        case idleFront:
            if (frontIdleCounter < 30)
            {

            }
            break;

        case walkFront:
            break;

        case idleSideLeft:
            break;

        case walkSideLeft:
            break;

        case idleSideRight:
            break;

        case walkSideRight:
            break;

        case idleBack:
            break;

        case walkBack:
            break;
    }
}

void Game::LoadMainMenuBackground()
{
    int currentFrame = 1, counter = 0;

    while (counter < 17)
    {
        std::string extension = ".png";
        std::string frameName = "../Graphics/Main Menu Background/Main_Menu_BG_-";
        frameName.append(std::to_string(currentFrame));
        frameName.append(extension);

        menuBG[counter] = IMG_Load(frameName.c_str());
        counter++;
        currentFrame++;
        hasMainMenuBGLoaded = true;

    }
}

void Game::ShowMenuBackground(int frame)
{
    SDL_Texture *currentFrame = SDL_CreateTextureFromSurface(renderer, menuBG[frame]);
    SDL_Rect bgRect = {0,
                       0,
                       menuBG[frame]->w,
                       menuBG[frame]->h};

    SDL_RenderCopy(renderer,
                   currentFrame,
                   nullptr,
                   &bgRect);

    SDL_DestroyTexture(currentFrame);
    currentFrame = nullptr;
}

void Game::StartMenu()
{

    menuFont = TTF_OpenFont("../Fonts/Aller_Rg.ttf", 35);

    SDL_Rect menuHolder = {static_cast<int>((float)screenWidth * 0.1f),
                           static_cast<int>((float)screenHeight * 0.8f),
                           300,
                           100};

    SDL_Rect menuHolderFill = {static_cast<int>((float)screenWidth * 0.1f),
                              static_cast<int>((float)screenHeight * 0.8f),
                              300,
                              100};

    SDL_SetRenderDrawColor(renderer,
                           0x00,
                           0x00,
                           0x00,
                           0xFF);
    SDL_RenderFillRect(renderer,
                       &menuHolderFill);

    SDL_SetRenderDrawColor(renderer,
                           0xFF,
                           0xFF,
                           0xFF,
                           0xFF);
    SDL_RenderDrawRect(renderer,
                       &menuHolder);

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
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

                            if (currState == gamePlay)
                            {
                                break;
                            }

                            break;

                        case SDLK_RIGHT:
                            if (currState == mainMenu)
                            {
                                currMainMenuSelection = exitSelected;
                                break;
                            }

                            if (currState == gamePlay)
                            {
                                break;
                            }

                            break;

                        case SDLK_UP:
                            if (currState == gamePlay)
                            {
                                break;
                            }

                            break;

                        case SDLK_DOWN:
                            if (currState == gamePlay)
                            {
                                break;
                            }

                            break;

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

                if (!hasMainMenuBGLoaded)
                {
                    LoadMainMenuBackground();
                }

                if (currentBGFrame < 16)
                {
                    ShowMenuBackground(currentBGFrame);

                    if (nextFrameClock == 20)
                    {
                        currentBGFrame++;
                        nextFrameClock = 0;
                    }else
                    {
                        nextFrameClock += 1;
                    }

                    StartMenu();

                    break;
                }else
                {
                    currentBGFrame = 0;
                    ShowMenuBackground(currentBGFrame);
                    currentBGFrame++;
                    StartMenu();
                    break;
                }


            case gamePlay:
                break;

            case gamePaused:
                break;
        }

        SDL_RenderPresent(renderer);
    }
}