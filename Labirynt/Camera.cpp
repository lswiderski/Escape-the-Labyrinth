#include "Camera.h"
#include <iostream>
Camera::Camera()
{
	//ctor
}

Camera::~Camera()
{
	//dtor
}

void Camera::Initialize()
{
	cameraX = cameraY = 0;
	CameraPosition.setSize(ScreenWidth,ScreenHeight);
	CameraPosition.setCenter(ScreenWidth/2,ScreenHeight/2);
}

void Camera::Update(int x, int y)
{

	CameraPosition.setCenter(x,y);
}

void Camera::Draw(sf::RenderWindow &Window)
{
	Window.setView(CameraPosition);
}

void Camera::SetView(sf::View Camera)
{
	this->CameraPosition = Camera;
}

sf::View Camera::getView()
{
	return CameraPosition;
}
