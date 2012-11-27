#include "Loadsave.h"


Loadsave::Loadsave(void)
{
}


int Loadsave::Run (sf::RenderWindow &App)
{

	sf::Event Event;
	bool Running = true;



	load_t.setFont(resources::Font);
	load_t.setCharacterSize(20);
	load_t.setColor(sf::Color::White);
	load_t.setString("Load");
	load_t.setPosition(200,160);

	save_t.setFont(resources::Font);
	save_t.setCharacterSize(20);
	save_t.setColor(sf::Color::White);
	save_t.setString("Save");
	save_t.setPosition(200,200);

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


		
		

		App.draw(load_t);
		App.draw(save_t);



		App.display();
		App.clear();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}
