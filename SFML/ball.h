#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "paddle.h"

class Ball{
private:
	sf::Vector2f normalized_velocity;
	float speed;

public:
	sf::CircleShape body;

	void update(Paddle &p, std::list<sf::RectangleShape> &bricks);

	const void draw(sf::RenderWindow &window);

	Ball();
	~Ball();
};

