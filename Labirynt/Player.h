#pragma once

#include <SFML/Graphics.hpp>
#include"Animation.h"
#include"Camera.h"
#include "resources.h"
#define _MAX_X 4096
#define _MAX_Y 1408
class Player
{
public:
	Player();
	~Player();

	void Initialize(int &x, int &y);
	void LoadContent();
	void Update(sf::RenderWindow &Window,std::vector<std::vector<std::vector<int>>> &Map);//int Map[20][20]);
	void Draw(sf::RenderWindow &Window);
	float getX();
	float getY();
	void teleport(int x, int y);
	int getKeys();
	void setKeys(int amount);
	void addKeys(int amount);
	int getPkt();
	void setPkt(int amount);
	void addPkt(int amount);
	int getLvl();
	void setLvl(int _lvl);
	int getTotalPkt();
	void setTotalPkt(int amount);
	int getLife();
	void setLife(int amount);
	void addLife(int amount);
	int getHearts();
	void setHearts(int amount);
	void addHearts(int amount);
	
protected:
	Animation playerAnimation;
	Camera camera;
private:
	int pkt,keys,lvl,total_pkt,life,hearts;
	float x, y;
	int currentFrameX, currentFrameY;
	float moveSpeed;
	sf::Clock Clock;
	sf::Event Event;
};