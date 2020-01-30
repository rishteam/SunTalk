#include <bits/stdc++.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

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

	sf::Font font;
	if (!font.loadFromFile("assets/font/arial.ttf"))
		return EXIT_FAILURE;
	sf::Text text(GAME_NAME, font, 150);
	text.setPosition(240,160);

	sf::Text S("start", font, 50);
	Button StartButton(580,350,120,50,S);

	sf::Text H("Home", font, 50);
	Button HomeButton(30,30,150,50,H); 

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
		switch (GameMode){
			case 0:
				window.draw(text);
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
