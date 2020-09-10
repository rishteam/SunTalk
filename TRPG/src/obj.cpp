#include <obj.h>

#include <iostream>

Object::Object(float x, float y, std::string str, bool clickable, bool show){
    init(x,y,str,clickable,show);
}

void Object::init(float x, float y, std::string str, bool clickable, bool show){

    m_x = x;
    m_y = y;
    m_clickable = clickable;
    m_show = show;
    m_texture.loadFromFile("assets/obj/"+str+".png");

}

void Object::draw(sf::RenderWindow &window){
    
    if( !m_show )
        return;

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition({m_x, m_y});
    window.draw(m_sprite);

}

bool Object::isClick(sf::Vector2i M){

    if( !m_clickable || !m_show )
        return false;
    
    auto S = m_texture.getSize();
    if( m_x < M.x && M.x < m_x+S.x && m_y < M.y && M.y < m_y+S.y ){
        m_clickable = false;
        return true;
    }

    return false;

}

void Object::showIT(){
    m_show = true;
}