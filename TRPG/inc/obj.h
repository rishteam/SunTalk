#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <string>

class Object{

public:

    Object() = default;
    Object(float x, float y, std::string str, bool clickable = false);

    void init(float x, float y, std::string str, bool clickable = false);
    void draw(sf::RenderWindow &window);
    bool isClick(sf::Vector2i M);

private:

    float m_x,m_y;
    
    bool m_clickable;
	sf::Sprite m_sprite;
	sf::Texture m_texture;

};
