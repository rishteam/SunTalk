#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Role{

public:
    
    Role() = default;
    Role(float x, float y);
    
    void init(float x, float y);
    float getX();
    void update();
    void draw(sf::RenderWindow &window);

private:

    float m_x, m_y;
    
	sf::Sprite m_sprite;
	sf::Texture m_texture;

};


