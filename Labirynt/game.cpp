#include "game.h"
#include "lose.h"
#include <fstream>
#include "Options.h"
bool Game::same =false;
short Game::map=0;
int Game::PLAYER_X=100;
int Game::PLAYER_Y=100;
bool Game::loaded=false;
std::vector<std::string> Game::Maps;
int Game::LPkt=0;
int Game::LMap=0;
int Game::LLives=0;
bool Game::LDone_map[100];
std::string Game::LId_map="0000000000000000";
std::string Game::id_map="0000000000000000";

void Game::setLevel(short lvl)
{
	map=lvl;
}
void Game::setPos(int x,int y)
{
	PLAYER_X=x;
	PLAYER_Y=y;
}

short Game::getLevel()
{
	return map;
}
bool Game::getSame()
{
	return same;

}


void Game::Reset()
{
	winner= false;
	win=false;
	lose=false;
	Running = true;
	showDialogBox=false;

	
	zebrane_mikstury=0;
	Czas_Gry.restart();
	przeszly_czas=0;
	player.setHearts(3);
	player.setKeys(0);
	player.setLife(3);
	player.setLvl(1);
	player.setPkt(0);
	player.setTotalPkt(0);
	mapa.loadMap(Maps[0].c_str());
	G_PLAYER_X=mapa.coordinates[0];
	G_PLAYER_Y=mapa.coordinates[1];
	player.teleport(G_PLAYER_X,G_PLAYER_Y);
	//std::cout<<"zresetowalo xD"<<std::endl;
	
}
void Game::restart(bool next){

	Running = true;
	
	if(done_maps[player.getLvl()]==true)
	{
		//std::cout<<"Plansza Byla"<<std::endl;
	}
	else
	{
		//std::cout<<"Planszy Niebylo"<<std::endl;
	}
	if(next)
	{
		for (int i=0;i<Maps.size();i++)
		{
		//	std::cout<<"i: "<<i<<" Maps: "<<Maps[i]<<" nextlvl: "<<nextLvl<<std::endl;
			if(Maps[i]=="Data/levels/"+nextLvl)
			{
				done_maps[player.getLvl()]=true;
				player.setLvl(i);
				break;
			}
			else if(nextLvl=="success")
			{
				winner=true;
			}
			else if(nextLvl=="wrongpath")
			{
				wrongpath=true;
			}
		}
		//player.setLvl(player.getLvl()+1);
		same=false;
		player.setTotalPkt(player.getPkt());
		
	}
	else{ same=true;
	player.setPkt(player.getTotalPkt());
	}

	
	player.setKeys(0);
	LPkt=player.getTotalPkt();

	//if(player.getLvl()>Maps.size()-1) winner=true;
	if(!winner)
	{
	
	map=player.getLvl();
	mapa.loadMap(Maps[player.getLvl()].c_str());
	if(!(Maps[player.getLvl()]=="Data/levels/"+mapa.mapName && Map_code[player.getLvl()]==mapa.map_code))
	{
		bledna_mapa=true;
	}

	G_PLAYER_X=mapa.coordinates[0];
	G_PLAYER_Y=mapa.coordinates[1];
	player.teleport(G_PLAYER_X,G_PLAYER_Y);
	}
	zebrane_mikstury=0;
	przeszly_czas=0;
	win=false;
}

