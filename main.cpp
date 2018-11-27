#include <SFML/Graphics.hpp>
#include "blocks.h"
#include <iostream>


/// variables for the fixed blocks: amount and positions

const int mBlock = 4;
sf::Vector2f blockPs[mBlock] = {sf::Vector2f(100.f, 100.f), sf::Vector2f(120.f, 100.f), sf::Vector2f(140.f, 100.f), sf::Vector2f(160.f, 100.f)};


/// variables for the moving blocks: amount, starting positions, amount of steps and the amount of steps taken at this point

const int mMvBlock = 1;
sf::Vector2f mvBlockPs[mMvBlock] = {sf::Vector2f(100.f, 200.f)};
int mSteps = 1000;
int steps = 0;


/// main loop

int main() {


	/// open the window

	sf::RenderWindow window(sf::VideoMode(600, 600), "Epic Game");
	window.setFramerateLimit(500);


	/// load the textures

	sf::Texture texture;
	texture.loadFromFile("/home/kip/CLionProjects/sfml-game/assets/textures.png");


	/// initialize the player

	Block player;

	player.setTexture(texture);
	player.setTextureRect(sf::IntRect(0, 0, 20, 20));
	player.setOrigin(10.f, 10.f);
	player.storeSize(20, 20);
	player.setSpeed(2.0);


	/// initialize the fixed blocks

	Block fixedBlock[mBlock];

	for(int x = 0; x < mBlock; x++) {
		fixedBlock[x].setTexture(texture);
		fixedBlock[x].setTextureRect(sf::IntRect(20, 0, 20, 20));

		fixedBlock[x].storeSize(20, 20);
		fixedBlock[x].setOrigin((fixedBlock[x].getSize().x / 2), (fixedBlock[x].getSize().y / 2));
		fixedBlock[x].setPosition(blockPs[x]);
	}


	/// initialize the movable blocks

	Block mvBlock[mMvBlock];

	for(int x = 0; x < mMvBlock; x++){
		mvBlock[x].setTexture(texture);
		mvBlock[x].setTextureRect(sf::IntRect(60, 0, 20, 20));

		mvBlock[x].storeSize(20, 20);
		mvBlock[x].setOrigin((mvBlock[x].getSize().x / 2), (mvBlock[x].getSize().y / 2));
		mvBlock[x].setPosition(mvBlockPs[x]);
		mvBlock[x].setSpeed(sf::Vector2f(0.1, 0.f));
	}


	/// initialize some general variables

	float mvspeed = player.getMvSpeed();

	sf::Vector2f mv;

	bool toMv = false;


	/// this is run while the game runs

	while (window.isOpen())
	{

		/// clear the screen and check if the window is closed

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);


		/// detect user input and act so
		/// mv is to store how you moved to move you back if a collision is detected

		mv.x = 0.f;
		mv.y = 0.f;

		/// keyboard input
		if (event.type == sf::Event::TextEntered){
			if (event.text.unicode < 128){
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
					player.move(sf::Vector2f(0.f, -mvspeed));
					mv.y = -mvspeed;
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
					player.move(sf::Vector2f(-mvspeed, 0.f));
					mv.x = -mvspeed;
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
					player.move(sf::Vector2f(0.f, mvspeed));
					mv.y = mvspeed;
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
					player.move(sf::Vector2f(mvspeed, 0.f));
					mv.x = mvspeed;
				}
			}
		}


		/// move the movable blocks

		for(int x = 0; x < mMvBlock; x++){
			if(steps < mSteps) {
				mvBlock[x].defMove();
				steps++;
			}else{
				mvBlock[x].setSpeed(sf::Vector2f(-mvBlock[x].getSpeed().x, -mvBlock[x].getSpeed().y));
				steps = 0;
			}
		}


		/// check collisions

		toMv = false;

		for(Block bl : fixedBlock){
			if(bl.colliding(player)){
				toMv = true;
			}
		}
		for(Block bl : mvBlock){
			if(bl.colliding(player)){
				toMv = true;
			}

			//TODO: clear this up
			if (bl.colliding(player, 1)) {
				if (((bl.getSpeed().x > 0) && (player.getPosition().x > bl.getPosition().x)) ||
					((bl.getSpeed().x < 0) && (player.getPosition().x < bl.getPosition().x)) ||
					((bl.getSpeed().y > 0) && (player.getPosition().y > bl.getPosition().y)) ||
					((bl.getSpeed().y < 0) && (player.getPosition().y < bl.getPosition().y))) {
					player.move(bl.getSpeed());
				}
			}
		}

		/// move player out of harms way if collisions were detected
		if(toMv){
			mv.x = mv.x * -1.f;
			mv.y = mv.y * -1.f;

			player.move(mv);
		}


		/// draw objects

		window.draw(player);
		for(const Block &todraw : fixedBlock){
			window.draw(todraw);
		}
		for(const Block &todraw : mvBlock){
			window.draw(todraw);
		}


		/// display everything on the window

		window.display();
	}


	/// close the program

	return 0;
}