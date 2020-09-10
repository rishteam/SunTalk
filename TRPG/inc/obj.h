#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <string>

#include "imgui.h"
#include "imgui-SFML.h"

class Object{

public:

    Object() = default;
    Object(float x, float y, std::string str, bool clickable = false, bool m_show = true);

    void init(float x, float y, std::string str, bool clickable = false, bool m_show = true);
    void draw(sf::RenderWindow &window);
    bool isClick(sf::Vector2i M);
    void showIT();

private:

    float m_x,m_y;
    
    bool m_clickable;
    bool m_show;
	sf::Sprite m_sprite;
	sf::Texture m_texture;

};
