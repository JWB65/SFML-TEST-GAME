#include "Character.hpp"

#include <SFML/Graphics.hpp>

#include <crtdbg.h>

// JAN: Moved the globals to with the main function
// JAN: Can not debug because we need to debug lib files for SFML

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //for detecting memory leak

	sf::RenderWindow window(sf::VideoMode(1280, 720), "The game");
	sf::Texture texture;
	sf::Sprite sprite;

	Character<float> theplayer = Character<float>(100, 10, 10, 10, 5, "the player");

	unsigned int lives;

	// Prepare everything
	window.create(sf::VideoMode(640, 480), "My SFML Game" /* ... */);

	// This should do some error checking as well and 'return' just in case.
	texture.loadFromFile("head.png");
	sprite.setTexture(texture);

	while (window.isOpen()) {
		sf::Event eventmain;
		while (window.pollEvent(eventmain)) {

			switch (eventmain.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::TextEntered:
					if (eventmain.text.unicode < 128) {
						printf("%c", eventmain.text.unicode);
					}
					break;
			}
		}

		// Update things

		window.clear();

		window.draw(sprite);

		window.display();
	}

	return 0;
}
