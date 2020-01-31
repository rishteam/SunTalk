#pragma once

#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Button{

public:
	Button() = default;
	Button(float x, float y, float w, float h, sf::Texture t1, sf::Texture t2);
	void init(float x, float y, float w, float h, sf::Texture t1, sf::Texture t2);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	bool isClick(sf::RenderWindow &window);

private:
	float m_x, m_y, m_w, m_h;
	sf::Sprite m_sprite;
	sf::Texture m_texture_1;
	sf::Texture m_texture_2;

};