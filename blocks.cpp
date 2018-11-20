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

void Block::setSize(int x, int y, int orX, int orY){
	Block::size = sf::Vector2f(x, y);
	sf::Sprite::scale((x / orX), (y / orY));
}

void Block::storeSize(int x, int y){
	Block::size = sf::Vector2f(x, y);
}

sf::Vector2f Block::getSize(){
	return Block::size;
}

