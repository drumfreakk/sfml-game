#ifndef BLOCKS_H
#define BLOCKS_H

#include <SFML/Graphics.hpp>

class Block : public sf::Sprite
{
private:
	sf::Vector2f speed;
	sf::Vector2f size;
	float mvSpeed;

public:
	Block(){}

	/// set a speed for a constant moving block
	void setSpeed(sf::Vector2f sp);

	/// set the speed for a non constant moving block
	void setSpeed(float sp);

	/// get the constant moving speed
	sf::Vector2f getSpeed();

	/// get the non constant moving block speed
	float getMvSpeed();

	/// move the block the constant moving speed
	void defMove();

	/// set the blocks size
	void setSize(int x, int y, int orX, int orY);

	/// store the blocks size, but dont set it
	void storeSize(int x, int y);

	/// get the stored size
	sf::Vector2f getSize();

	/// is the block colliding with another block
	bool colliding(Block &player);

	bool colliding(Block &player, int margin);

};

#endif