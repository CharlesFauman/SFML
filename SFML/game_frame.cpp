#include "game_frame.h"

using namespace sf;

GameFrame::GameFrame() {
	player = new Player();
}

GameFrame::~GameFrame() {
	delete(player);
}

const void GameFrame::draw(RenderWindow &window) const{
	player->draw(window);
}

void GameFrame::update() {
	player->update();
}

const void GameFrame::keyPressed(Event::KeyEvent e) {
	switch (e.code) {
	case Keyboard::Key::Up:
		player->setDirection(Direction::Up);
		break;
	case Keyboard::Key::Down:
		player->setDirection(Direction::Down);
		break;
	case Keyboard::Key::Left:
		player->setDirection(Direction::Left);
		break;
	case Keyboard::Key::Right:
		player->setDirection(Direction::Right);
		break;
	case Keyboard::Key::Space:
		player->setDirection(Direction::None);
		break;
	default:
		break;
	}
}