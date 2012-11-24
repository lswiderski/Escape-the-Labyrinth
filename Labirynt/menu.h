#include <iostream>
#include "screen.h"
#include "Global.h"
#include "game.h"
#include <fstream>
class Menu : public cScreen
{
private:
	std::ifstream *load_file;
	std::ofstream *save_file;
	int alpha_max;
	int alpha_div;

	 int tmp[2];
	 int tmp2[2];
	 FILE *fp;
	 sf::Text Menu1;
	 sf::Text Menu2;
	 sf::Text Menu3;
	 sf::Text Menu4;
	 sf::Text Menu5;
	 sf::Text Menu6;
	 sf::Text Menu7;
	 std::string Konami;
	 sf::Text stan;

	 sf::Text nazwa;
	 sf::Text ver;
	 bool saved;
public:
	static bool playing;
	Menu (void);
	virtual int Run (sf::RenderWindow &App);
};

