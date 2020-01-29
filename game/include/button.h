#pragma once

#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Button{

public:
	Button() = default;
	Button(float x, float y, float w, float h, sf::Text text);
	void init(float x, float y, float w, float h, sf::Text text);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	bool mouseIn(float pos_x, float pos_y);

private:
	float m_x, m_y, m_w, m_h;
	sf::RectangleShape m_rectShape;
	sf::Text m_text;

};