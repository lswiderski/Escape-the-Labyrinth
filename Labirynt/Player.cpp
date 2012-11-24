#include "Player.h"

Player::Player()
{

}


Player::~Player()
{

}
int Player::getLife()
{
	return life;
}
void Player::setLife(int amount)
{
	life=amount;
}
void Player::addLife(int amount)
{
	life+=amount;
}


void Player::teleport(int _x, int _y)
{
	x=_x;
	y=_y;
}

void Player::Initialize(int & _x, int & _y)
{
	hearts=3;
	lvl=0;
	keys=0;
	pkt=0;
	life=3;
	total_pkt=0;
	x=_x;
	y=_y;
	moveSpeed = 200;
	currentFrameX = currentFrameY = 0;
	playerAnimation.Initialize(x, y, 4, 4);
	camera.Initialize();

}

void Player::LoadContent()
{
	//if(playerTexture.loadFromFile("Data/Player.png"))
		playerAnimation.setImage(resources::Player);
}

void Player::Update(sf::RenderWindow &Window,std::vector<std::vector<std::vector<int>>> &Map)
{
	playerAnimation.setActive(true);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if(Map[(int)y/64][(int)((x+16+moveSpeed * Clock.getElapsedTime().asSeconds())/64)][0]%2!=1 && Map[(int)y/64][(int)((x+16+moveSpeed * Clock.getElapsedTime().asSeconds())/64)][2]%2!=1)
		x += moveSpeed * Clock.getElapsedTime().asSeconds();
		currentFrameY = 2;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if(Map[(int)y/64][(int)((x-16-moveSpeed * Clock.getElapsedTime().asSeconds())/64)][0]%2!=1 && Map[(int)y/64][(int)((x-16-moveSpeed * Clock.getElapsedTime().asSeconds())/64)][2]%2!=1)
		x -= moveSpeed * Clock.getElapsedTime().asSeconds();
		currentFrameY = 1;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if((Map[(int)(y-8-moveSpeed * Clock.getElapsedTime().asSeconds())/64][(int)((x-16)/64)][0]%2!=1 && Map[(int)(y-8-moveSpeed * Clock.getElapsedTime().asSeconds())/64][(int)((x+16)/64)][0]%2!=1) && (Map[(int)(y-8-moveSpeed * Clock.getElapsedTime().asSeconds())/64][(int)((x-16)/64)][2]%2!=1 && Map[(int)(y-8-moveSpeed * Clock.getElapsedTime().asSeconds())/64][(int)((x+16)/64)][2]%2!=1))
		y -= moveSpeed * Clock.getElapsedTime().asSeconds();
		currentFrameY = 3;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if((Map[(int)(y+moveSpeed * Clock.getElapsedTime().asSeconds())/64][(int)((x-16)/64)][0]%2!=1 && Map[(int)(y+moveSpeed * Clock.getElapsedTime().asSeconds())/64][(int)((x+16)/64)][0]%2!=1) && (Map[(int)(y+moveSpeed * Clock.getElapsedTime().asSeconds())/64][(int)((x-16)/64)][2]%2!=1 && Map[(int)(y+moveSpeed * Clock.getElapsedTime().asSeconds())/64][(int)((x+16)/64)][2]%2!=1))
		y += moveSpeed * Clock.getElapsedTime().asSeconds();
		currentFrameY = 0;
	}
	else
		playerAnimation.setActive(false);

	Clock.restart();
	playerAnimation.setPosition(1, x);
	playerAnimation.setPosition(2, y);
	playerAnimation.setCurrentFrame(2, currentFrameY);
	playerAnimation.Update(Window);
	camera.Update(x, y);
}

void Player::Draw(sf::RenderWindow &Window)
{
	camera.Draw(Window);
	playerAnimation.Draw(Window);

}

float Player::getX()
{
	return x;
}

float Player::getY()
{
	return y;
}
int Player::getKeys()
{
	return keys;
}
	void Player::setKeys(int amount)
	{
		keys=amount;
	}
	void Player::addKeys(int amount)
	{
		keys+=amount;
	}
	int Player::getPkt()
	{
		return pkt;
	}
	void Player::setPkt(int amount)
	{
		pkt=amount;
	}
	void Player::addPkt(int amount)
	{
		pkt+=amount;
	}
	int Player::getLvl()
	{
		return lvl;
	}
	void Player::setLvl(int _lvl)
	{
		lvl=_lvl;
	}
	int Player::getTotalPkt()
	{
		return total_pkt;
	}
	void Player::setTotalPkt(int amount)
	{
		total_pkt=amount;
	}

	void Player::setHearts(int amount)
	{
		hearts=amount;
	}
	int Player::getHearts()
	{
		return hearts;
	}
	void Player::addHearts(int amount)
	{
		hearts+=amount;
	}