#include "Credits.h"
#include <iostream>

Credits::Credits(void)
{
}


int Credits::Run (sf::RenderWindow &App)
{

	sf::Event Event;
	bool Running = true;



	txt.setFont(resources::Font);
	txt.setCharacterSize(20);
	
	txt.setColor(sf::Color::White);


	

	sf::View CameraPosition;
	CameraPosition=App.getDefaultView();


	while (Running)
	{
		//Verifying events
		while (App.pollEvent(Event))
		{
			// Window cLoadingd
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
					return (0);
					break;
				default :
					break;
				}
			}
		}
		//When getting at alpha_max, we stop modifying the sprite



		//Drawing

		App.setView(CameraPosition);


		txt.setString("Code & Design:	Lukasz Swiderski");
		txt.setPosition(180,180);
		App.draw(txt);
		txt.setString("               Music:	Marek Rubczewski");
		txt.setPosition(180,220);
		App.draw(txt);
		txt.setString("made by neufrin.com");
		txt.setPosition(300,570);
		App.draw(txt);



		App.display();
		App.clear();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}