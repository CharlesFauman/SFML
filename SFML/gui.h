#pragma once
#include <SFML/Graphics.hpp>

#include "frame.h"
#include "game_frame.h"

using namespace std;
using namespace sf;

class GUI {
private:
	RenderWindow * window;
	Clock* clock;
	int fps;
	Frame* current_frame;

	// Non Modifying Methods
	const void draw() const {
		window->clear();
		current_frame->draw(*window);
		window->display();
	}

	void handleEvents() {
		Event event;
		//cout << "handing_events!" << endl;
		while (window->pollEvent(event)) {
			switch (event.type){
			case sf::Event::Closed: // window closed
				window->close();
				break;
			case sf::Event::MouseButtonPressed: // key pressed
				current_frame->mousePressed(event.mouseButton);
				break;
			case sf::Event::MouseButtonReleased: // key pressed
				current_frame->mouseReleased(event.mouseButton);
				break;
			case sf::Event::KeyPressed: // key pressed
				current_frame->keyPressed(event.key);
				break;
			case sf::Event::KeyReleased: // key pressed
				current_frame->keyReleased(event.key);
				break;
			default:
				break;
			}
		}
	}

	// Modifiers
	void update() {
		current_frame->update();
	}

public:
	// Constructors
	GUI() {
		window = new RenderWindow(VideoMode(400, 200), "SFML Works!");
		clock = new Clock();
		fps = 60;
		current_frame = new GameFrame();
	}

	// Destructors
	~GUI() {
		delete(window);
		delete(clock);
	}

	// Non Modifying Methods

	// Modifiers
	void run() {
		while (window->isOpen()) {
			clock -> restart();
			Event event;

			handleEvents();
			update();
			draw();


			int elapsed_time = clock -> getElapsedTime().asMilliseconds();
			while (elapsed_time <= 1000 / fps) {
				elapsed_time = clock -> getElapsedTime().asMilliseconds();
			}
		}
	}

};