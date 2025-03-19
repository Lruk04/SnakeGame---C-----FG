#include "GameObject.h"


GameObject::GameObject(PlayState* game) : m_game(game)
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

