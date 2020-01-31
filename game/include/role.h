#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Role{

public:
	Role() = default;
	Role(float x, float y, float s);
	void init(float x, float y, float s);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	bool alive();

	float getX() const { return m_x; }
	float getY() const { return m_y; }

private:

	float m_x, m_y, m_speed;
	enum class Status{
		FLY,
		DOWN
	}m_status;

	sf::Sprite m_role;
	sf::Texture m_fly_1;
	sf::Texture m_fly_2;
	sf::Texture m_down;

	int m_cnt,m_anim;

};