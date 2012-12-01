#pragma once
#include "screen.h"
#include "resources.h"
#include "Player.h"
#include "game.h"
class Loadsave : public cScreen
{
	sf::Text load_t,save_t,m1,m2,m3,error_load;
	int menu;
	bool load(int memorycard);
	bool save(int memorycard);
	int memory_slot;
	FILE *fp;
	bool pokaz;
	bool load_flag;
public:
	Loadsave(void);
	struct Slot
	{
		char mapset_id[16];
		int player_map;
		int player_pkt;
		int player_lives;
		bool done_maps[100];
	};
	Slot slots[3];
	
	virtual int Run (sf::RenderWindow &App);
};

