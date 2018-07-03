#pragma once
#include <utility>
#include <SFML/Graphics.hpp>

#include "direction.h"

class Paddle {
private:
	float x, y;
	float width, height;
	float speed;
	Direction direction;

public:
	// Constructors
	Paddle();

	// Destructors
	~Paddle() {}

	const void draw(sf::RenderWindow &window);

	// Modifiers
	void update();

	void setDirection(Direction d);
	Direction getDirection() const;

};