#include "ball.h"
#include "model.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>


using namespace sf;

void Ball::update(){
	body.move(normalized_velocity.x*speed/3, normalized_velocity.y*speed/3);

	if (body.getGlobalBounds().intersects(game->paddle->body.getGlobalBounds())) {
		float normalized_distance = (game->paddle->body.getPosition().x - body.getPosition().x) / (body.getRadius() + game->paddle->body.getSize().x / 2);
		float bounce_angle = normalized_distance*5 * M_PI / 12;
		normalized_velocity.x = -sin(bounce_angle);
		normalized_velocity.y = cos(bounce_angle)*((normalized_velocity.y > 0) ? -1 : 1);
	}
	else if (body.getPosition().y - body.getRadius()*2 < 0) {
		normalized_velocity.y *= -1;
	}
	else if (body.getPosition().x - body.getRadius() < 0 || body.getPosition().x + body.getRadius() > Model::gui->getWidth()) {
		normalized_velocity.x *= -1;
	}
	else if (body.getPosition().y + body.getRadius() * 2 > Model::gui->getHeight()) {
		game->lives -= 1;
		reset();
	}

	auto brick_itr = game->bricks.begin();
	bool hit_y = false;
	bool hit_x = false;
	while (brick_itr != game->bricks.end()) {
		if (body.getGlobalBounds().intersects(brick_itr->getGlobalBounds())) {
			Vector2f dists = (body.getPosition() - brick_itr->getPosition());
			if (!hit_y && abs(dists.x / brick_itr->getPosition().x) > abs(dists.y / brick_itr->getPosition().y)) {
				normalized_velocity.x *= -1;
				hit_y = true;
			}else if(!hit_x){
				normalized_velocity.y *= -1;
				hit_x = true;
			}
			brick_itr = game->bricks.erase(brick_itr);
			game->score += 1;
		}
		else {
			++brick_itr;
		}
	}
	body.move(2*normalized_velocity.x*speed / 3, 2*normalized_velocity.y*speed / 3);
}

const void Ball::draw(sf::RenderWindow &window) {
	window.draw(body);
}

Ball::Ball(GameFrame* g) {
	game = g;
	body.setRadius(Model::gui->getWidth() / 60);
	body.setOrigin(Vector2f(body.getRadius(), body.getRadius()));
	body.setFillColor(Color::Green);
	reset();
}

void Ball::reset() {
	speed = 6;
	body.setPosition(Model::gui->getWidth() / 2, Model::gui->getHeight() / 2);
	normalized_velocity = Vector2f(0, 1);
}


Ball::~Ball() {
}
