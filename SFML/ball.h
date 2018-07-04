#pragma once
#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>
#include <list>
#include "paddle.h"

class GameFrame;
class Ball{
private:
	sf::Vector2f normalized_velocity;
	float speed;
	GameFrame* game;

public:
	sf::CircleShape body;

	void update();

	void reset();

	const void draw(sf::RenderWindow &window);

	Ball(GameFrame* g);
	~Ball();
};

#endif

