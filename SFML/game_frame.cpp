#pragma once
#include "game_frame.h"

using namespace sf;

GameFrame::GameFrame() {
	paddle = new Paddle();
}

GameFrame::~GameFrame() {
	delete(paddle);
}

const void GameFrame::draw(RenderWindow &window) const{
	paddle->draw(window);
}

void GameFrame::update() {
	paddle->update();
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
