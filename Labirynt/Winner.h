#pragma once
#include "screen.h"
class Winner : public cScreen
{
public:
	Winner(void);

	virtual int Run (sf::RenderWindow &App);
};

