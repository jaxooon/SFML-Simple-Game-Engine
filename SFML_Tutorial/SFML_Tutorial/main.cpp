#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"

int main() 
{
	
	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close);

	//create a "player"
	
	sf::Texture playerTexture; 
	playerTexture.loadFromFile("tux_from_linux.png");


	Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.f);

	sf::Vector2u textureSize = playerTexture.getSize();

	float deltaTime = 0.0f;
	sf::Clock clock;

	//running while the window is open
	while (window.isOpen()) 
	{
		deltaTime = clock.restart().asSeconds();

		//create an sfml event
		sf::Event evnt;

		//this loop will run every time an event occurs
		while (window.pollEvent(evnt)) 
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				printf("New window width: %i New window height: %i \n", evnt.size.width, evnt.size.height);
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128)
				{
					printf("%c", evnt.text.unicode);
				}
				

			}
			
		}

		player.update(deltaTime);

		window.clear(sf::Color(150, 150, 150));
		player.Draw(window);
		window.display();
	}
	return 0;
}