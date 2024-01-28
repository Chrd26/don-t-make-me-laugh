#pragma  once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "player-header.h"
#include "SDL_image.h"
#include <string>

#define screenWidth 1280
#define screenHeight 720

class Game
{

//  Player Components
private:
    Player<SDL_Surface, SDL_Texture, SDL_Renderer> player;

//  Game State
private:
    int currState = 0;

    enum GameState{
        mainMenu = 0,
        gamePlay,
        gamePaused
    };
//  Game Components
private:
    TTF_Font *font = nullptr;
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

//    Game constructor and destructor
public:
    Game();
    ~Game();

//  Functionality
private:
    bool GameInit();

//  Menu
private:
    enum MenuSelections{
        startSelected = 0,
        exitSelected
    };

    int currMainMenuSelection = startSelected;
    SDL_Surface *startGameSurface = nullptr, *exitGameSurface = nullptr;
    SDL_Texture *startGameTexture = nullptr, *exitGameTexture = nullptr;
    TTF_Font *menuFont = nullptr;
    std::array<SDL_Surface*, 16> menuBG;
    bool hasMainMenuBGLoaded = false;
    int currentBGFrame = 0;
    int nextFrameClock = 0;

    void StartMenu();
    void ShowMenuBackground(int frame);
    void LoadMainMenuBackground();
    void UnloadMainMenuElements();

};
