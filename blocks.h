#ifndef BLOCKS_H
#define BLOCKS_H

#include <SFML/Graphics.hpp>

class Block : public sf::Sprite
{
private:
	sf::Vector2f pos;
public:
	Block(sf::Vector2f x)
		:pos(x)
	{}

};

#endif