#pragma once
#ifndef GAME_OVER_FRAME_H
#define GAME_OVER_FRAME_H
#include <SFML/Graphics.hpp>
#include <list>

#include "frame.h"

class GameOverFrame : public Frame {
private:
	sf::Text game_over_text;
	sf::Font font;
public:

	// Constructors
	GameOverFrame();

	// Destructors
	~GameOverFrame();

	// Functions
	const void draw(sf::RenderWindow &window) const override;

	// Modifiers
	void update() override;
};

#endif