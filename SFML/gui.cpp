#include "gui.h"

using namespace sf;

const void GUI::draw() const {
	window->clear();
	Model::active_frame->draw(*window);
	window->display();
}

void GUI::handleEvents() {
	Event event;
	while (window->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed: // window closed
			window->close();
			break;
		case sf::Event::MouseButtonPressed: // key pressed
			Model::active_frame->mousePressed(event.mouseButton);
			break;
		case sf::Event::MouseButtonReleased: // key pressed
			Model::active_frame->mouseReleased(event.mouseButton);
			break;
		case sf::Event::KeyPressed: // key pressed
			Model::active_frame->keyPressed(event.key);
			break;
		case sf::Event::KeyReleased: // key pressed
			Model::active_frame->keyReleased(event.key);
			break;
		default:
			break;
		}
	}
}

void GUI::update() {
	Model::active_frame->update();
}

GUI::GUI() {
	fps = 60;
	width = 1000;
	height = 600;
	window = new RenderWindow(VideoMode(width, height), window_name.c_str());
	clock = new Clock();
}

GUI::~GUI(){
	delete(window);
	delete(clock);
}

float GUI::getWidth() const{
	return width;
}
float GUI::getHeight() const {
	return height;
}

void GUI::run() {
	while (window->isOpen()) {
		clock->restart();

		handleEvents();
		update();
		draw();


		int elapsed_time = clock->getElapsedTime().asMilliseconds();
		while (elapsed_time <= 1000 / fps) {
			elapsed_time = clock->getElapsedTime().asMilliseconds();
		}
	}
}