#include <SFML\Graphics.hpp>
#include <iostream>

int main() 
{
	
	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);

	//create a "player" and set its color to cyan
	sf::RectangleShape player(sf::Vector2f(100, 100));
	player.setFillColor(sf::Color::Cyan);
	player.setOrigin(50.0f, 50.0f);

	//running while the window is open
	while (window.isOpen()) 
	{

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

		//WASD controls
	/*	if (sf::keyboard::iskeypressed(sf::keyboard::key::a))
		{
			player.move(-0.1f, 0.0f);
		}
		if (sf::keyboard::iskeypressed(sf::keyboard::key::d))
		{
			player.move(0.1f, 0.0f);
		}
		if (sf::keyboard::iskeypressed(sf::keyboard::key::w))
		{
			player.move(0.0f, -0.1f);
		}
		if (sf::keyboard::iskeypressed(sf::keyboard::key::s))
		{
			player.move(0.0f, 0.1f);
		}*/

		//mouse controls
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));
		}

		window.clear();
		window.draw(player);
		window.display();
	}
	return 0;
}