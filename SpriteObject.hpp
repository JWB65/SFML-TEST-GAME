#pragma once

#pragma once

#include "gameObject.hpp"
#include "memory"
#include "spriteData.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class SpriteObject : public GameObject {
private:
	sf::Sprite sprite; //must be unique
	SpriteData* theSpriteData;
public:
	SpriteObject(std::string identifier, SpriteData** theSpriteData);
	SpriteObject(const SpriteObject& other);
	~SpriteObject();
	void update() override;
	void render(sf::RenderWindow& window) override;
	void setPosition(sf::Vector2f position);
	void setScale(sf::Vector2f scale);
	SpriteData* getSpriteData() const;
};
