#pragma once
#include <SFML/Graphics.hpp>

class Ball{
private:
	sf::CircleShape body;
public:

	void update();

	const void draw(sf::RenderWindow &window);

	Ball();
	~Ball();
};

