#include "paddle.h"
#include "model.h"

using namespace sf;

Paddle::Paddle() {
	x = Model::gui->getWidth() / 2;
	y = 7 * Model::gui->getHeight() / 8;
	width = Model::gui->getWidth()/8;
	height = Model::gui->getHeight() / 32;
	speed = 10;
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

	if (x < 0) {
		x = 0;
	}
	else if (x + width > Model::gui->getWidth()) {
		x = Model::gui->getWidth() - width;
	}
}

void Paddle::setDirection(Direction d) {
	direction = d;
}

Direction Paddle::getDirection() const {
	return direction;
}