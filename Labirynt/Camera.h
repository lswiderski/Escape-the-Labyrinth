#pragma once
#include"Global.h"
#include<SFML/Graphics.hpp>

class Camera
{
public:
	Camera();
	~Camera();

	void Initialize();
	void Update(int playerX, int playerY);
	void Draw(sf::RenderWindow &Window);

	void SetView(sf::View CameraPosition);
	sf::View getView();
protected:
	sf::View CameraPosition;
	float cameraX, cameraY;
private:
};
