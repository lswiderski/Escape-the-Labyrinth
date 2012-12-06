#pragma once
#include "screen.h"
class Start : public cScreen
{
public:
	 sf::Sprite title;
	Start(void);
	virtual int Run (sf::RenderWindow &App);
};

