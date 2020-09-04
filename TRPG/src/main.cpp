#include <bits/stdc++.h>

#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define GAME_SPEED 5
#define GAME_NAME "TRPG"

#include <role.h>
#include <map.h>
#include <gameloop.h>

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
	window.setFramerateLimit(60);

	window.setVerticalSyncEnabled(true);
	ImGui::SFML::Init(window);
	sf::Clock deltaClock;

	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event)){

			ImGui::SFML::ProcessEvent(event);
			
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

		ImGui::SFML::Update(window, deltaClock.restart());

		Yukino.update();

		if( Yukino.getX() - viewX > 1000 ){
			viewX = Yukino.getX() - 1000;
		}
		else if ( Yukino.getX() - viewX < 80 ){
			viewX = Yukino.getX() - 80;
		}

		gameloop(window, M, Yukino);

		view.reset(sf::FloatRect(viewX, viewY, WINDOW_WIDTH, WINDOW_HEIGHT));
		window.setView(view);

		window.clear();
		M.draw(window);
		Yukino.draw(window);
		ImGui::SFML::Render(window);
		window.display();

	}

	return EXIT_SUCCESS;

}
