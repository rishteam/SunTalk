#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include <obj.h>

class Map{

public:

    Map() = default;

    void init();
    void increase(Object obj);
    void draw(sf::RenderWindow &window);
    int click(sf::RenderWindow &window);

private:
    std::vector <Object> m_obj;

};
