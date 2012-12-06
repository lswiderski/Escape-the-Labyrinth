#pragma once
#include "screen.h"
class Winner : public cScreen
{
public:
	 sf::Sprite title;
	Winner(void);

	virtual int Run (sf::RenderWindow &App);
};

