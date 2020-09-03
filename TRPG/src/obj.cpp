#include <obj.h>

#include <iostream>

Object::Object(float x, float y, std::string str, bool clickable){
    init(x,y,str,clickable);
}

void Object::init(float x, float y, std::string str, bool clickable){

    m_x = x;
    m_y = y;
    m_clickable = clickable;
    m_texture.loadFromFile("assets/obj/"+str+".png");

}

void Object::draw(sf::RenderWindow &window){
    
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition({m_x, m_y});
    window.draw(m_sprite);

}

bool Object::isClick(sf::Vector2i M){


    if( !m_clickable )
        return false;
    
    auto S = m_texture.getSize();
    if( m_x < M.x && M.x < m_x+S.x && m_y < M.y && M.y < m_y+S.y ){
        return true;
    }

    return false;

}