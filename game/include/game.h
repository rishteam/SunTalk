#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <random>

#include <background.h>
#include <button.h>
#include <role.h>
#include <pillar.h>

class Game{

public:

	Game(int w, int h, float s);
	void restart(int w, int h, float s);
	
	void countdown(sf::RenderWindow &window);
	void addPillar();
	void run(sf::RenderWindow &window);

	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

private: 
	
	int m_ww, m_wh,m_score;
	float m_speed,m_cnt;
	bool m_isAdd = true;

	enum class Process{
		COUNT,
		PLAY,
		LOSE
	}m_process;

	Role m_Bird;
	std::vector <Pillar> m_PillarTable;

	// sf::Sprite m_countNum;
	// sf::Texture m_Numone;
	// sf::Texture m_Numtwo;
	// sf::Texture m_NumThree;

	sf::Font m_font;
	sf::Text m_scoreText;

};
