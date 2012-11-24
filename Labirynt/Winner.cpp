#include "Winner.h"

#include <iostream>
#include "resources.h"
#include "menu.h"
Winner::Winner(void)
{
}

int Winner::Run (sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;
	sf::Text Menu1;

	sf::Text nazwa;
	sf::Clock clock;
	Menu::playing = false;
	nazwa.setFont(resources::Font);
	nazwa.setCharacterSize(30);
	nazwa.setString("Escape the labyrinth");
	nazwa.setPosition(230,100);
	nazwa.setColor(sf::Color::Black);

	Menu1.setFont(resources::Font);
	Menu1.setCharacterSize(20);

	Menu1.setColor(sf::Color::Black);

	sf::View CameraPosition;
	CameraPosition=App.getDefaultView();
	while (Running)
	{
		//Verifying events
		while (App.pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
			//Key pressed
			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{
				case sf::Keyboard::Escape:
					return(-1);
					break;
				default :
					break;
				}
			}
		}
		//When getting at alpha_max, we stop modifying the sprite

		if(clock.getElapsedTime().asSeconds()>5)
			return 0;

		//Drawing
		App.setView(CameraPosition);
		App.draw(nazwa);
		Menu1.setString("Congratulations");
		Menu1.setPosition(350,200);
		App.draw(Menu1);
		Menu1.setString("You finished the Demo");
		Menu1.setPosition(250,250);
		App.draw(Menu1);
		App.display();
		App.clear(sf::Color::White);
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}
