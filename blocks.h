#ifndef BLOCKS_H
#define BLOCKS_H

#include <SFML/Graphics.hpp>

class Block : public sf::Sprite
{
private:
	sf::Vector2f speed;
	sf::Vector2f size;
public:
	Block(){}

	void setSpeed(sf::Vector2f sp);

	sf::Vector2f getSpeed();

	void defMove();

	void setSize(int x, int y, int orX, int orY);

	void storeSize(int x, int y);


	sf::Vector2f getSize();

};

#endif