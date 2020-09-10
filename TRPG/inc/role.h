#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "imgui.h"
#include "imgui-SFML.h"

#include <stdlib.h>
#include <time.h>

class Role{

public:
    
    Role() = default;
    Role(float x, float y);
    
    void init(float x, float y);
    void setPos(float x, float y);
    float getX();
    float getY();
    void update();
    void draw(sf::RenderWindow &window);
    void ImguiData();

    bool SuccessObserved();
    bool ObservedtoObj();

private:

    float m_x, m_y;
    
	sf::Sprite m_sprite;
	sf::Texture m_texture;

    int m_observedData = 80;
    bool m_observed = false;

};


