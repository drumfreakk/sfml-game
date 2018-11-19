#include "blocks.h"

#include <iostream>

#include <SFML/Graphics.hpp>

void Block::setSpeed(sf::Vector2f sp){
	Block::speed = sp;
}

sf::Vector2f Block::getSpeed(){
	return Block::speed;
}

void Block::defMove(){
	sf::Sprite::move(Block::speed);
}