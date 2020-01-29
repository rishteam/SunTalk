#include <bits/stdc++.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <button.h>
#include <role.h>
#include <pillar.h>
#include <game.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define GAME_NAME "Just a Game"

int GameMode = 0;

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);

	sf::Font font;
	if (!font.loadFromFile("assets/font/arial.ttf"))
		return EXIT_FAILURE;
	sf::Text text(GAME_NAME, font, 150);
	text.setPosition(240,160);

	sf::Text S("start", font, 50);
	Button StartButton(580,335,120,50,S);

	sf::Text H("Home", font, 50);
	Button HomeButton(30,30,150,50,H); 

	Game Gametest(WINDOW_WIDTH, WINDOW_HEIGHT, 0.05);

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
					if( GameMode == 0 ){
						if( StartButton.mouseIn(event.mouseButton.x, event.mouseButton.y) ){
							// Bird.init(1000, 360,0.05);
							GameMode = 1;
						}
					}
					else if( GameMode == 1 ){
						if( HomeButton.mouseIn(event.mouseButton.x, event.mouseButton.y) )
							GameMode = 0;
					}
					break;
				default:
					break;
			}

		}

		window.clear();
		if( GameMode == 0 ){
			window.draw(text);
			StartButton.update(window);
			StartButton.draw(window);
		}
		if( GameMode == 1 ){

			Gametest.update(window);
			Gametest.draw(window);

			HomeButton.update(window);
			HomeButton.draw(window);

		}
		window.display();

	}

	return EXIT_SUCCESS;

}
