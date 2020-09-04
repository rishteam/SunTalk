#include <role.h>

Role::Role(float x, float y){
    init(x,y);
}

void Role::init(float x, float y){
    m_x = x;
    m_y = y;
    m_texture.loadFromFile("assets/role/Yukino.png");
    m_sprite.setTexture(m_texture);
}

void Role::update(){
    
    float x = 0, y = 0;
    // if( sf::Keyboard::isKeyPressed(sf::Keyboard::W) ){
    //     y -= 5;
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
    //     y += 5;
    // }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        x -= 5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        x += 5;
    }

    m_x += x;
    m_y += y;

}

void Role::setPos(float x, float y){
    m_x = x;
    m_y = y;
}

float Role::getX(){
    return m_x;
}

float Role::getY(){
    return m_y;
}

void Role::draw(sf::RenderWindow &window){

    m_sprite.setTexture(m_texture);
    m_sprite.setPosition({m_x, m_y});
    window.draw(m_sprite);

}
