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
	void init(int w, int h, float s);
	
	void ready(sf::RenderWindow &window);
	void addPillar();
	void run(sf::RenderWindow &window);
	void restart(sf::RenderWindow &window);

	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

private: 
	
	int m_ww, m_wh,m_score;
	float m_speed,m_cnt;
	bool m_isAdd = true;

	enum class Process{
		READY,
		PLAY,
		LOSE
	}m_process;

	Role m_Bird;
	std::vector <Pillar> m_PillarTable;

	sf::Sprite m_Sprite;
	sf::Texture m_readyTexture;
	sf::Texture m_resetTexture;

	sf::Font m_font;
	sf::Text m_scoreText;

};
