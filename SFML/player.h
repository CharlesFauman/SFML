#pragma once
#include <utility>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "direction.h"

using namespace std;
using namespace sf;

class Player {
private:
	float x, y;
	float width, height;
	float speed;
	Direction direction;

public:
	// Constructors
	Player() {
		x = 50;
		y = 50;
		width = 50; 
		height = 50;
		speed = 3;
		direction = Direction::None;
	}

	// Destructors

	// Functions
	const pair<float, float> getPos() {
		return make_pair(x, y);
	}

	const void draw(RenderWindow &window) {
		RectangleShape rect;
		rect.setSize(Vector2f(width, height));
		rect.setPosition(x, y);
		rect.setFillColor(Color::Cyan);
		window.draw(rect);
	}

	// Modifiers
	void update() {
		switch (direction) {
		case Direction::Up:
			y -= speed;
			break;
		case Direction::Down:
			y += speed;
			break;
		case Direction::Left:
			x -= speed;
			break;
		case Direction::Right:
			x += speed;
			break;
		default:
			break;
		}
	}

	void setDirection(Direction d) {
		direction = d;
	}

};