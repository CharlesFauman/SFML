#include "ball.h"
#include "model.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>


using namespace sf;

void Ball::update(Paddle &p, std::list<sf::RectangleShape> &bricks){
	body.move(normalized_velocity.x*speed, normalized_velocity.y*speed);

	if (body.getGlobalBounds().intersects(p.body.getGlobalBounds()) || body.getPosition().y - body.getRadius() < 0) {
		normalized_velocity.y *= -1;
	}
	else if (body.getPosition().x - body.getRadius() < 0 || body.getPosition().x + body.getRadius() > Model::gui->getWidth()) {
		normalized_velocity.x *= -1;
	}

	auto brick_itr = bricks.begin();
	while (brick_itr != bricks.end()) {
		if (body.getGlobalBounds().intersects(brick_itr->getGlobalBounds())) {
			brick_itr = bricks.erase(brick_itr);
		}
		else {
			++brick_itr;
		}
	}
}

const void Ball::draw(sf::RenderWindow &window) {
	window.draw(body);
}

Ball::Ball() {
	body.setRadius(Model::gui->getWidth() / 60);
	body.setOrigin(Vector2f(body.getRadius(), body.getRadius()));
	body.setPosition(Model::gui->getWidth() / 2, Model::gui->getHeight() / 2);
	body.setFillColor(Color::Green);
	normalized_velocity = Vector2f(0, 1);
	speed = 6;
}


Ball::~Ball() {
}
