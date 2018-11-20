#include <SFML/Graphics.hpp>

#include "blocks.h"

#include <iostream>



/** EDITABLE VARIABLES **/

const int mBlock = 4;
float mvspeed = 10.0;
sf::Vector2f blockPs[mBlock] = {sf::Vector2f(100.f, 100.f), sf::Vector2f(120.f, 100.f), sf::Vector2f(140.f, 100.f), sf::Vector2f(160.f, 100.f)};



/** UNEDITABLE VARIABLES & CODE **/

sf::Vector2f playerPos;
sf::Vector2f blockPos;

sf::Vector2f mv;

bool toMv = false;


int main() {
//    sf::RenderWindow window(sf::VideoMode(1360, 768), "My window", sf::Style::Fullscreen);
	sf::RenderWindow window(sf::VideoMode(600, 600), "Epic Game");
	window.setFramerateLimit(60);

	sf::Texture texture;
	texture.loadFromFile("/home/kip/CLionProjects/sfml-app/assets/textures.png");

	Block player;

	player.setTexture(texture);
	player.setTextureRect(sf::IntRect(0, 0, 20, 20));
	player.setOrigin(10.f, 10.f);
	player.storeSize(20, 20);

	Block block[mBlock];

	for(int x = 0; x < mBlock; x++) {
		block[x].setTexture(texture);
		block[x].setTextureRect(sf::IntRect(20, 0, 20, 20));

		block[x].storeSize(20, 20);
		block[x].setOrigin((block[x].getSize().x / 2), (block[x].getSize().y / 2));
		block[x].setPosition(blockPs[x]);
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);

		mv.x = 0.f;
		mv.y = 0.f;

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

		playerPos.x = player.getPosition().x;
		playerPos.y = player.getPosition().y;

		toMv = false;

		for(Block bl : block) {
			blockPos.x = bl.getPosition().x;
			blockPos.y = bl.getPosition().y;

			float xdiff = (bl.getSize().x / 2) + (player.getSize().x / 2);
			float ydiff = (bl.getSize().y / 2) + (player.getSize().y / 2);

			if ((playerPos.x > (blockPos.x - xdiff)) && (playerPos.x < (blockPos.x + xdiff)) &&
				(playerPos.y > (blockPos.y - ydiff)) && (playerPos.y < (blockPos.y + ydiff))) {

				toMv = true;

			}
		}

		if(toMv){
			mv.x = mv.x * -1.f;
			mv.y = mv.y * -1.f;

			player.move(mv);
		}

		window.draw(player);
		for(const Block &todraw : block){
			window.draw(todraw);
		}
		window.display();
	}

	return 0;
}