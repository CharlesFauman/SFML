#include "game_over_frame.h"
#include "model.h"

using namespace sf;

// Constructors
GameOverFrame::GameOverFrame() {
	font.loadFromFile("sewer.ttf");
	game_over_text.setFont(font);
	game_over_text.setString("Game Over!");
	game_over_text.setCharacterSize(130);
	sf::FloatRect textRect = game_over_text.getLocalBounds();
	game_over_text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	game_over_text.setPosition(Vector2f(Model::gui->getWidth() / 2, Model::gui->getHeight() / 2));
	game_over_text.setFillColor(Color::Red);
	game_over_text.setOutlineColor(Color::Yellow);
	game_over_text.setOutlineThickness(3);
}

// Destructors
GameOverFrame::~GameOverFrame() {

}

// Functions
const void GameOverFrame::draw(sf::RenderWindow &window) const {
	window.draw(game_over_text);
}

// Modifiers
void GameOverFrame::update() {

}