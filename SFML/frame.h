#pragma once
#ifndef Frame_H
#define Frame_H
#include <SFML/Graphics.hpp>

class Frame {
private:
	

public:
	// Constructors
	Frame() {}

	// Destructors
	~Frame() {}

	// Functions
	virtual const void draw(sf::RenderWindow &window) const = 0;

	virtual const void mousePressed(sf::Event::MouseButtonEvent e){}
	virtual const void mouseReleased(sf::Event::MouseButtonEvent e) {}
	virtual const void keyPressed(sf::Event::KeyEvent e) {}
	virtual const void keyReleased(sf::Event::KeyEvent e) {}

	// Modifiers
	virtual void update() = 0;
};

#endif