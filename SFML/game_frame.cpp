#pragma once
#include "game_frame.h"
#include "model.h"

using namespace sf;

GameFrame::GameFrame() {
	paddle = new Paddle();
	ball = new Ball();
	for (int y = 0; y < 6; ++y) {
		for (int x = 0; x < 10; ++x) {
			RectangleShape brick;
			brick.setSize(Vector2f((Model::gui->getWidth() / 10), (Model::gui->getHeight() / 20)));
			brick.setPosition(brick.getSize().x*x, brick.getSize().y*(y+3));
			brick.setFillColor(Color::Magenta);
			brick.setOutlineThickness(5);
			brick.setOutlineColor(Color::Blue);
			bricks.push_front(brick);
		}
	}
}

GameFrame::~GameFrame() {
	delete(paddle);
}

const void GameFrame::draw(RenderWindow &window) const{
	paddle->draw(window);
	for (auto brick : bricks) {
		window.draw(brick);
	}
	ball->draw(window);
}

void GameFrame::update() {
	paddle->update();
	ball->update(*paddle, bricks);
}

const void GameFrame::keyPressed(Event::KeyEvent e) {
	switch (e.code) {
	case Keyboard::Key::Left:
		paddle->setDirection(Direction::Left);
		break;
	case Keyboard::Key::Right:
		paddle->setDirection(Direction::Right);
		break;
	default:
		break;
	}
}

const void GameFrame::keyReleased(Event::KeyEvent e) {
	switch (e.code) {
	case Keyboard::Key::Left:
		if (paddle->getDirection() == Direction::Left) paddle->setDirection(Direction::None);
		break;
	case Keyboard::Key::Right:
		if (paddle->getDirection() == Direction::Right) paddle->setDirection(Direction::None);
		break;
	default:
		break;
	}
}
