#include "player.h"

using namespace sf;

Player::Player() {
	x = 50;
	y = 50;
	width = 50;
	height = 50;
	speed = 3;
	direction = Direction::None;
}

const void Player::draw(RenderWindow &window) {
	RectangleShape rect;
	rect.setSize(Vector2f(width, height));
	rect.setPosition(x, y);
	rect.setFillColor(Color::Cyan);
	window.draw(rect);
}

void Player::update() {
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

void Player::setDirection(Direction d) {
	direction = d;
}