#pragma once

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

public:
    virtual void PlayerAnimation();
    virtual void StateSetter(int state);

};
