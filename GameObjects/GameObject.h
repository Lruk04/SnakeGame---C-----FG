#pragma once
#include "../Tools/SnakeGraphics.h"
#include "../World.h"

class World;

class GameObject {
private:
    bool m_bDestroyed = false;
    World* m_game;

public:
    GameObject(World* game);
    virtual ~GameObject() = default;

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Render(SnakeGraphics* graphics) = 0;
    virtual void DestroyDerived() = 0;

    void Destroy();
    bool IsDestroyed() const;
};