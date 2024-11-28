#include "Character.hpp"
#include "Fpscounter.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <crtdbg.h>

// JAN: Some general changes: Capitalization of file names
// JAN: Moved the globals variable to variable within the main function
// JAN: Can not debug because we need to debug lib files for SFML

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //for detecting memory leak

	// We can define the texture here and give a pointer to it to other objects - no memory leaks
	sf::Texture texture;

	//if (!texture.loadFromFile("dogg.jpg"))
	//	return EXIT_FAILURE;

	if (!texture.loadFromFile("head.png"))
		return EXIT_FAILURE;

	sf::Sprite sprite(texture);

	sf::Font font;
	if (!font.loadFromFile("Plans.ttf"))
		return EXIT_FAILURE;

	Character<float> theplayer = Character<float>(100, 10, 10, 10, 5, "The player");

	unsigned int lives;

	sf::Music music;
	if (!music.openFromFile("guitarr.wav"))
		return EXIT_FAILURE;
	music.play();

	sf::RenderWindow window(sf::VideoMode(1280, 720), "The game");
	window.create(sf::VideoMode(640, 480), "My SFML Game" /* ... */);

	sf::Clock clock; // sf::Clock class to get keep timee

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
		window.draw(sf::Text("Hello SFML!", font, 30));

		// Simulate 15 ms pause
		sf::sleep(sf::milliseconds(15)); 

		sf::Time elapsed = clock.restart(); // Elapsed time since the last frame. Time counter back to 0

		FPSCounter fpsCounter; // JAN: can make this local actually!
		fpsCounter.update(elapsed); // Updates counter
		fpsCounter.render(window);

		window.display();
	}

	return EXIT_SUCCESS;
}

//player.info();
//
//int amountofcharacters = 3;
////  Character<float>** thecharacters = new Character<float>*[amountofcharacters]; //an array of pointers to a character
//
//player.info();
//player.addItem("Health Potion");
//player.addItem("Sword");
//player.addItem("Shield");
//
//player.printItems();
//
//player.removeItem(1);
//player.printItems();
//player.addItem("Bow");
//player.addItem("Arrow");
//player.addItem("Helmet");
//player.printItems();
//
//
//printf("Hello world");


