#ifndef BLOCKS_H
#define BLOCKS_H

#include <SFML/Graphics.hpp>

#include <iostream>

class Block : public sf::Sprite
{
private:
	sf::Vector2f size;

public:
	Block(){}

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

class MovingBlock : public Block
{
private:
	sf::Vector2f speed;
	float mvSpeed;

public:
	MovingBlock(){}

	/// set a speed for a constant moving block
	void setSpeed(sf::Vector2f sp);

	/// get the constant moving speed
	sf::Vector2f getSpeed();

	/// move the block the constant moving speed
	void defMove();

	/// set the speed for a non constant moving block
	void setSpeed(float sp);


	/// get the non constant moving block speed
	float getMvSpeed();

};

class TpBaseBlock : public Block
{
public:
	TpBaseBlock(){};
};

class TpSendBlock : public TpBaseBlock
{
private:
	TpBaseBlock linkedBlock;
	bool linked = false;
public:
	TpSendBlock(){};

	void linkBlocks(TpBaseBlock &toLink);

	void unlinkBlocks();

	void teleport(Block &toTeleport);
};

#endif