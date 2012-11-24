#pragma once

#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation();
	~Animation();

	void Initialize(float x, float y, int FrameX, int FrameY);
	void isOpen();
	void Update(sf::RenderWindow &Window);
	void Draw(sf::RenderWindow &Window);

	bool getActive();
	void setActive(bool active);

	int getCurrentFrame(int axis);
	void setCurrentFrame(int axis, int value);

	float getPosition(int axis);
	void setPosition(int axis, int value);

	void setImage(sf::Texture &tempImage);

protected:
	int getFrameWidth();
	int getFrameHeight();
private:
	sf::Texture spriteTexture;
	sf::Sprite spriteImage;
	sf::Clock Clock;
	int currentFrameX, currentFrameY;
	float frameCounter, switchFrame;
	float frameTime;
	int amountOfFramesX, amountOfFramesY;
	float x, y;
	bool active;
};