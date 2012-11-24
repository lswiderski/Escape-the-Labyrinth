#include "Loading.h"
#include "Options.h"

#include <iostream>
Loading::Loading (void)
{
	clock.restart();
	level = 0;
	first = true;
}

int Loading::Run (sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;


	level = Game::getLevel();
	lvl=Game::ToString(level);
	
	pass.setFont(resources::Font);
	pass.setCharacterSize(20);
	pass.setString("Congratulations, you passed level "+ lvl);
	pass.setPosition(200,160);
	pass.setColor(sf::Color::White);

	sf::Sound win;
	bool played=false;
	win.setBuffer(resources::s_win);
	win.setVolume(Options::Sound_Volume);
	load.setFont(resources::Font);
	load.setCharacterSize(20);
	load.setString("Loading level "+Game::ToString(level+1));
	load.setPosition(200,200);
	load.setColor(sf::Color::White);
	sf::View CameraPosition;
	CameraPosition=App.getDefaultView();

	clock.restart();
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
			
		}
		//When getting at alpha_max, we stop modifying the sprite

	

		//Drawing
		if(clock.getElapsedTime().asSeconds()>3)
		{first=false;
		resources::bgm.stop();
			return 1;}
		App.setView(CameraPosition);
		if(!first)
		{	
			App.draw(pass);
		}
		if(!first && !played)
		{
			played=true;
			win.play();
		}
		App.draw(load);

		

		App.display();
		App.clear();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}