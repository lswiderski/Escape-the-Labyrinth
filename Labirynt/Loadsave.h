#pragma once
#include "screen.h"
#include "resources.h"
class Loadsave : public cScreen
{
	sf::Text load_t,save_t;
public:
	Loadsave(void);
	virtual int Run (sf::RenderWindow &App);
};

