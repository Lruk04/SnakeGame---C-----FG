#include "GameObject.h"


void GameObject::Render(SnakeGraphics* graphics) 
{
    
}

void GameObject::Update()
{
    
}

void GameObject::Destroy()
{
    GameObject* obj = new GameObject();
    delete obj;
}

