#include "menu.h"
#include <sstream>
#include "Player.h"
#include "Options.h"
Menu::Menu (void)
{
	alpha_max = 3*255;
	alpha_div = 3;

	fp=NULL;
	saved=false;
}
bool Menu::playing = false;
int Menu::Run (sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;
	int alpha = 0;
	
	int menu = 0;

	sf::Sound SoundButtons;
	SoundButtons.setBuffer(resources::s_menuButton);
	bool play=false;
	SoundButtons.setVolume(Options::Sound_Volume);
	resources::menu_music.play();
	resources::menu_music.setLoop(true);
	resources::menu_music.setVolume(Options::Music_Volume);

	Konami="";
	Menu1.setFont(resources::Font);
	Menu1.setCharacterSize(20);
	Menu1.setString("Play");
	Menu1.setPosition(350,160);

	Menu2.setFont(resources::Font);
	Menu2.setCharacterSize(20);
	Menu2.setString("Exit");
	Menu2.setPosition(350,400);

	Menu3.setFont(resources::Font);
	Menu3.setCharacterSize(20);
	Menu3.setString("Continue");
	Menu3.setPosition(350,160);

	Menu4.setFont(resources::Font);
	Menu4.setCharacterSize(20);
	Menu4.setString("Load/Save");
	Menu4.setPosition(350,220);

	Menu5.setFont(resources::Font);
	Menu5.setCharacterSize(20);
	Menu5.setString("Load");
	Menu5.setPosition(350,220);

	Menu6.setFont(resources::Font);
	Menu6.setCharacterSize(20);
	Menu6.setString("Options");
	Menu6.setPosition(350,280);

	Menu7.setFont(resources::Font);
	Menu7.setCharacterSize(20);
	Menu7.setString("Credits");
	Menu7.setPosition(350,340);

	stan.setFont(resources::Font);
	stan.setCharacterSize(20);
	stan.setPosition(450,220);
	stan.setColor(sf::Color::Black);

	nazwa.setFont(resources::Font);
	nazwa.setCharacterSize(30);
	nazwa.setString("Escape the labyrinth");
	nazwa.setPosition(230,100);
	nazwa.setColor(sf::Color::Black);

	ver.setFont(resources::Font);
	ver.setCharacterSize(10);
	ver.setString("ver: 0.2.3a");
	ver.setPosition(0,590);
	ver.setColor(sf::Color::Black);
	sf::View CameraPosition;
	CameraPosition=App.getDefaultView();


	if (playing)
	{
		alpha = alpha_max;
	}

	while (Running)
	{
	
		if(play)
		{
			SoundButtons.play();
			play=false;
		}
		if (Konami=="0011232345")
		{
			resources::menu_music.stop();
			return 9;
		}
		else if(Konami.size()>10)
			Konami="";
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
				case sf::Keyboard::Up:
					menu-=1;
					if(menu<0) menu=0;
					Konami+="0";
					play=true;
					break;
				case sf::Keyboard::Down:
					menu+= 1;
					if(menu>4)menu=4;
					Konami+="1";
					play=true;
					break;
				case sf::Keyboard::Left:
					Konami+="2";
					break;	
				case sf::Keyboard::Right:
					Konami+="3";
					break;
				case sf::Keyboard::B:
					Konami+="4";
					break;	
				case sf::Keyboard::A:
					Konami+="5";
					break;	
				case sf::Keyboard::Return:
					if (menu==0)
					{
						resources::menu_music.stop();
						//Let's get play !
						if (Game::getSame())
						{
							
							playing = true;
							return 1;
						}
						saved=false;
						if(!Game::loaded)
						{
							playing = true;
							return 8;
						}
						playing = true;
						return (4);
					}
					else if(menu==2)
					{
						return(5);
					}
					else if(menu==1)
					{
						return 10;
						
					}
					else if(menu==3)
					{
						return(6);
					}
					else
					{
						//Let's get work...
						return (-1);
					}
					break;
				case sf::Keyboard::Escape:
					saved=false;
					if(playing) return (1);
					else return(-1);
					break;
				default :
					Konami+="x";
					break;
				}
			}
		}
		//When getting at alpha_max, we stop modifying the sprite
		if (alpha<alpha_max)
		{
			alpha=alpha+10;
			if(alpha>alpha_max) alpha=alpha_max;
		}
		nazwa.setColor(sf::Color(0, 0, 0, alpha/alpha_div));
		if (menu==0)
		{
			Menu1.setColor(sf::Color(255, 0, 0, 255));
			Menu2.setColor(sf::Color(0, 0, 0, 255));
			Menu3.setColor(sf::Color(255, 0, 0, 255));
			Menu4.setColor(sf::Color(0, 0, 0, 255));
			Menu5.setColor(sf::Color(0, 0, 0, 255));
			Menu6.setColor(sf::Color(0, 0, 0, 255));
			Menu7.setColor(sf::Color(0, 0, 0, 255));

		}
		else if(menu==1)
		{
			Menu1.setColor(sf::Color(0, 0, 0, 255));
			Menu2.setColor(sf::Color(0, 0, 0, 255));
			Menu3.setColor(sf::Color(0, 0, 0, 255));
			Menu4.setColor(sf::Color(255, 0, 0, 255));
			Menu5.setColor(sf::Color(255, 0, 0, 255));
			Menu6.setColor(sf::Color(0, 0, 0, 255));
			Menu7.setColor(sf::Color(0, 0, 0, 255));
		}
		else if(menu==2)
		{
			Menu1.setColor(sf::Color(0, 0, 0, 255));
			Menu2.setColor(sf::Color(0, 0, 0, 255));
			Menu3.setColor(sf::Color(0, 0, 0, 255));
			Menu4.setColor(sf::Color(0, 0, 0, 255));
			Menu5.setColor(sf::Color(0, 0, 0, 255));
			Menu6.setColor(sf::Color(255, 0, 0, 255));
			Menu7.setColor(sf::Color(0, 0, 0, 255));
		}

		else if(menu==3)
		{
			Menu1.setColor(sf::Color(0, 0, 0, 255));
			Menu2.setColor(sf::Color(0, 0, 0, 255));
			Menu3.setColor(sf::Color(0, 0, 0, 255));
			Menu4.setColor(sf::Color(0, 0, 0, 255));
			Menu5.setColor(sf::Color(0, 0, 0, 255));
			Menu6.setColor(sf::Color(0, 0, 0, 255));
			Menu7.setColor(sf::Color(255, 0, 0, 255));
		}

		else if(menu==4)
		{
			Menu1.setColor(sf::Color(0, 0, 0, 255));
			Menu2.setColor(sf::Color(255, 0, 0, 255));
			Menu3.setColor(sf::Color(0, 0, 0, 255));
			Menu4.setColor(sf::Color(0, 0, 0, 255));
			Menu5.setColor(sf::Color(0, 0, 0, 255));
			Menu6.setColor(sf::Color(0, 0, 0, 255));
			Menu7.setColor(sf::Color(0, 0, 0, 255));
		}


		//Drawing
		App.clear(sf::Color::White);
		App.setView(CameraPosition);
		if (alpha==alpha_max)
		{
			if (playing)
			{
				App.draw(Menu3);
				
			}
			else
			{
				App.draw(Menu1);

			}
			App.draw(Menu4);
			App.draw(Menu2);
			App.draw(Menu6);
			App.draw(Menu7);
		}
		if(saved)
			App.draw(stan);	
		App.draw(nazwa);
		App.draw(ver);
		App.display();
		
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}