#include "blocks.h"

#include <iostream>

#include <SFML/Graphics.hpp>

void Block::setSpeed(sf::Vector2f sp){
	Block::speed = sp;
}

void Block::setSpeed(float sp){
	Block::mvSpeed = sp;
}

float Block::getMvSpeed() {
	return Block::mvSpeed;
}

sf::Vector2f Block::getSpeed(){
	return Block::speed;
}

void Block::defMove(){
	Block::move(Block::speed);
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

bool Block::colliding(Block &player){
	sf::Vector2f blockPos = Block::getPosition();
	sf::Vector2f playerPos = player.getPosition();

	float xdiff = (Block::getSize().x / 2) + (player.getSize().x / 2);
	float ydiff = (Block::getSize().y / 2) + (player.getSize().y / 2);

	if ((playerPos.x > (blockPos.x - xdiff)) && (playerPos.x < (blockPos.x + xdiff)) &&
		(playerPos.y > (blockPos.y - ydiff)) && (playerPos.y < (blockPos.y + ydiff))) {
		return true;

	}
	return false;
}