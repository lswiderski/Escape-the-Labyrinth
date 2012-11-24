#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
class resources
{
public:
	resources(void);
	~resources(void);
	static sf::Font Font;
	static sf::Texture Tiles;
	static sf::Texture Player;
	static sf::Texture GUI;
	static sf::SoundBuffer s_key;
	static sf::SoundBuffer s_lancuch;
	static sf::SoundBuffer s_menuButton;
	static sf::SoundBuffer s_tp;
	static sf::SoundBuffer s_potion;
	static sf::SoundBuffer s_lose;
	static sf::SoundBuffer s_win;
	static sf::SoundBuffer s_timer;
	static sf::SoundBuffer s_lava;
	static sf::SoundBuffer s_box;

	static sf::Music bgm;
	static sf::Music menu_music;
};

