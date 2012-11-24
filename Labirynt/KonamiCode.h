#pragma once
#include "screen.h"
#include "game.h"
class KonamiCode : public cScreen
{
public:
	static bool konami;
	static int lvl;
	KonamiCode(void);
	virtual int Run (sf::RenderWindow &App);
};

