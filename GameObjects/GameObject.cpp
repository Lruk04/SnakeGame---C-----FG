#include "GameObject.h"


class World;

GameObject::GameObject(World* game) : m_game(game)
{
    m_game->AddGameObject(this);
}

bool GameObject::IsDestroyed() const
{
    return m_bDestroyed;
}

void GameObject::Destroy()
{
    DestroyDerived();

    m_bDestroyed = true;
}

