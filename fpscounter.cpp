#include "FpsCounter.hpp"

#include <sstream> //stringstream
#include <iomanip> //std::fixed and std::setprecision

FPSCounter::FPSCounter()
{
    font.loadFromFile("Plans.ttf");

    text.setFont(font);
    text.setString("FPS: ");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Green);
    text.setPosition(sf::Vector2f(10, 0));
}  

FPSCounter::~FPSCounter()
{
    //no dynamic memory
}

// Calculates the FPS using the elapsed time between frames (1 / frame time)
void FPSCounter::update(sf::Time elapsed) 
{
	// JAN: elapsed.asMilliseconds returns an int ... use asSeconds() instead
    //float milliseconds = elapsed.asMilliseconds();
	float seconds = elapsed.asSeconds();

	// JAN: Modified the below

	std::stringstream fpsStream;
	if (seconds != 0.0f) {
		fpsStream << std::fixed << std::setprecision(2) << 1.0f / seconds; //fps to 2 decimal places
	} else {
		fpsStream << "Infinity";
	}

	text.setString("FPS: " + fpsStream.str());

	/*
    float fps;
    if (milliseconds != 0) 
    {
        fps = 1.0f / milliseconds;
    }
    else 
    {
        fps = 60.0f;  //60 FPS if milliseconds is zero
    }
    
    std::stringstream fpsStream;
    fpsStream << std::fixed << std::setprecision(2) << fps; //fps to 2 decimal places
    text.setString("FPS: " + fpsStream.str());
	*/
}

void FPSCounter::render(sf::RenderWindow& window) 
{
    window.draw(text);
}
