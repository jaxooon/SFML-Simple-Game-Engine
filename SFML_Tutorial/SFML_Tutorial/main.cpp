#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"

static const float VIEW_HEIGHT = 512;

void resizeView(sf::RenderWindow& window, sf::View& view) 
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main() 
{
	
	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);

	sf::View view(sf::Vector2f(0.f, 0.f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

	//create a "player"
	sf::Texture playerTexture; 
	playerTexture.loadFromFile("tux_from_linux.png");

	Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.f);

	sf::Vector2u textureSize = playerTexture.getSize();

	//delta time is the time difference between the previous frame that was drawn and the current frame
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
				resizeView(window, view);
				break;
			}
			
		}

		player.update(deltaTime);

		view.setCenter(player.getPosition());

		window.clear(sf::Color(150, 150, 150));
		window.setView(view);
		player.Draw(window);
		window.display();
	}
	return 0;
}