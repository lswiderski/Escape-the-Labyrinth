#include "Animation.h"
#include <iostream>
Animation::Animation()
{

}


Animation::~Animation()
{

}

int Animation::getFrameWidth()
{
	return spriteTexture.getSize().x / amountOfFramesX;
}

int Animation::getFrameHeight()
{
	return spriteTexture.getSize().y / amountOfFramesY;
}

bool Animation::getActive()
{
	return active;
}

void Animation::setActive(bool value)
{
	active = value;
}

int Animation::getCurrentFrame(int axis)
{
	if(axis == 1)
		return currentFrameX;
	else
		return currentFrameY;
}

void Animation::setCurrentFrame(int axis, int value)
{
	if(axis == 1)
		currentFrameX = value;
	else
		currentFrameY = value;

}

float Animation::getPosition(int axis)
{
	if(axis == 1)
		return x;
	else
		return y;
}

void Animation::setPosition(int axis, int value)
{
	if(axis == 1)
		x = value;
	else
		y = value;
}

void Animation::setImage(sf::Texture &tempImage)
{
	spriteImage.setTexture(tempImage);
	spriteTexture=tempImage;
	spriteImage.setOrigin(getFrameWidth()/2, getFrameHeight());
}


void Animation::Initialize(float x, float y, int FrameX, int FrameY)
{
	frameCounter = 0;
	switchFrame = 1;
	this->x = x;
	this->y = y;
	this->amountOfFramesX = FrameX;
	this->amountOfFramesY = FrameY;
	this->spriteImage.setTexture(spriteTexture);
	this->currentFrameX=0;
	this->currentFrameY=0;
	active = false;


}



void Animation::Update(sf::RenderWindow &Window)
{
	frameTime = Clock.getElapsedTime().asSeconds();

	if(active)
		frameCounter += frameTime;
	else
	{frameCounter = 0;
	currentFrameX=0;}


	if(frameCounter >= switchFrame)
	{
		Clock.restart();
		frameCounter = 0;
		currentFrameX += getFrameWidth();
		if(currentFrameX >= spriteTexture.getSize().x)
			currentFrameX = 0;
	}

	spriteImage.setTextureRect(sf::IntRect(currentFrameX, currentFrameY * getFrameHeight(), getFrameWidth(),  getFrameHeight()));

	spriteImage.setPosition(x, y);

}

void Animation::Draw(sf::RenderWindow &Window)
{
	Window.draw(spriteImage);

}