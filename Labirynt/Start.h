#pragma once
#include "screen.h"
class Start : public cScreen
{
public:
	Start(void);
	virtual int Run (sf::RenderWindow &App);
};

