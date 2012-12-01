#include "Loadsave.h"
#include "menu.h"
#include <algorithm>
Loadsave::Loadsave(void)
{
	std::string id_map="0000000000000000";
		bool dmaps[10];
		for (int j=0;j<3;j++)
		{
			slots[j].player_pkt=0;
			slots[j].player_lives=0;
			slots[j].player_map=0;
			for(int i=0;i<16;i++)
				slots[j].mapset_id[i]=id_map[i];
			for(int i=0;i<100;i++)
				slots[j].done_maps[i]=false;
		}
			
			 

}

bool Loadsave::load(int memorycard)
{
	int tmp;
	char idtmp[16];
	bool donetmp[100];
	
	
		if(memorycard>-1){
			
		Game::LPkt=slots[memorycard].player_pkt;
			
					Game::LLives=slots[memorycard].player_lives;
					Game::LMap=slots[memorycard].player_map;
					Game::LId_map="";
					for(int i=0;i<16;i++)
						Game::LId_map+=slots[memorycard].mapset_id[i];
					for(int i=0;i<100;i++)
						Game::LDone_map[i]=slots[memorycard].done_maps[i];
		}
		
		
	Game::loaded=true;
	Menu::playing=true;
	return true;	

}
bool Loadsave::save(int memorycard)
{

slots[memorycard].player_pkt=Game::LPkt;
	slots[memorycard].player_lives=Game::LLives;
	slots[memorycard].player_map=Game::LMap;
	for(int i=0;i<16;i++)
		slots[memorycard].mapset_id[i]=Game::id_map[i];
	for(int i=0;i<100;i++)
		slots[memorycard].done_maps[i]=Game::LDone_map[i];
	
fp = fopen("memorycard.dat","w+b");
if(fp!=NULL)
{
	fwrite(&slots,sizeof(Slot),3,fp);
	fclose(fp);
	
	return true;

}
else
{
	return false;
}
	
}
int Loadsave::Run (sf::RenderWindow &App)
{

	sf::Event Event;
	bool Running = true;
	menu=0;

	m1.setFont(resources::Font);
	m1.setCharacterSize(20);
	m1.setString("-Slot 1-");
	m1.setPosition(200,200);

	m2.setFont(resources::Font);
	m2.setCharacterSize(20);
	m2.setString("-Slot 2-");
	m2.setPosition(200,240);

	m3.setFont(resources::Font);
	m3.setCharacterSize(20);
	m3.setString("-Slot 3-");
	m3.setPosition(200,280);

	error_load.setFont(resources::Font);
	error_load.setCharacterSize(20);
	error_load.setColor(sf::Color::Black);
	error_load.setString("Error");
	error_load.setPosition(600,300);

	load_t.setFont(resources::Font);
	load_t.setCharacterSize(20);
	load_t.setColor(sf::Color::White);
	load_t.setString("Load");
	load_t.setPosition(200,400);

	save_t.setFont(resources::Font);
	save_t.setCharacterSize(20);
	save_t.setColor(sf::Color::White);
	save_t.setString("Save");
	save_t.setPosition(300,400);
	load_flag=false;
	memory_slot=0;

	sf::View CameraPosition;
	CameraPosition=App.getDefaultView();

	fp = fopen("memorycard.dat","r+b");
	if(fp!=NULL)
	{
		fread(slots,sizeof(Slot),3,fp);
	}
	fclose(fp);
	for (int i=0;i<3;i++)
	{
		using namespace std;
		cout<<slots[i].player_pkt<<" "<<slots[i].player_lives<<" "<<slots[i].player_map<<endl;
		for (int j=0;j<16;j++)
		{
			cout<<slots[i].mapset_id[j];
		}
		cout<<endl;
		for(int j=0;j<100;j++)
		{
			if(slots[i].done_maps[j]==true)
				cout<<1;
			else
			{
				cout<<0;

			}

		}
		cout<<endl;
	}
	pokaz=false;

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
				case sf::Keyboard::P:
					pokaz=true;
					break;
				case sf::Keyboard::Left:
					menu--;
					if(menu<0)menu=0;
					break;
				case sf::Keyboard::Right:
					menu++;
					if(menu>1)menu=1;
					break;
				case sf::Keyboard::Up:
					memory_slot--;
					if(memory_slot<0)memory_slot=0;
					break;
				case sf::Keyboard::Down:
					memory_slot++;
					if(memory_slot>2)memory_slot=2;
					break;
				case sf::Keyboard::Return:
					if(menu)
					{
						//1 save
						std::cout<<"save"<<std::endl;
						save(memory_slot);
						std::cout<<"saved"<<std::endl;
					}
					else 
					{
						//2 load
						std::cout<<"load"<<std::endl;
						if(!load(memory_slot))
						{
							load_flag=true;
							std::cout<<"error"<<std::endl;
						}
						std::cout<<"loaded"<<std::endl;
					}
					break;
				default :
					break;
				}
			}
		}
		//When getting at alpha_max, we stop modifying the sprite



		//Drawing

		App.setView(CameraPosition);

		if (pokaz)
		{
			pokaz = false;
			for (int i=0;i<3;i++)
			{
				for(int j=0;j<16;j++)
				{
					std::cout<<slots[i].mapset_id[j];
				}
				std::cout<<std::endl;
				std::cout<<slots[i].player_map<<" "<<slots[i].player_pkt<<" "<<slots[i].player_lives<<std::endl;
			
			for(int j=0;j<100;j++)
			{
				if(slots[i].done_maps[j]==true)
					std::cout<<1;
				else
				{
					std::cout<<0;

				}
				
			}
			std::cout<<std::endl;
			}
		}
		if(memory_slot==0)
		{
			m1.setColor(sf::Color(255, 0, 0, 255));
			m2.setColor(sf::Color(0, 0, 0, 255));
			m3.setColor(sf::Color(0, 0, 0, 255));
		}
		else if(memory_slot==1)
		{
			m1.setColor(sf::Color(0, 0, 0, 255));
			m2.setColor(sf::Color(255, 0, 0, 255));
			m3.setColor(sf::Color(0, 0, 0, 255));
		}
		else if(memory_slot==2)
		{
			m1.setColor(sf::Color(0, 0, 0, 255));
			m2.setColor(sf::Color(0, 0, 0, 255));
			m3.setColor(sf::Color(255, 0, 0, 255));
		}
		if(menu)
		{
			load_t.setColor(sf::Color(0, 0, 0, 255));
			save_t.setColor(sf::Color(255, 0, 0, 255));
		}
		else
		{
			save_t.setColor(sf::Color(0, 0, 0, 255));
			load_t.setColor(sf::Color(255, 0, 0, 255));
		}
		
		App.draw(m1);
		App.draw(m2);
		App.draw(m3);
		App.draw(load_t);
		App.draw(save_t);

		if(load_flag)
			App.draw(error_load);
			

		App.display();
		App.clear(sf::Color::White);
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}
