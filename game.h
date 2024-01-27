#pragma  once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

#define screenWidth 1280
#define screenHeight 720

class Game
{

private:
    enum GameState
    {
        mainMenu = 0,
        gamePlay,
        gamePaused
    };
//    Game Components
private:
    TTF_Font *font;
    SDL_Window *window;
    SDL_Renderer *renderer;

//    Game constructor and destructor
public:
    Game();
    ~Game();

//    Functionality
private:
    bool GameInit();

};
