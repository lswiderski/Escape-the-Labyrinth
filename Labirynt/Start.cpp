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
		App.draw(title);
		if(clock.getElapsedTime().asSeconds()>1)
		{
			Menu1.setString("The evil alchemist kidnapped you.");
			Menu1.setPosition(200,225);
			App.draw(Menu1);
		}
		
		
		if(clock.getElapsedTime().asSeconds()>3)
		{
			Menu1.setString("But you managed to escape from his cell.");
			Menu1.setPosition(170,275);
			App.draw(Menu1);
		}
		
		if(clock.getElapsedTime().asSeconds()>5)
		{
			Menu1.setString("Unfortunately, the lab spans a huge maze");
			Menu1.setPosition(165,325);
			App.draw(Menu1);
		}
		
		if(clock.getElapsedTime().asSeconds()>7)
		{
			Menu1.setString("and if you want to be safe and you have to beat it");
			Menu1.setPosition(130,375);
			App.draw(Menu1);
		}
		if(clock.getElapsedTime().asSeconds()>9)
		{
			Menu1.setString("Good luck");
			Menu1.setPosition(320,425);
			App.draw(Menu1);
		}
		App.display();
		App.clear(sf::Color::White);
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}