#include "resources.h"


resources::resources(void)
{
	Font.loadFromFile("Data/fonts/verdanab.ttf");
	Tiles.loadFromFile("Data/sprites/tile.png");
	Player.loadFromFile("Data/sprites/Player.png");
	GUI.loadFromFile("Data/sprites/GUI.png");

	s_key.loadFromFile("Data/music/klucz.wav");
	s_lancuch.loadFromFile("Data/music/lancuch.wav");
	s_menuButton.loadFromFile("Data/music/menubutton.wav");
	s_tp.loadFromFile("Data/music/portal.wav");
	s_potion.loadFromFile("Data/music/potion.wav");
	s_lose.loadFromFile("Data/music/przegrana.wav");
	s_win.loadFromFile("Data/music/wygrana.wav");
	s_timer.loadFromFile("Data/music/timer.wav");
	s_lava.loadFromFile("Data/music/lava.wav");
	s_box.loadFromFile("Data/music/skrzynia.wav");

	bgm.openFromFile("Data/music/plansza.wav");
	menu_music.openFromFile("Data/music/menu1.wav");
}


resources::~resources(void)
{
}
sf::Font resources::Font;
sf::Texture resources::Tiles;
sf::Texture resources::Player;
sf::Texture resources::GUI;

 sf::SoundBuffer resources::s_key;
sf::SoundBuffer resources::s_lancuch;
 sf::SoundBuffer resources::s_menuButton;
sf::SoundBuffer resources::s_tp;
 sf::SoundBuffer resources::s_potion;
 sf::SoundBuffer resources::s_lose;
 sf::SoundBuffer resources::s_win;
sf::SoundBuffer resources::s_timer;
sf::SoundBuffer resources::s_box;
sf::SoundBuffer resources::s_lava;


 sf::Music resources::bgm;
 sf::Music resources::menu_music;