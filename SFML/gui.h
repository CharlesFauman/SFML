#pragma once
#ifndef GUI_H
#define GUI_H
#include <SFML/Graphics.hpp>
#include <string>

#include "model.h"
#include "frame.h"
#include "game_frame.h"

class GUI {
private:
	sf::RenderWindow * window;
	sf::Clock* clock;
	int fps;
	float width, height;
	std::string window_name;

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

	// Non Modifying Methods
	float getWidth() const;
	float getHeight() const;

	// Modifiers
	void run();

};

#endif