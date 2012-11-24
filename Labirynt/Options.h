#pragma once
#include "screen.h"
#include "game.h"
class Options : public cScreen
{
private:

	sf::Text txt;

public:
	static int Music_Volume;
	static int Sound_Volume;
	Options(void);
virtual int Run (sf::RenderWindow &App);
};

