#include "Game.h"

Game::Game() : window(sf::VideoMode(500, 500), "Game"), player(window), window_state(NORMALSCREEN) {

}

void Game::start(){
	sf::Clock clock;
	sf::Time deltaTime = clock.getElapsedTime();
	float delta = 0;

	while (window.isOpen()){
		sf::Event event;

		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window.close();
			}
			if (event.type == sf::Event::KeyPressed){
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
					window.close();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)){
					if (window_state == NORMALSCREEN){
						window.create(sf::VideoMode(500, 500), "Game", sf::Style::Fullscreen);
						window_state = FULLSCREEN;
					}
					if (window_state == FULLSCREEN){
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

void Game::update(float time){
	player.update(time);
}

void Game::render(){
	player.render();
}