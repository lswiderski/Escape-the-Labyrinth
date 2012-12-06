#include "resources.h"


resources::resources(void)
{
	Font.loadFromFile("Data/fonts/verdanab.ttf");
	Tiles.loadFromFile("Data/sprites/tile.png");
	Player.loadFromFile("Data/sprites/Player.png");
	GUI.loadFromFile("Data/sprites/GUI.png");
	dialogbox.loadFromFile("Data/images/dialogbox.png");

	Neufrin_logo.loadFromFile("Data/images/logo_gear.png");
	passion.loadFromFile("Data/images/passion.png");
	Game_title.loadFromFile("Data/images/title.png");

	s_key.loadFromFile("Data/music/klucz.ogg");
	s_lancuch.loadFromFile("Data/music/lancuch.ogg");
	s_menuButton.loadFromFile("Data/music/menubutton.ogg");
	s_tp.loadFromFile("Data/music/portal.ogg");
	s_potion.loadFromFile("Data/music/potion.ogg");
	s_lose.loadFromFile("Data/music/przegrana.ogg");
	s_win.loadFromFile("Data/music/wygrana.ogg");
	s_timer.loadFromFile("Data/music/timer.ogg");
	s_lava.loadFromFile("Data/music/lava.ogg");
	s_box.loadFromFile("Data/music/skrzynia.ogg");

	bgm.openFromFile("Data/music/plansza.ogg");
	menu_music.openFromFile("Data/music/menu1.ogg");
}


resources::~resources(void)
{
}
sf::Font resources::Font;
sf::Texture resources::Tiles;
sf::Texture resources::Player;
sf::Texture resources::GUI;
sf::Texture resources::dialogbox;

sf::Texture resources::Neufrin_logo;
sf::Texture resources::passion;
sf::Texture resources::Game_title;

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