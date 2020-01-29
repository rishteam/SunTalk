#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Pillar{

public:
	Pillar(float x, float y, float w, float h, float s);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	bool hitby(float x, float y);

private:
	float m_x, m_y, m_w, m_h;
	float m_speed;
	sf::RectangleShape m_rect;

};