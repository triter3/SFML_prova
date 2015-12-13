#include "Game.h"
#include <iostream>

Game::Game() : window(sf::VideoMode(500, 500), "Game"), player(window), window_state(NORMALSCREEN), FPS(60) {

}

void Game::start(){
	sf::Clock clock;
	sf::Time deltaTime = clock.getElapsedTime();
	sf::Time time = clock.getElapsedTime();
	float delta = 0;
	while (window.isOpen()){
		sf::Event event;
		time = clock.getElapsedTime();
		delta = time.asSeconds() / (1 / FPS);
		while (delta >= 1){
			while (window.pollEvent(event)){
				if (event.type == sf::Event::Closed){
					window.close();
					std::exit(0);
				}
				if (event.type == sf::Event::KeyPressed){
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
						window.close();
						std::exit(0);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)){
						if (window_state == NORMALSCREEN){
							window.create(sf::VideoMode(500, 500), "Game", sf::Style::Fullscreen);
							window_state = FULLSCREEN;
						}
						else if (window_state == FULLSCREEN){
							window.create(sf::VideoMode(500, 500), "Game", sf::Style::Resize);
							window_state = NORMALSCREEN;
						}
					}
				}
			}

			update(deltaTime.asSeconds());

			window.clear();
			render();
			window.display();

			deltaTime = clock.restart();
		}

	}
		
}

void Game::update(float time){
	player.update(time);
}

void Game::render(){
	player.render();
}