Game::Game (void)	
{
	bledna_mapa=false;
	nextLvl="";
	winner= false;
	win=false;
	//lose=false;
	Running = true;
	showDialogBox=false;
	G_PLAYER_X=mapa.coordinates[0];
	G_PLAYER_Y=mapa.coordinates[1];
	zebrane_mikstury=0;
	player.Initialize(G_PLAYER_X,G_PLAYER_Y);
	player.LoadContent();

	camera.Initialize();

	if(tloImage.loadFromFile("Data/images/tlo.png"))
		tlo.setTexture(tloImage);


	//if(buffer.loadFromFile("Data/music/cowbell.wav"))
	//	sound.setBuffer(buffer);


	gui.setTexture(resources::GUI);

	HUD.setSize(ScreenWidth,100);
	HUD.setCenter(ScreenWidth/2,50);
	HUD.setViewport(sf::FloatRect(0,0,1,0.2));

	Dialog.setSize(ScreenWidth,100);
	Dialog.setCenter(ScreenWidth/2,50);
	Dialog.setViewport(sf::FloatRect(0,0.8,1,0.2));

	dialogBox.setSize(sf::Vector2f(ScreenWidth,100));
	dialogBox.setFillColor(sf::Color::Blue);

	dialogBG.setTexture(resources::dialogbox);
	dialogBG.setPosition(80,0);


	DialogText.setFont(resources::Font);
	DialogText.setCharacterSize(15);
	DialogText.setColor(sf::Color::White);
	DialogText.setPosition(100,20);

	Timer.setFont(resources::Font);
	Timer.setCharacterSize(15);
	Timer.setColor(sf::Color::White);
	Timer.setPosition(750,7);

	cheater.setFont(resources::Font);
	cheater.setCharacterSize(45);
	cheater.setColor(sf::Color::White);
	cheater.setPosition(300,295);
	cheater.setString("Wrong map file");

	coiny.setFont(resources::Font);
	coiny.setCharacterSize(15);
	coiny.setColor(sf::Color::White);
	coiny.setPosition(0,7);

	keye.setFont(resources::Font);
	keye.setCharacterSize(15);
	keye.setColor(sf::Color::White);
	keye.setPosition(400,7);

	FILE *fp;
	fp=fopen("Data/levels/levels.dat", "r+b");
	std::string stmp;
	int tmpint;
	char id_map_tmp[16];
	char ctmp[1];
	int h,x;
	fread(&id_map_tmp, sizeof(char),16,fp);
	id_map="";
	for (int i=0;i<16;i++)
	{
		id_map+=id_map_tmp[i];
	}
	fread(&h, sizeof(int),1,fp);

	for(int i=0;i<h;i++)
	{
		fread(&x, sizeof(int),1,fp);
		for (int z=0;z<x;z++)
		{
			fread(ctmp, sizeof(char),1,fp);
			stmp+=ctmp[0];


		}
		Maps.push_back(stmp);
		//std::cout<<stmp<<std::endl;
		stmp="";
		fread(&tmpint, sizeof(int),1,fp);
		Map_code.push_back(tmpint);
	}

	fclose(fp);
	LId_map = id_map;
	for (int i=0;i<Maps.size();i++)
	{
		
	}

	showTlo=true;
	Czas_Gry.restart();
	przeszly_czas=0;
	for (int i=0;i<100;i++)
	{
		done_maps[i]=false;
	}

}

bool Game::wrongpath=false;
bool Game::losed=false;
bool Game::reset=false;


