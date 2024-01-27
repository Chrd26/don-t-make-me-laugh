#pragma  once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

#define screenWidth 1280
#define screenHeight 720

class Game
{
//    Game Components
private:
    TTF_Font *font;
    SDL_Window *window;

//    Game constructor and destructor
public:
    Game();
    ~Game();

//    Functionality
private:
    bool GameInit();

};
