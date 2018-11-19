#ifndef BLOCKS_H
#define BLOCKS_H

#include <SFML/Graphics.hpp>

class Block : public sf::Sprite
{
private:
	sf::Vector2f speed;
public:
	Block(){}

	void setSpeed(sf::Vector2f sp);

	sf::Vector2f getSpeed();

	void defMove();

};

#endif