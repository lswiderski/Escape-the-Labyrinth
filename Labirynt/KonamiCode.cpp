#include "KonamiCode.h"
#include <iostream>
#include "resources.h"
#include "menu.h"

KonamiCode::KonamiCode(void)
{
}
bool KonamiCode::konami=false;
int KonamiCode::lvl=0;
int KonamiCode::Run (sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;
	sf::Text Menu1;
	sf::Text lvls;
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

	lvls.setPosition(550,230);
	lvls.setColor(sf::Color::Black);
	lvls.setFont(resources::Font);
	lvls.setCharacterSize(20);

	sf::View CameraPosition;
	CameraPosition=App.getDefaultView();
	clock.restart();
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
				case sf::Keyboard::Up:
					if(lvl<Game::Maps.size()-1)
					lvl++;
					break;
				case sf::Keyboard::Down:
					if(lvl>0)
					lvl--;
					break;
				case sf::Keyboard::Return:
					konami=true;
					return (1);
					break;
				default :
					break;
				}
			}
		}
		//When getting at alpha_max, we stop modifying the sprite


		lvls.setString(Game::ToString(lvl+1));
		//Drawing
		App.setView(CameraPosition);
		App.draw(nazwa);
		Menu1.setString("Welcome in secret Place:");
		Menu1.setPosition(300,200);
		App.draw(Menu1);
		Menu1.setString("Select Level:");
		Menu1.setPosition(350,230);
		App.draw(Menu1);
		App.draw(lvls);
		App.display();
		App.clear(sf::Color::White);
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}
