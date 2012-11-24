#include "Options.h"
#include "resources.h"
#include <iostream>

Options::Options(void)
{
}
int Options::Music_Volume=70;
int Options::Sound_Volume=90;

int Options::Run (sf::RenderWindow &App)
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
				case sf::Keyboard::Left:
					if(Music_Volume>0)
					Music_Volume--;
					break;
				case sf::Keyboard::Right:
					if(Music_Volume<100)
						Music_Volume++;
					break;
				case sf::Keyboard::Up:
					if(Sound_Volume<100)
						Sound_Volume++;
					break;
				case sf::Keyboard::Down:
					if (Sound_Volume>0)
					{
						Sound_Volume--;
					}
					break;
				default :
					break;
				}
			}
		}
		//When getting at alpha_max, we stop modifying the sprite



		//Drawing
		App.clear();
		App.setView(CameraPosition);
		
		txt.setString("Arrows : movement ");
		txt.setPosition(200,160);
			App.draw(txt);
			txt.setString("R : reset Map ");
			txt.setPosition(200,200);
		App.draw(txt);
		txt.setString("Space+Arrow: action (ex. Open Door)");
		txt.setPosition(200,240);
		App.draw(txt);
		txt.setString("Space+Enter: Pick Key or enter to portal");
		txt.setPosition(200,280);
		App.draw(txt);
		txt.setString("Volume Music: "+Game::ToString(Music_Volume)+" Arrowrs <- / ->");
		txt.setPosition(200,320);
		App.draw(txt);
		txt.setString("Sound Music: "+Game::ToString(Sound_Volume)+ " Arrowrs V / /\\");
		txt.setPosition(200,360);
		App.draw(txt);

		App.display();
		
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}