#include "you_win_frame.h"
#include "model.h"

using namespace sf;


// Constructors
YouWinFrame::YouWinFrame() {
	font.loadFromFile("sewer.ttf");
	you_win_text.setFont(font);
	you_win_text.setString("You Win!");
	you_win_text.setCharacterSize(130);
	sf::FloatRect textRect = you_win_text.getLocalBounds();
	you_win_text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	you_win_text.setPosition(Vector2f(Model::gui->getWidth() / 2, Model::gui->getHeight() / 2));
	you_win_text.setFillColor(Color::Cyan);
	you_win_text.setOutlineColor(Color::Yellow);
	you_win_text.setOutlineThickness(3);
}

// Destructors
YouWinFrame::~YouWinFrame() {

}

// Functions
const void YouWinFrame::draw(sf::RenderWindow &window) const {
	window.draw(you_win_text);
}

// Modifiers
void YouWinFrame::update() {

}