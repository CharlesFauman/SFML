#pragma once
#include <SFML/Graphics.hpp>
#include "frame.h"
#include "player.h"
#include "direction.h"

using namespace std;
using namespace sf;

class GameFrame : public Frame{
private:
	Player * player;

public:
	// Constructors
	GameFrame() {
		player = new Player();
	}

	// Destructors
	~GameFrame() {
		delete(player);
	}

	// Functions
	const void draw(RenderWindow &window) const override {
		player->draw(window);
	}

	// Modifiers
	void update() override {
		player->update();
	}

	const void keyPressed(Event::KeyEvent e) override{
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
};