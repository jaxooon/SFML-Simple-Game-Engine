#include <SFML\Graphics.hpp>
#include <iostream>

int main() 
{
	
	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);

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
	}
	return 0;
}