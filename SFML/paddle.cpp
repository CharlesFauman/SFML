#include "paddle.h"
#include "model.h"

using namespace sf;

Paddle::Paddle() {
	body.setSize(Vector2f((Model::gui->getWidth() / 8), (Model::gui->getHeight() / 32)));
	body.setPosition(Model::gui->getWidth() / 2, 7 * Model::gui->getHeight() / 8);
	body.setFillColor(Color::Cyan);
	speed = 10;
	direction = Direction::None;
}

#include <iostream>
const void Paddle::draw(RenderWindow &window) {
	window.draw(body);
}

void Paddle::update() {
	switch (direction) {
	case Direction::Left:
		body.move(Vector2f (-speed, 0));
		break;
	case Direction::Right:
		body.move(Vector2f(speed, 0));
		break;
	default:
		break;
	}

	if (body.getPosition().x < 0) {
		body.setPosition(Vector2f(0, body.getPosition().y));
	}
	else if (body.getPosition().x + body.getSize().x > Model::gui->getWidth()) {
		body.setPosition(Vector2f(Model::gui->getWidth() - body.getSize().x, body.getPosition().y));
	}
}

void Paddle::setDirection(Direction d) {
	direction = d;
}

Direction Paddle::getDirection() const {
	return direction;
}