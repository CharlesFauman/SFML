#pragma once
#include <SFML/Graphics.hpp>

#include "model.h"
#include "frame.h"
#include "game_frame.h"

class GUI {
private:
	sf::RenderWindow * window;
	sf::Clock* clock;
	int fps;
	int width, height;

	// Non Modifying Methods
	const void draw() const;

	void handleEvents();

	// Modifiers
	void update();

public:
	// Constructors
	GUI();

	// Destructors
	~GUI();

	// Modifiers
	void run();

};