int Game::Run (sf::RenderWindow &Window)
{
	Window.setFramerateLimit(60);
	//actual_dialog=1;
	//actual_fragment=0;
	
	showDialogBox=false;
	same=true;
	sf::Clock Clock;
	Czas_Gry.restart();

	sf::Sound Sounds;
	Sounds.setVolume(Options::Sound_Volume);
	bool play_sound=false;

	sf::Sound timer;
	timer.setBuffer(resources::s_timer);
	Sounds.setVolume(Options::Sound_Volume+10);
	bool play_timer=false;
	bool actual_playing=false;
	resources::bgm.play();
	resources::bgm.setLoop(true);
	resources::bgm.setVolume(Options::Music_Volume);

	if(KonamiCode::konami)
	{
		player.setLvl(KonamiCode::lvl);
		restart(false);
		player.setLife(999);
		mapa.time_map=999;
		//KonamiCode::konami=false;
	}

	
	
	if(reset)
	{
		reset=false;
		Reset();
	}
	if (loaded)
	{


		player.setLvl(LMap);
		player.setTotalPkt(LPkt);
		player.setPkt(LPkt);
		for(int i=0;i<100;i++)
		{
			done_maps[i]=LDone_map[i];
		}
		id_map=LId_map;
		restart(false);
		loaded=false;
		
	}

	while (Running)
	{	
		if(wrongpath)
		{

			Lose::left_life=player.getLife();
			player.addLife(-1);

			restart(true);
			//losed=true;
			wrongpath=false;
			return 2;
		}
		if(losed)
		{
			restart(false);
			losed=false;
			player.setHearts(3);
		}

		if(winner)
		{
			//std::cout<<"XDDDDDDDDDDDDDDDDDDDDDDDD"<<std::endl;
			LPkt=player.getPkt();
			nextLvl="";
			Reset();
			win=false;
			return 7;
		}
		
		if(win)
			{
				if(!done_maps[player.getLvl()])
				{
					player.setTotalPkt(player.getPkt()+time_left);
					player.setPkt(player.getPkt()+time_left);
				}
				
				win=false;
				restart(true);
				if(winner) {
					nextLvl="";
					Reset();
					return 7;
				}
		return 4;
		}
		if(wrongpath)
			wrongpath=false;
		if(Czas_Gry.getElapsedTime().asSeconds()>1)
		{
			przeszly_czas++;
			Czas_Gry.restart();
		}
		//Verifying events
		while (Window.pollEvent(Event))
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
					resources::bgm.stop();
					LLives=player.getLife();
					LPkt=player.getTotalPkt();
					LMap=player.getLvl();
					for(int i=0;i<100;i++)
					{
						LDone_map[i]=done_maps[i];
					}
					LId_map = id_map;
					return (0);
					break; 
				case sf::Keyboard::F1:
					if(!hud)
						hud=true;
					else hud=false;
					break;
				case sf::Keyboard::F2:
					if(!showTlo)
						showTlo=true;
					else showTlo=false;
					break;
				case sf::Keyboard::R:
					restart(false);
					player.addLife(-1);
					break;
				default:
					break;
				}
			}

			

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{

				if(mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64)][1]==4)
				{
					
					for (int i=0;i<mapa.portals.size();i++)
					{
						//std::cout<<mapa.portals[i][0]<<" "<<mapa.portals[i][1]<<" "<<mapa.portals[i][2]<<std::endl;
						//std::cout<<player.getX()/64<<" "<<player.getY()/64<<std::endl;
						if(mapa.portals[i][1]==(int)player.getY()/64 && mapa.portals[i][0]==(int)player.getX()/64)
						{
							//std::cout<<"znalazlo: "<<mapa.portals[i][2]<<std::endl;
							nextLvl=mapa.nextMap[mapa.portals[i][2]];
							//std::cout<<"nextlvl: "<<nextLvl<<std::endl;
							break;
						}
					}
					if(nextLvl=="wrongpath")
					{
						wrongpath=true;
					}
					else 
						win=true;
				}
				else if(mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64)][1]==12)
				{
					player.addKeys(1);
					mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64)][1]=0;
				}

				else if(mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64)][1]==14)
				{
					Sounds.setBuffer(resources::s_tp);
					play_sound=true;
					for (int i=0;i<mapa.vteleports;i++)
					{
						if(mapa.teleports[i][0]==(int)(player.getX()/64) && mapa.teleports[i][1]==(int)(player.getY()/64))
						{
							
							player.teleport((mapa.teleports[i][2])*64+32,(mapa.teleports[i][3])*64+32);
							break;
						}
					}

				}


				if(mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64)][1]==22)
				{
					if(Clock.getElapsedTime().asMilliseconds()>50)
					{
						
						Sounds.setBuffer(resources::s_lancuch);
						play_sound=true;
					
					for (int i=0;i<mapa.vlevers;i++)
					{
						if(mapa.levers[i][0]==(int)(player.getX()/64) && mapa.levers[i][1]==(int)(player.getY()/64))
						{
							mapa.levers[i][2]=0;
							mapa.checkGate(i,false);
							break;
						}
					}
					mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64)][1]=24;
					
					}	
					Clock.restart();
				}


				else if(mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64)][1]==24)
				{
					if(Clock.getElapsedTime().asMilliseconds()>50)
					{
						Sounds.setBuffer(resources::s_lancuch);
						play_sound=true;
					for (int i=0;i<mapa.vlevers;i++)
					{
						if(mapa.levers[i][0]==(int)(player.getX()/64) && mapa.levers[i][1]==(int)(player.getY()/64))
						{
							mapa.levers[i][2]=1;
							mapa.checkGate(i,true);
							break;
						}
					}
					mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64)][1]=22;
					}	
					Clock.restart();
				}

				else if(showDialogBox)
				{
					
					if(Clock.getElapsedTime().asMilliseconds()>50)
					{
						actual_fragment++;
						if(actual_fragment>=mapa.txts[actual_dialog].size())
						{

							showDialogBox=false;
							actual_fragment=0;
						}
						
						DialogText.setString(mapa.txts[mapa.Npcs[actual_dialog][2]][actual_fragment]);
								
							
						




					}	
					Clock.restart();
				}
					
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				
				 if (mapa.MapVector[(int)(player.getY()/64+1)][(int)(player.getX()/64)][2]==11 && player.getKeys()>0)
				{
					Sounds.setBuffer(resources::s_key);
					play_sound=true;
					mapa.MapVector[(int)(player.getY()/64+1)][(int)(player.getX()/64)][2]=0;
					player.addKeys(-1);
				}
				 else if (mapa.MapVector[(int)(player.getY()/64+1)][(int)(player.getX()/64)][2]==13)
				 {

					 for (int i=0;i<mapa.Npcs.size();i++)
					 {
						 if(mapa.Npcs[i][0]==(int)(player.getX()/64) && mapa.Npcs[i][1]==(int)(player.getY()/64+1))
						 {
							 actual_fragment=0;
							 showDialogBox=true;
							 actual_dialog=i;
							 DialogText.setString(mapa.txts[mapa.Npcs[actual_dialog][2]][actual_fragment]);
							 break;
						 }
					 }


				 }
				 else if (mapa.MapVector[(int)(player.getY()/64+1)][(int)(player.getX()/64)][2]==7)
				 {
					if(mapa.moveBox((player.getY()/64+1),(player.getX()/64),2))
					{
						Sounds.setBuffer(resources::s_box);
						play_sound=true;
					}
				 }
				

			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				if (mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64-1)][2]==11 && player.getKeys()>0)
				{
					Sounds.setBuffer(resources::s_key);
					play_sound=true;
					mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64-1)][2]=0;
					player.addKeys(-1);
				}
				else if (mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64-1)][2]==13)
				{

					for (int i=0;i<mapa.Npcs.size();i++)
					{
						if(mapa.Npcs[i][0]==(int)(player.getX()/64-1) && mapa.Npcs[i][1]==(int)(player.getY()/64))
						{
							actual_fragment=0;
							showDialogBox=true;
							actual_dialog=i;
							DialogText.setString(mapa.txts[mapa.Npcs[actual_dialog][2]][actual_fragment]);
							break;
						}
					}


				}
				else if (mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64-1)][2]==7)
				{
					if(mapa.moveBox((player.getY()/64),(player.getX()/64-1),3))
					{
						Sounds.setBuffer(resources::s_box);
						play_sound=true;
					}
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				if (mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64+1)][2]==11 && player.getKeys()>0)
				{
					Sounds.setBuffer(resources::s_key);
					play_sound=true;
					mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64+1)][2]=0;
					player.addKeys(-1);
				}
				else if (mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64+1)][2]==13)
				{

					for (int i=0;i<mapa.Npcs.size();i++)
					{
						if(mapa.Npcs[i][0]==(int)(player.getX()/64+1) && mapa.Npcs[i][1]==(int)(player.getY()/64))
						{
							actual_fragment=0;
							showDialogBox=true;
							actual_dialog=i;
							DialogText.setString(mapa.txts[mapa.Npcs[actual_dialog][2]][actual_fragment]);
							break;
						}
					}


				}
				else if (mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64+1)][2]==7)
				{
					if(mapa.moveBox((player.getY()/64),(player.getX()/64+1),1))
					{
						Sounds.setBuffer(resources::s_box);
						play_sound=true;
					}
				}

			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				if (mapa.MapVector[(int)(player.getY()/64-1)][(int)(player.getX()/64)][2]==11 && player.getKeys()>0)
				{
					Sounds.setBuffer(resources::s_key);
					play_sound=true;
					mapa.MapVector[(int)(player.getY()/64-1)][(int)(player.getX()/64)][2]=0;
					player.addKeys(-1);
				}
				else if (mapa.MapVector[(int)(player.getY()/64-1)][(int)(player.getX()/64)][2]==13)
				{

					for (int i=0;i<mapa.Npcs.size();i++)
					{
						if(mapa.Npcs[i][0]==(int)(player.getX()/64) && mapa.Npcs[i][1]==(int)(player.getY()/64-1))
						{
							actual_fragment=0;
							showDialogBox=true;
							actual_dialog=i;
							DialogText.setString(mapa.txts[mapa.Npcs[actual_dialog][2]][actual_fragment]);
							
							break;
						}
					}
					
					
				}
				else if (mapa.MapVector[(int)(player.getY()/64-1)][(int)(player.getX()/64)][2]==7)
				{
					if(mapa.moveBox((player.getY()/64-1),(player.getX()/64),0))
					{
						Sounds.setBuffer(resources::s_box);
						play_sound=true;
					}
				}


			}
		}

		//Updating

		if(play_sound)
		{
			Sounds.play();
			play_sound=false;
		}
			

		//Drawing
		Window.clear();
		
		camera.Update(player.getX(), player.getY());
		player.Update(Window,mapa.MapVector);
		if(mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64)][1]==10)
		{
			Sounds.setBuffer(resources::s_potion);
			play_sound=true;
			if(!done_maps[player.getLvl()])
			player.addPkt(10);
			zebrane_mikstury+=10;
			mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64)][1]=0;
		}
		else if(mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64)][1]==26)
		{
			Sounds.setBuffer(resources::s_potion);
			play_sound=true;
			if(!done_maps[player.getLvl()])
			player.addPkt(10);
			zebrane_mikstury-=5;
			mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64)][1]=0;
		}
		else if(mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64)][1]==16)
		{
			Sounds.setBuffer(resources::s_potion);
			play_sound=true;
			if(player.getHearts()<6)
			player.addHearts(1);
			else
			{
				player.addLife(1);
					player.setHearts(3);
			}
			
			mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64)][1]=0;
			//std::cout<<player.getHearts()<<std::endl;
		}
		else if(Clock.getElapsedTime().asMilliseconds()>250){
		if(mapa.MapVector[(int)(player.getY()/64)][(int)(player.getX()/64)][0]==18)
		{
			Sounds.setBuffer(resources::s_lava);
			play_sound=true;
			player.addHearts(-1);
			Clock.restart();
			if(player.getHearts()<0)
			{
				//lose=true;
				Lose::left_life=player.getLife();
				player.addLife(-1);

				restart(false);
				losed=true;

				return 2;
			}
				
		}
		}
		keye.setString(" : "+ToString(player.getKeys()));
		coiny.setPosition(450,7);
		coiny.setString("Score : "+ToString(player.getPkt()));
		
		
		Window.setView(camera.getView());
		if (bledna_mapa)
		{
			Window.draw(cheater);
			return -1;
		}
		else
		{
			mapa.drawMap(Window,player);

			G_PLAYER_X=player.getX();
			G_PLAYER_Y=player.getY();

			setPos(player.getX(),player.getY());
			player.Draw(Window);

			tlo.setOrigin(405,305);
			tlo.setPosition(player.getX(),player.getY());
			if(showTlo)
				Window.draw(tlo);


			Window.setView(HUD);
			gui.setTextureRect(sf::IntRect(1*32,0,32,32));
			gui.setPosition(720,0);
			Window.draw(gui);

			gui.setTextureRect(sf::IntRect(2*32,0,32,32));
			gui.setPosition(370,0);
			Window.draw(gui);

			gui.setTextureRect(sf::IntRect(0*32,0,32,32));
			for(int i=0;i<player.getHearts();i++)
			{
				gui.setPosition(85+i*35,0);
				Window.draw(gui);
			}


			Window.draw(coiny);

			coiny.setPosition(0,7);
			coiny.setString("Lives: "+ToString(player.getLife()));
			Window.draw(coiny);

			Window.draw(keye);

			time_left=mapa.time_map-przeszly_czas+zebrane_mikstury;

			if(time_left>0 && time_left<11 && !play_timer)
			{

				play_timer=true;
			}


			if(play_timer && !actual_playing)
			{
				timer.play();
				play_timer=false;
				actual_playing=true;

			}
			if(time_left>10)
			{
				timer.stop();
				actual_playing=false;
			}



			if(time_left<0)
			{
				Lose::left_life=player.getLife();
				player.addLife(-1);

				restart(false);
				losed=true;
				return 2;
			}	

			Timer.setString(" : "+ToString(time_left));
			Window.draw(Timer);
		}
		

		//if(hud)_hud.pokazHUD(zegarfps, Window,player.getX(),player.getY(),G_PLAYER_X,G_PLAYER_Y,0,0,0);

		if(showDialogBox)
		{
			Window.setView(Dialog);
			Window.draw(dialogBG);
			Window.draw(DialogText);
		}
		
		

		Window.display();
	}

	//Never reaching this point normally, but just in case, exit the Windowlication
	return -1;
}