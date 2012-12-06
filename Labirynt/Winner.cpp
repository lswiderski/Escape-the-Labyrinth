#include "Winner.h"

#include <iostream>
#include "resources.h"
#include "menu.h"
#include "game.h"
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
	title.setTexture(resources::Game_title);
	title.setPosition(200,80);

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
		App.draw(title);
		Menu1.setString("Congratulations");
		Menu1.setPosition(310,250);
		App.draw(Menu1);
		Menu1.setString("You finished the Demo\nand Earned "+Game::ToString(Game::LPkt)+" Points");
		Menu1.setPosition(270,300);
		App.draw(Menu1);
		App.display();
		App.clear(sf::Color::White);
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}
