#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Background{

public:
	Background() = default;
	Background(float bgs, float fgs);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

private:
	float m_bgSpeed,m_fgSpeed;
	sf::Sprite m_bgSprite_1;
	sf::Sprite m_bgSprite_2;
	sf::Texture m_bgTexture;

	sf::Sprite m_fgSprite_1;
	sf::Sprite m_fgSprite_2;
	sf::Texture m_fgTexture;

};
