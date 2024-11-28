#include "GameObject.hpp"

GameObject::GameObject() 
{
}

GameObject::GameObject(std::string identifier) : identifier(identifier) 
{
}
 
GameObject::GameObject(const GameObject& other) : identifier(other.getIdentifier()) 
{
}

GameObject::~GameObject() 
{
}

std::string GameObject::getIdentifier() const 
{
    return identifier;
}