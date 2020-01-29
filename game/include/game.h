#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

#include <button.h>
#include <role.h>
#include <pillar.h>

class Game{

public:

	Game(int w, int h, float s);
	void addPillar();
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

private:
	
	int m_ww, m_wh;
	float m_speed,m_cnt;
	bool m_isAdd = true;
	int m_score;

	sf::Font m_font;
	sf::Text m_scoreText;

	Role m_Bird;
	std::vector <Pillar> m_PillarTable;

};
