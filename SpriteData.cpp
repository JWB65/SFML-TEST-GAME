#include "spriteData.hpp"

#include <SFML/Graphics/Texture.hpp>

SpriteData::SpriteData()
{
    m_spriteFile = nullptr;
}

// JAN: changed the argument to pointer to the file name
SpriteData::SpriteData(std::string* spriteFile) : m_spriteFile(spriteFile)
{
	printf("SpriteData constructed\n"); // JAN: addded

    //printf("Memory address of spriteFile: %p \n", this->m_spriteFile);
	printf("Memory address of spriteFile: %p \n", m_spriteFile); // JAN: "this->" is not needed

    if (m_texture.loadFromFile(*m_spriteFile)) // JAN: "this->" is not needed
    {
        printf("File loaded \n");
    }
    else 
    {
        if (!m_texture.loadFromFile("textureFailed.png"))
        {
            printf("Backup could not be loaded. Should not happen! \n"); // JAN: changed text a little
        }

        else 
        {
            printf("Backup image loaded \n");
        }
    }
}

SpriteData::~SpriteData()
{
    printf("SpriteData destructed\n");
    delete m_spriteFile;
}

const sf::Texture* SpriteData::getTexture() const
{
    return &m_texture;
}

std::string* SpriteData::getSpriteFile() const
{
    return m_spriteFile;
}