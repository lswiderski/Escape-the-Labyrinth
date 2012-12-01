#include "Start.h"
#include <iostream>
#include "resources.h"
#include "menu.h"

Start::Start(void)
{
}


int Start::Run (sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;
	sf::Text Menu1;

	sf::Text nazwa;
	sf::Clock clock;
	Menu::playing = true;
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
					return(4);
					break;
				default :
					break;
				}
			}
		}
		//When getting at alpha_max, we stop modifying the sprite

		if(clock.getElapsedTime().asSeconds()>11)
			return 4;

		//Drawing
		App.setView(CameraPosition);
		App.draw(nazwa);
		if(clock.getElapsedTime().asSeconds()>1)
		{
			Menu1.setString("The evil alchemist kidnapped you.");
			Menu1.setPosition(200,225);
			App.draw(Menu1);
		}
		
		
		if(clock.getElapsedTime().asSeconds()>3)
		{
			Menu1.setString("But you managed to escape from his cell.");
			Menu1.setPosition(200,250);
			App.draw(Menu1);
		}
		
		if(clock.getElapsedTime().asSeconds()>5)
		{
			Menu1.setString("Unfortunately, the lab spans a huge maze");
			Menu1.setPosition(200,275);
			App.draw(Menu1);
		}
		
		if(clock.getElapsedTime().asSeconds()>7)
		{
			Menu1.setString("and if you want to be safe and you have to beat it");
			Menu1.setPosition(200,300);
			App.draw(Menu1);
		}
		if(clock.getElapsedTime().asSeconds()>9)
		{
			Menu1.setString("Good luck");
			Menu1.setPosition(200,325);
			App.draw(Menu1);
		}
		App.display();
		App.clear(sf::Color::White);
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}