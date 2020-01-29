#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Role{

public:

	Role(float x, float y);
	void reset(float x, float y);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	bool alive();

private:

	float m_x, m_y, m_speed;
	enum class Status{
		FLY,
		STOP,
		DOWN
	}m_status;

	sf::Sprite m_role;
	sf::Texture m_fly_1;
	sf::Texture m_fly_2;
	sf::Texture m_stop_1;
	sf::Texture m_stop_2;
	sf::Texture m_down;

	int m_cnt,m_anim;

};