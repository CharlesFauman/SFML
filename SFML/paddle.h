#pragma once
#include <SFML/Graphics.hpp>

#include "direction.h"

class Paddle {
private:
	sf::RectangleShape body;
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