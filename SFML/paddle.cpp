#include "paddle.h"
#include "model.h"

using namespace sf;

Paddle::Paddle() {
	x = 50;
	y = 50;
	width = Model::gui->getWidth()/2;
	height = 7 * Model::gui->getWidth() / 8;
	speed = 3;
	direction = Direction::None;
}

const void Paddle::draw(RenderWindow &window) {
	RectangleShape rect;
	rect.setSize(Vector2f(width, height));
	rect.setPosition(x, y);
	rect.setFillColor(Color::Cyan);
	window.draw(rect);
}

void Paddle::update() {
	switch (direction) {
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

void Paddle::setDirection(Direction d) {
	direction = d;
}

Direction Paddle::getDirection() const {
	return direction;
}