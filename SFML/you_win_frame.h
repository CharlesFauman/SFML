#pragma once
#ifndef YOU_WIN_FRAME_H
#define YOU_WIN_FRAME_H
#include <SFML/Graphics.hpp>
#include <list>

#include "frame.h"

class YouWinFrame : public Frame {
private:
	sf::Text you_win_text;
	sf::Font font;
public:

	// Constructors
	YouWinFrame();

	// Destructors
	~YouWinFrame();

	// Functions
	const void draw(sf::RenderWindow &window) const override;

	// Modifiers
	void update() override;
};

#endif