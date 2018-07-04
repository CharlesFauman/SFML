#pragma once
#ifndef GAMEFRAME_H
#define GAMEFRAME_H
#include <SFML/Graphics.hpp>
#include <list>

#include "frame.h"
#include "paddle.h"
#include "ball.h"
#include "direction.h"

class GameFrame : public Frame{
private:
	sf::Text score_text;
	sf::Text lives_text;
	sf::Font font;
public:
	Paddle * paddle;
	Ball* ball;
	int score;
	int lives;
	std::list<sf::RectangleShape> bricks;

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

#endif