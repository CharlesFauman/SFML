#pragma once
#include <SFML/Graphics.hpp>
#include "frame.h"
#include "paddle.h"
#include "direction.h"

class Paddle;
class GameFrame : public Frame{
private:
	Paddle * paddle;

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
	const void keyReleased(sf::Event::KeyEvent e) override;
};