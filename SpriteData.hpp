#pragma once

#include <SFML/Graphics/Texture.hpp>

class SpriteData {
private:

	// Two NON owning pointers to the sprite file name and texture
    std::string* m_spriteFile; 
    sf::Texture m_texture;

public:
    SpriteData();
    SpriteData(std::string* spriteFile); // Changed from double pointer

    ~SpriteData();

    const sf::Texture* getTexture() const; // JAN: need to make return type const
    std::string* getSpriteFile() const;
};
