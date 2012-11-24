#include "screen.h"
class Lose : public cScreen
{
private:

public:
	static int left_life;
	Lose (void);
	virtual int Run (sf::RenderWindow &App);
};



