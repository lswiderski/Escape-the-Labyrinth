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
	mode=0;



	
	

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
					if (mode==0)
					{
						Music_Volume--;
						if(Music_Volume<0)
							Music_Volume=100;
						resources::menu_music.setVolume(Music_Volume);
					}
					else if(mode==1)
					{
							Sound_Volume--;
						if (Sound_Volume<0)
							Sound_Volume=100;
					}
					
					break;
				case sf::Keyboard::Right:
					if (mode ==0)
					{
						
							Music_Volume++;
							if(Music_Volume>100)
								Music_Volume=0;
							resources::menu_music.setVolume(Music_Volume);
					}
					else if (mode == 1)
					{
						
							Sound_Volume++;
							if(Sound_Volume>100)
								Sound_Volume=0;
					}
					
					break;
				case sf::Keyboard::Up:
					mode--;
					if(mode<0)
						mode=0;
					
					break;
				case sf::Keyboard::Down:
					mode++;
					if(mode>1)
						mode=1;
					
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
		txt.setColor(sf::Color::White);
		txt.setString("Arrows : movement ");
		txt.setPosition(200,160);
			App.draw(txt);
			txt.setString("R : reset Map ");
			txt.setPosition(200,200);
		App.draw(txt);
		txt.setString("Space+Arrow: action (ex. Open Door)");
		txt.setPosition(200,240);
		App.draw(txt);
		txt.setString("Space: Pick Key or enter to portal");
		txt.setPosition(200,280);
		App.draw(txt);
		txt.setString("Volume Music: "+Game::ToString(Music_Volume));
		txt.setPosition(200,320);
		if(mode==0)
			txt.setColor(sf::Color::Red);
		else
		{
			txt.setColor(sf::Color::White);
		}
		App.draw(txt);
		txt.setString("Sound Music: "+Game::ToString(Sound_Volume));
		txt.setPosition(200,360);
		if(mode==1)
			txt.setColor(sf::Color::Red);
		else
		{
			txt.setColor(sf::Color::White);
		}
		App.draw(txt);

		App.display();
		
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}