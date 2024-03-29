#include "game.h"

template<>
Player<SDL_Surface, SDL_Texture, SDL_Renderer >::~Player()
{
    for (auto &i : frontAnimIdleFrameSurface)
    {
        if (i == nullptr)
        {
            break;
        }

        SDL_FreeSurface(i);
    }

    for (auto &j : frontAnimWalkFrameSurface)
    {
        if (j == nullptr)
        {
            break;
        }

        SDL_FreeSurface(j);
    }

    for (auto &k : backAnimWalkFrameSurface)
    {
        if (k == nullptr)
        {
            break;
        }

        SDL_FreeSurface(k);
    }

    for (auto &l : sideAnimIdleFrameSurface)
    {
        if (l == nullptr)
        {
            break;
        }

        SDL_FreeSurface(l);
    }

    for (auto &m : sideAnimWalkFrameSurface)
    {
        if (m == nullptr)
        {
            break;
        }

        SDL_FreeSurface(m);
    }

    if (frameTexture != nullptr)
    {
        SDL_DestroyTexture(frameTexture);
    }

    if (backAnimIdleFrameSurface != nullptr)
    {
        SDL_FreeSurface(backAnimIdleFrameSurface);
    }
}


template<>
bool Player<SDL_Surface, SDL_Texture, SDL_Renderer>::hasLoadedTextures() const
{
    return areTexturesLoaded;
}

template<>
void Player<SDL_Surface, SDL_Texture, SDL_Renderer>::StateSetter(int state)
{
    currentPlayerState = state;
}

template<>
void Player<SDL_Surface, SDL_Texture, SDL_Renderer>::LoadPlayerFrames(SDL_Renderer *renderer)
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
    int arrCounter = 0;

//      Load Front Anim Idle
    while (frontIdleFrame < 12)
    {
//      Use std::to string to convert to string
//      Source: https://stackoverflow.com/questions/5590381/how-to-convert-int-to-string-in-c
        std::string currentFrontIdleAnim = frontIdleAnimName;
        currentFrontIdleAnim.append(std::to_string(frontIdleFrame));
        currentFrontIdleAnim.append(extension);
        frontAnimIdleFrameSurface[arrCounter] = IMG_Load(currentFrontIdleAnim.c_str());
        frontIdleFrame++;
        arrCounter++;
    }

    arrCounter = 0;

//     Load Front Anim Walk
    while (frontWalkFrame < 18)
    {
        std::string currentFrontWalkAnim = frontWalkAnimName;
        currentFrontWalkAnim.append(std::to_string(frontWalkFrame));
        currentFrontWalkAnim.append(extension);
        frontAnimWalkFrameSurface[arrCounter] = IMG_Load(currentFrontWalkAnim.c_str());
        frontWalkFrame++;
        arrCounter++;
    }

    arrCounter = 0;

//    Load Back Anim Idle
    backAnimIdleFrameSurface = IMG_Load(backIdleAnimName.c_str());

//    Load Back Anim Walk
    while (backWalkFrame < 5)
    {
        std::string currentBackWalkAnim = backWalkAnimName;
        currentBackWalkAnim.append(std::to_string(backWalkFrame));
        currentBackWalkAnim.append(extension);
        backAnimWalkFrameSurface[arrCounter] = IMG_Load(currentBackWalkAnim.c_str());
        backWalkFrame++;
        arrCounter++;
    }

    arrCounter = 0;

//    Load Side Anim Idle
    while (sideIdleFrame < 10)
    {
        std::string currentSideIdleAnim = sideIdleAnimName;
        currentSideIdleAnim.append(std::to_string(sideIdleFrame));
        currentSideIdleAnim.append(extension);
        sideAnimIdleFrameSurface[arrCounter] = IMG_Load(currentSideIdleAnim.c_str());
        sideIdleFrame++;
        arrCounter++;
    }

    arrCounter = 0;

//    Load Side Anim Walk
    while (sideWalkFrame < 19)
    {
        std::string currentSideWalkAnim = sideWalkAnimName;
        currentSideWalkAnim.append(std::to_string(sideWalkFrame));
        currentSideWalkAnim.append(extension);
        sideAnimIdleFrameSurface[arrCounter] = IMG_Load(currentSideWalkAnim.c_str());
        sideWalkFrame++;
        arrCounter++;
    }

    arrCounter = 0;
    areTexturesLoaded = true;
}

