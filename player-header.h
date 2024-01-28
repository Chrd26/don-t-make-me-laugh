#pragma once

template<typename S,typename T, typename  R>
class Player
{
//    Player state
private:

    enum PlayerState
    {
        idleFront = 0,
        walkFront,
        idleSideRight,
        walkSideRight,
        idleSideLeft,
        walkSideLeft,
        idleBack,
        walkBack
    };

//  Player components
private:
    int currentPlayerState;
    std::array<S*, 11> frontAnimIdleFrameSurface;
    std::array<S*, 17> frontAnimWalkFrameSurface;
    T* backAnimIdleFrameTexture = nullptr;
    std::array <S*, 4> backAnimWalkFrameSurface;
    std::array <S*, 9> sideAnimIdleFrameSurface;
    std::array <S*, 18> sideAnimWalkFrameSurface;
    T *frameTexture = nullptr;
    int animClock = 0;
    //int frontIdleCounter = 0;
    int curAnim = 0;

public:
    float playerX = 0, playerY = 0;
    bool areTexturesLoaded = false;

public:
    virtual void PlayerAnimation(R *renderer);
    virtual void StateSetter(int state);
    virtual void LoadPlayerFrames(R *renderer);
    //virtual void unloadPlayerFrames();

//     This is a static function because it is
//      already defined, use static to declare it
    bool hasLoadedTextures() const;
};
