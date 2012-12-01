#pragma once
#include <iostream>
#include "screen.h"
#include "techhud.h"
#include "Player.h"
#include "Map.h"
#include "resources.h"
#include <sstream>
#include <SFML/Audio.hpp>
#include <vector>
#include "KonamiCode.h"
#define BLOCKSIZE 64

class Game : public cScreen
{
private:
	
	static bool same;
	
	static short map;
	sf::Text keye, coiny;
	Map mapa;

	Player player;
	Camera camera;
	bool lose;
	bool hud;
	TechHUD _hud;
	int pos2;
	sf::Event Event;
	bool Running;
	sf::Clock zegarfps;
	sf::Clock predkosc;
	sf::Clock Czas_Gry;
	sf::Texture tloImage;
	sf::Sprite  tlo;
	sf::Sprite gui;
	sf::Texture tile;

	int hearts_tmp;
	int zebrane_mikstury;
	int przeszly_czas;

	sf::SoundBuffer buffer;
	sf::Sound sound;

	bool winner;
	bool win;
	bool showDialogBox;
	bool showTlo;
	int actual_dialog;
	int actual_fragment;

	int time_left;
	bool done_maps[100];
	sf::Text DialogText;
	sf::Text Timer;
	sf::View HUD;
	sf::View Dialog;
	sf::Sprite dialogBG;
	sf::RectangleShape dialogBox;
	sf::RectangleShape object;

	int G_PLAYER_X;
	int G_PLAYER_Y;



public:
	template <class T> std::string static ToString(const T& t) 
	{ 
		std::ostringstream oss; 
		oss << t; 
		return oss.str();
	}
	static std::vector<std::string> Maps;
	std::string nextLvl;
	static bool reset;
	static bool losed;
	static bool loaded;
	static bool wrongpath;
	static int PLAYER_X;
	static int PLAYER_Y;
	Game (void);
	virtual int Run (sf::RenderWindow &Window);

	void restart(bool next);
	void Reset();
	
	short static getLevel();
	bool static getSame();
	void static setLevel(short level);
	void static setPos(int x, int y);
	int static LPkt;
	int static LMap;
	int static LLives;
	bool static LDone_map[100];
	std::string static LId_map;
	std::string static id_map;

};

