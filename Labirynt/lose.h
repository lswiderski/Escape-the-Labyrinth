#include "screen.h"
class Lose : public cScreen
{
private:

public:
	 sf::Sprite title;
	static int left_life;
	Lose (void);
	virtual int Run (sf::RenderWindow &App);
};



