#pragma once
#include <utility>
#include <SFML/Graphics.hpp>

#include "direction.h"

class Player {
private:
	float x, y;
	float width, height;
	float speed;
	Direction direction;

public:
	// Constructors
	Player();

	// Destructors
	~Player() {}

	const void draw(sf::RenderWindow &window);

	// Modifiers
	void update();

	void setDirection(Direction d);

};