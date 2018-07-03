#pragma once
#include <SFML/Graphics.hpp>
#include "frame.h"
#include "player.h"
#include "direction.h"

class GameFrame : public Frame{
private:
	Player * player;

public:
	// Constructors
	GameFrame();

	// Destructors
	~GameFrame();

	// Functions
	const void draw(sf::RenderWindow &window) const override;

	// Modifiers
	void update() override;

	const void keyPressed(sf::Event::KeyEvent e) override;
};