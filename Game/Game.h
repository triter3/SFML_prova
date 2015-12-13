#ifndef GAME_H
#define GAME_H

#include "SFML\Graphics.hpp"
#include "Player.h"

enum WindowState { NORMALSCREEN , FULLSCREEN };

class Game{
public:
	Game();
	void start();
	void update(float time);
	void render();
private:
	sf::RenderWindow window;
	Player player;
	WindowState window_state;
	int FPS;
};

#endif
