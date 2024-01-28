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
    std::array <T*, 4> backAnimWalkFrameTexture;
    std::array <T*, 9> sideAnimIdleFrameTexture;
    std::array <T*, 18> sideAnimWalkFrameTexture;
    T *frameTexture;
    int frontIdleCounter = 0;
    bool areTexturesLoaded = false;

public:
    virtual void PlayerAnimation(S *surface, T *texture);
    virtual void StateSetter(int state);
    virtual void LoadPlayerFrames(R *renderer);
    
    bool hasLoadedTextures()
    {
        return hasLoadedTextures;
    }
};
