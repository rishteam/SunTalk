#include <bits/stdc++.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <background.h>
#include <button.h>
#include <role.h>
#include <pillar.h>
#include <game.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define GAME_SPEED 5
#define GAME_NAME "Just Fly"

int GameMode = 0;

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
	window.setFramerateLimit(60);

	Background Bg(5,2);

	sf::Texture TitleTexture;
	TitleTexture.loadFromFile("assets/pic/title.png");
	sf::Sprite TitleSprite;
	TitleSprite.setTexture(TitleTexture);
	TitleSprite.setPosition(340,200);

	sf::Texture Stexture1;
	Stexture1.loadFromFile("assets/pic/button/start_1.png");
	sf::Texture Stexture2;
	Stexture2.loadFromFile("assets/pic/button/start_2.png");
	Button StartButton(580,400,120,50,Stexture1,Stexture2);

	sf::Texture Htexture1;
	Htexture1.loadFromFile("assets/pic/button/home_1.png");
	sf::Texture Htexture2;
	Htexture2.loadFromFile("assets/pic/button/home_2.png");
	Button HomeButton(30,30,120,50,Htexture1,Htexture2); 

	Game Gametest(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_SPEED);

	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{

			switch (event.type){
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::EventType::KeyPressed:
					break;
				case sf::Event::EventType::KeyReleased:
					break;
				case sf::Event::MouseButtonPressed:
					break;
				default:
					break;
			}

		}

		switch (GameMode){
			case 0:
				if( StartButton.isClick(window) ){
					Gametest.restart(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_SPEED);
					GameMode = 1;
				}
				break;
			case 1:
				if( HomeButton.isClick(window) ){
					GameMode = 0;
				}
				break;
			default:
				break;
		}


		window.clear();
		Bg.update(window);
		Bg.draw(window);
		switch (GameMode){
			case 0:
				window.draw(TitleSprite);
				StartButton.update(window);
				StartButton.draw(window);
				break;
			case 1:
				Gametest.update(window);
				Gametest.draw(window);
				HomeButton.update(window);
				HomeButton.draw(window);
				break;
			default:
				break;

		}
		window.display();

	}

	return EXIT_SUCCESS;

}
