#pragma once
#include "screen.h"
#include "game.h"
class Loading : public cScreen
{
private:
	sf::Clock clock;
	short level;
	sf::Text pass;
	sf::Text load;
	std::string lvl;
	bool first;
public:
	Loading(void);
	
	virtual int Run (sf::RenderWindow &App);
};

