#include <iostream>
#include "screen.h"
#include "Global.h"
class Logo : public cScreen
{
private:
	int alpha_max;
	int alpha_div;
	bool playing;
public:
	Logo (void);
	virtual int Run (sf::RenderWindow &App);
};

