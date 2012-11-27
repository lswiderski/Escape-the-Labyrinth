#include "Loading.h"
#include "Options.h"
#include "game.h"
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

	lose.setFont(resources::Font);
	lose.setCharacterSize(20);
	lose.setString("You choosed wrong way. Try again if u can.");
	lose.setPosition(200,160);
	lose.setColor(sf::Color::White);

	sf::Sound win;
	bool played=false;
	std::string mapName=Game::Maps[Game::getLevel()];

	mapName.erase(0,12);
	mapName.erase(mapName.size()-4,4);

	win.setBuffer(resources::s_win);
	win.setVolume(Options::Sound_Volume);
	load.setFont(resources::Font);
	load.setCharacterSize(20);
	
	load.setString("Loading level "+mapName);
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
		{	if(Game::wrongpath)
				App.draw(lose);
		
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