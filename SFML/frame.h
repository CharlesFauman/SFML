#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Frame {
private:
	

public:
	// Constructors
	Frame() {
		
	}

	// Destructors
	~Frame() {
		
	}

	// Functions
	virtual const void draw(RenderWindow &window) const = 0;

	virtual const void mousePressed(Event::MouseButtonEvent e){}
	virtual const void mouseReleased(Event::MouseButtonEvent e) {}
	virtual const void keyPressed(Event::KeyEvent e) {}
	virtual const void keyReleased(Event::KeyEvent e) {}

	// Modifiers
	virtual void update() = 0;
};