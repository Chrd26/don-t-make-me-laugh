#pragma once

template<typename S,typename T>
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
    S *frameSurface;
    T *frameTexture;
    bool isPlayerInstantiated = false;
    int frontIdleCounter = 0;

public:
    virtual void PlayerAnimation(S *surface, T *texture);
    virtual void StateSetter(int state);
};
