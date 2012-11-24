#pragma once
#include "screen.h"
#include "resources.h"
class Credits : public cScreen
{
private:
	sf::Text txt;

public:
	Credits(void);

	virtual int Run (sf::RenderWindow &App);
};

