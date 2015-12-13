#include "Player.h"

Player::Player(sf::RenderWindow &win) : window(win), radius(20.f){
	pos.x = 0; pos.y = 0;
	velocity.x = 0; velocity.y = 0;
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(0,0);
	shape.setRadius(radius);
}

void Player::update(float time){
	inputs();
	pos.x = velocity.x * time * 100.f;
	pos.y = velocity.y * time * 100.f;
	shape.move(pos);
}

void Player::render(){
	window.draw(shape);
}

void Player::inputs(){
	resetVelocity();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){ velocity.x -= 1; };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){ velocity.x += 1; };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){ velocity.y -= 1; };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){ velocity.y += 1; };
}

void Player::resetVelocity(){
	velocity.x = 0;
	velocity.y = 0;
}