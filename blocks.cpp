#include "blocks.h"
#include <iostream>
#include <SFML/Graphics.hpp>


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

	return (playerPos.x > (blockPos.x - xdiff)) && (playerPos.x < (blockPos.x + xdiff)) &&
		   (playerPos.y > (blockPos.y - ydiff)) && (playerPos.y < (blockPos.y + ydiff));
}

bool Block::colliding(Block &player, int margin){
	sf::Vector2f blockPos = Block::getPosition();
	sf::Vector2f playerPos = player.getPosition();

	float xdiff = (Block::getSize().x / 2) + (player.getSize().x / 2) + margin;
	float ydiff = (Block::getSize().y / 2) + (player.getSize().y / 2) + margin;

	return (playerPos.x > (blockPos.x - xdiff)) && (playerPos.x < (blockPos.x + xdiff)) &&
		   (playerPos.y > (blockPos.y - ydiff)) && (playerPos.y < (blockPos.y + ydiff));
}


/// moving blocks

sf::Vector2f MovingBlock::getSpeed(){
	return MovingBlock::speed;
}

void MovingBlock::defMove(){
	MovingBlock::move(MovingBlock::speed);
}

void MovingBlock::setSpeed(sf::Vector2f sp){
	MovingBlock::speed = sp;
}

void MovingBlock::setSpeed(float sp){
	MovingBlock::mvSpeed = sp;
}

float MovingBlock::getMvSpeed() {
	return MovingBlock::mvSpeed;
}

/// teleport blocks

void TpSendBlock::linkBlocks(TpBaseBlock &toLink) {
	if(!TpSendBlock::linked) {
		TpSendBlock::linkedBlock = toLink;
		TpSendBlock::linked = true;
	}
}

void TpSendBlock::unlinkBlocks() {
	TpSendBlock::linked = false;
}

void TpSendBlock::teleport(Block &toTeleport) {
	if(TpSendBlock::linked) {
		std::cout << TpSendBlock::linkedBlock.getPosition().x << " " << TpSendBlock::linkedBlock.getPosition().y << std::endl;
		toTeleport.setPosition(TpSendBlock::linkedBlock.getPosition());
	}
}