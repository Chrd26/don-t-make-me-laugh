#pragma once

template<typename S,typename T, typename  R, typename Rect>
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
    std::array<T*, 11> frontAnimIdleFrameTexture = nullptr;
    std::array<T*, 17> frontAnimWalkFrameTexture = nullptr;
    T* backAnimIdleFrameTexture = nullptr;
    std::array <T*, 4> backAnimWalkFrameTexture = nullptr;
    std::array <T*, 9> sideAnimIdleFrameTexture = nullptr;
    std::array <T*, 18> sideAnimWalkFrameTexture = nullptr;
    T *frameTexture;
    bool isPlayerInstantiated = false;
    int frontIdleCounter = 0;

public:
    virtual void PlayerAnimation(S *surface, T *texture);
    virtual void StateSetter(int state);
    virtual void LoadPlayerFrames(R *renderer);
};
