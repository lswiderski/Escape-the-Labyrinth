#include "logo.h"
#include "resources.h"

Logo::Logo (void)
{
	alpha_max = 3*255;
	alpha_div = 3;
	playing = false;
}

int Logo::Run (sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;
	sf::Texture Image;
	sf::Sprite Sprite;
	int alpha = 0;
	int alphab = 0;
	sf::Font Font;
	sf::Text autor;
	sf::Clock clock;
	sf::Texture Image2;
	sf::Sprite glhf;

	if (!Image.loadFromFile("Data/images/logo_gear.png"))
	{
		std::cerr<<"Error loading logo_gear.png"<<std::endl;
		return (-1);
	}
	Sprite.setTexture(Image);
	Sprite.setColor(sf::Color(255, 255, 255, alpha));
	Sprite.setOrigin(Image.getSize().x/2, Image.getSize().y/2);
	Sprite.setPosition(400,200);

	if (!Image2.loadFromFile("Data/images/passion.png"))
	{
		std::cerr<<"Error loading passion.png"<<std::endl;
		return (-1);
	}
	glhf.setTexture(Image2);
	glhf.setColor(sf::Color(255, 255, 255, alphab));
	glhf.setOrigin(Image2.getSize().x/2, Image2.getSize().y/2);
	glhf.setPosition(400,330);
	
	autor.setFont(resources::Font);
	autor.setCharacterSize(16);
	autor.setString("created by Lukasz Swiderski");
	autor.setPosition(550,580);
	autor.setColor(sf::Color::Black);

	sf::View CameraPosition;
	CameraPosition=App.getDefaultView();


	while (Running)
	{
		if(clock.getElapsedTime().asSeconds()>3)
			return 0;
		//Verifying events
		while (App.pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
			//Key pressed
			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{

				case sf::Keyboard::Escape:
					return(0);
					break;
				default :
					break;
				}
			}
		}
		//When getting at alpha_max, we stop modifying the sprite
		if (alpha<alpha_max)
		{
			alpha=alpha+5;
			if(alpha>alpha_max) alpha=alpha_max;
			clock.restart();
		}
		if(alpha_max==alpha && alphab<alpha_max)
		{
			alphab=alphab+5;
			if(alphab>alpha_max) alphab=alpha_max;
			clock.restart();
		}

		Sprite.setColor(sf::Color(255, 255, 255, alpha/alpha_div));
		glhf.setColor(sf::Color(255, 255, 255, alphab/alpha_div));


		//Drawing
		App.clear(sf::Color::White);
		App.draw(Sprite);
		App.draw(glhf);
		App.draw(autor);
		App.display();

	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}