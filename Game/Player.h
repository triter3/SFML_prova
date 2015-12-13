#ifndef PLAYER_H
#define PLAYER_H

#include "SFML\Graphics.hpp"

class Player{
public:
	Player(sf::RenderWindow &win);
	void update(float time);
	void render();
private:
	void inputs();
	void resetVelocity();

	sf::CircleShape shape;
	sf::Vector2f pos;
	sf::Vector2f velocity;
	sf::RenderWindow &window;

	float radius;
};

#endif