template<>
void Player<SDL_Surface, SDL_Texture, SDL_Renderer>::PlayerAnimation(SDL_Renderer *renderer)
{
    SDL_Rect frameHolder;
    switch (currentPlayerState)
    {
        case idleFront:

            if (animClock < 500) {
                frameHolder = {static_cast<int>(playerX),
                               static_cast<int>(playerY),
                               static_cast<int>((float)frontAnimIdleFrameSurface[curAnim]->w * 0.2f),
                               static_cast<int>((float)frontAnimIdleFrameSurface[curAnim]->h * 0.2f)};

                frameTexture = SDL_CreateTextureFromSurface(renderer, frontAnimIdleFrameSurface[curAnim]);

                SDL_RenderCopy(renderer,
                               frameTexture,
                               nullptr,
                               &frameHolder);
                animClock++;
                std::cout << animClock << std::endl;
                break;
            }else{

                if (curAnim >= frontAnimIdleFrameSurface.size())
                {
                    animClock = 0;
                    curAnim = 0;
                }

                if (animClock < 520)
                {
                    frameHolder = {static_cast<int>(playerX),
                                   static_cast<int>(playerY),
                                   static_cast<int>((float)frontAnimIdleFrameSurface[curAnim]->w * 0.2f),
                                   static_cast<int>((float)frontAnimIdleFrameSurface[curAnim]->h * 0.2f)};

                    frameTexture = SDL_CreateTextureFromSurface(renderer, frontAnimIdleFrameSurface[curAnim]);

                    SDL_RenderCopy(renderer,
                                   frameTexture,
                                   nullptr,
                                   &frameHolder);
                    animClock++;
                    break;
                }

                frameHolder = {static_cast<int>(playerX),
                               static_cast<int>(playerY),
                               static_cast<int>((float)frontAnimIdleFrameSurface[curAnim]->w * 0.2f),
                               static_cast<int>((float)frontAnimIdleFrameSurface[curAnim]->h * 0.2f)};

                frameTexture = SDL_CreateTextureFromSurface(renderer, frontAnimIdleFrameSurface[curAnim]);

                SDL_RenderCopy(renderer,
                               frameTexture,
                               nullptr,
                               &frameHolder);
                animClock = 500;
                animClock++;
                curAnim++;
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

    while (counter < 16)
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

void Game::UnloadMainMenuElements()
{
    int unloadCounter = 0;

    while (unloadCounter < menuBG.size())
    {
        SDL_FreeSurface(menuBG[unloadCounter]);
        unloadCounter++;
    }

    hasMainMenuBGLoaded = false;
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

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00,
                           0x00, 0xFF);
    SDL_RenderFillRect(renderer,
                       &menuHolderFill);

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF,
                           0xFF, 0xFF);
    SDL_RenderDrawRect(renderer, &menuHolder);

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_Rect startButton = {static_cast<int>((float)screenWidth * 0.12f),
                            static_cast<int>((float)screenHeight * 0.85f),
                            0, 0};
    SDL_Rect exitButton = {static_cast<int>((float)screenWidth * 0.25f),
                            static_cast<int>((float)screenHeight * 0.85f),
                            0, 0};

    SDL_Color selectedColor = {0x00, 0xFF, 0x00};
    SDL_Color unselectedColor = {0xFF, 0xFF, 0xFF};

    switch (currMainMenuSelection)
    {
        case startSelected:
            startGameSurface = TTF_RenderText_Solid(menuFont, "Start",
                                                    selectedColor);
            startButton.h = startGameSurface->h;
            startButton.w = startGameSurface->w;
            startGameTexture = SDL_CreateTextureFromSurface(renderer,
                                                            startGameSurface);

            exitGameSurface = TTF_RenderText_Solid(menuFont, "Exit",
                                                    unselectedColor);
            exitButton.h = exitGameSurface->h;
            exitButton.w = exitGameSurface->w;
            exitGameTexture = SDL_CreateTextureFromSurface(renderer,
                                                           exitGameSurface);

            SDL_RenderCopy(renderer, exitGameTexture, nullptr,
                           &exitButton);

            SDL_RenderCopy(renderer, startGameTexture, nullptr,
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
            startGameSurface = TTF_RenderText_Solid(menuFont, "Start",
                                                    unselectedColor);
            startButton.h = startGameSurface->h;
            startButton.w = startGameSurface->w;
            startGameTexture = SDL_CreateTextureFromSurface(renderer,
                                                            startGameSurface);

            exitGameSurface = TTF_RenderText_Solid(menuFont, "Exit",
                                                   selectedColor);
            exitButton.h = exitGameSurface->h;
            exitButton.w = exitGameSurface->w;
            exitGameTexture = SDL_CreateTextureFromSurface(renderer,
                                                           exitGameSurface);

            SDL_RenderCopy(renderer, exitGameTexture, nullptr,
                           &exitButton);

            SDL_RenderCopy(renderer, startGameTexture, nullptr,
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
    window = SDL_CreateWindow("Don't make me laugh", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, screenWidth,
                              screenHeight, SDL_WINDOW_SHOWN);

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

    if (currState == mainMenu)
    {
        UnloadMainMenuElements();
    }

    if (currState == gamePlay)
    {

    }
}


Game::Game()
{
    if(!GameInit())
    {
        exit(-1);
    }

    bool quit = false;
    SDL_Event eventHandler;

//    Use keyboard events to make proper movement
//    Read here: https://www.appsloveworld.com/cplus/100/134/sdl-2-0-key-repeat-and-delay

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
                                player.playerX -= 10.0f;
                                break;
                            }

                        case SDLK_RIGHT:
                            if (currState == mainMenu)
                            {
                                currMainMenuSelection = exitSelected;
                                break;
                            }

                            if (currState == gamePlay)
                            {
                                player.playerX += 10.0f;
                                break;
                            }

                        case SDLK_UP:
                            if (currState == gamePlay)
                            {
                                player.playerY -= 10.0f;
                                break;
                            }

                            break;

                        case SDLK_DOWN:
                            if (currState == gamePlay)
                            {
                                player.playerY += 10.0f;
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
                                UnloadMainMenuElements();
                                player.playerX = 200;
                                player.playerY = 50;
                                player.LoadPlayerFrames(renderer);
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
                                UnloadMainMenuElements();
                                player.playerX = (float)screenWidth/2;
                                player.playerY = (float)screenHeight/2;
                                std::cin.get();

                                break;
                            }
                    }

                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00,
                               0x00, 0x00);
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

                    if (nextFrameClock == 15)
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
                if (player.hasLoadedTextures())
                {
                    player.PlayerAnimation(renderer);
                }
                break;

            case gamePaused:
                break;
        }

        SDL_RenderPresent(renderer);
    }
}