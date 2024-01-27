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
    Player<SDL_Surface, SDL_Texture> player();

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
    SDL_Surface *startGameSurface = nullptr;
    SDL_Texture *startGameTexture = nullptr;
    SDL_Surface *exitGameSurface = nullptr;
    SDL_Texture *exitGameTexture = nullptr;
    TTF_Font *menuFont = nullptr;

    void StartMenu();

};
