#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Pillar{

public:
	Pillar() = default;
	Pillar(float x, float y, float w, float h, float s);
	void init(float x, float y, float w, float h, float s);
	void update(sf::RenderWindow &window, bool move = true);
	void draw(sf::RenderWindow &window);
	bool hitby(float x, float y);

	bool notneed();

private:
	float m_x, m_y, m_w, m_h;
	float m_speed;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

};