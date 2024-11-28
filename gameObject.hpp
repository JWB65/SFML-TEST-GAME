#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class GameObject {
    protected:
        std::string identifier;
    public:
        GameObject();
        GameObject(std::string identifier);
        GameObject(const GameObject& other);
        virtual ~GameObject(); //children of this class will use this deconstrcutor as well
        virtual void update() = 0;
        virtual void render(sf::RenderWindow& window) = 0;
        std::string getIdentifier() const;
    
};