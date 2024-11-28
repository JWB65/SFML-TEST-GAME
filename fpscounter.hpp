#pragma once

#include <SFML/Graphics.hpp>

class FPSCounter {
    private:
        sf::Text text;
        sf::Font font;

    public:
        FPSCounter();
        ~FPSCounter();

        void render(sf::RenderWindow& window);
        void update(sf::Time elapsed);
};