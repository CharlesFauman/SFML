#include "paddle.h"
#include "model.h"

using namespace sf;

Paddle::Paddle() {
	body.setSize(Vector2f((Model::gui->getWidth() / 8), (Model::gui->getHeight() / 32)));
	body.setOrigin(Vector2f(body.getSize().x/2, body.getSize().y/2));
	body.setFillColor(Color::Cyan);
	speed = 10;
	reset();
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

	if (body.getPosition().x - body.getSize().x / 2 < 0) {
		body.setPosition(Vector2f(body.getSize().x / 2, body.getPosition().y));
	}
	else if (body.getPosition().x + body.getSize().x/2 > Model::gui->getWidth()) {
		body.setPosition(Vector2f(Model::gui->getWidth() - body.getSize().x/2, body.getPosition().y));
	}
}

void Paddle::setDirection(Direction d) {
	direction = d;
}

Direction Paddle::getDirection() const {
	return direction;
}

void Paddle::reset() {
	body.setPosition(Model::gui->getWidth() / 2, 7 * Model::gui->getHeight() / 8);
	direction = Direction::None;
}