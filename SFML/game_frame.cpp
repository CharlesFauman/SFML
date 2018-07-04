#pragma once
#include "game_frame.h"
#include "model.h"

using namespace sf;

GameFrame::GameFrame() {
	paddle = new Paddle();
	ball = new Ball(this);
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
	score = 0;
	lives = 3;
	font.loadFromFile("sewer.ttf");
	score_text.setFont(font);
	score_text.setCharacterSize(40);
	score_text.setPosition(Vector2f(Model::gui->getWidth() / 8, 9*Model::gui->getHeight() / 10));
	score_text.setFillColor(Color::Cyan);
	score_text.setOutlineColor(Color::Yellow);
	score_text.setOutlineThickness(3);

	lives_text.setFont(font);
	lives_text.setCharacterSize(40);
	lives_text.setPosition(Vector2f(5*Model::gui->getWidth() / 8, 9 * Model::gui->getHeight() / 10));
	lives_text.setFillColor(Color::Red);
	lives_text.setOutlineColor(Color::Yellow);
	lives_text.setOutlineThickness(3);
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
	window.draw(score_text);
	window.draw(lives_text);
}

void GameFrame::update() {
	paddle->update();
	ball->update();
	score_text.setString("score: " + std::to_string(score) );
	lives_text.setString("lives: " + std::to_string(lives));

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
