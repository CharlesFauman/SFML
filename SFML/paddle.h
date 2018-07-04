#pragma once
#include <SFML/Graphics.hpp>

#include "direction.h"

class GameFrame;
class Paddle {
private:
	float speed;
	Direction direction;

public:
	sf::RectangleShape body;

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