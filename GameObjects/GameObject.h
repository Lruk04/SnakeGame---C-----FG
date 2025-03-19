// #pragma once
// #include "../Tools/SnakeGraphics.h"
// #include "../Game.h"
//
// class PlayState;
//
// class GameObject
// {
// private:
//     bool m_bDestroyed = false;
//
// protected:
//     PlayState* m_game;
//
//     virtual void DestroyDerived() = 0;
//
// public:
//     GameObject(PlayState* game);
//
//     virtual void Init() = 0;
//     virtual void Render(SnakeGraphics* graphics) = 0;
//     virtual void Update() = 0;
//
//     void Destroy();
//
//     bool IsDestroyed() const;
// };

#pragma once
#include "../Tools/SnakeGraphics.h"
#include "../GameStates/PlayState.h"

class PlayState;

class GameObject {
private:
    bool m_bDestroyed = false;
    PlayState* m_game;

public:
    GameObject(PlayState* game);
    virtual ~GameObject() = default;

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Render(SnakeGraphics* graphics) = 0;
    virtual void DestroyDerived() = 0;

    void Destroy();
    bool IsDestroyed() const;
};