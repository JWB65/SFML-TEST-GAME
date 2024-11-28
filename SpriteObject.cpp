#include "spriteObject.hpp"

SpriteObject::SpriteObject(std::string identifier, SpriteData** theSpriteData) : GameObject(identifier), 
theSpriteData(*theSpriteData)
{
	printf("SpriteObject constructed 1");

    printf("Memory address of this: %p \n", this->theSpriteData);
    sprite.setTexture(*this->theSpriteData->getTexture());
}

SpriteObject::~SpriteObject() 
{
    printf("SpriteObject destructed");
    delete theSpriteData;
}

SpriteObject::SpriteObject(const SpriteObject& other) : 
    GameObject(other.getIdentifier()), theSpriteData(other.getSpriteData())
{
	printf("SpriteObject constructed 2");
}

void SpriteObject::update() 
{

}

void SpriteObject::render(sf::RenderWindow& window) 
{
    window.draw(sprite);
}

void SpriteObject::setPosition(sf::Vector2f position) 
{
    sprite.setPosition(position);
}

void SpriteObject::setScale(sf::Vector2f scale) 
{
    sprite.setScale(scale);
}

SpriteData* SpriteObject::getSpriteData() const
{
    return theSpriteData;
}