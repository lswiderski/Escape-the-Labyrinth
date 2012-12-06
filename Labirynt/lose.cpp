#include "lose.h"
#include <iostream>
#include "resources.h"
#include "menu.h"
#include "Options.h"
#include "game.h"
Lose::Lose (void)
{

}
int Lose::left_life=0;
int Lose::Run (sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;
	sf::Text Menu1;

	sf::Sound win;
	bool played=false;
	win.setBuffer(resources::s_lose);
	win.setVolume(Options::Sound_Volume);
	Game::losed = true;
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
		{
			if(left_life)
				return 1;
			else {
				Game::reset=true;
				resources::bgm.stop();
				return 0;
			}
		}
			
		if(!played)
		{
			played=true;
			win.play();
		}
		//Drawing
		App.setView(CameraPosition);
		App.draw(title);
		Menu1.setString("You Died and earned "+Game::ToString(Game::LPkt)+" Points");
		Menu1.setPosition(220,250);
		App.draw(Menu1);
		Menu1.setString("So Sorry");
		Menu1.setPosition(320,300);
		App.draw(Menu1);
		App.display();
		App.clear(sf::Color::White);
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}

