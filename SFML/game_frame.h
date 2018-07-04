#pragma once
#include <SFML/Graphics.hpp>
#include <list>

#include "frame.h"
#include "paddle.h"
#include "ball.h"
#include "direction.h"

class GameFrame : public Frame{
private:
	Paddle* paddle;
	Ball* ball;
	std::list<sf::RectangleShape> bricks;

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