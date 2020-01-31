#include <pillar.h>

Pillar::Pillar(float x, float y, float w, float h, float s){
	init(x,y,w,h,s);
}

void Pillar::init(float x, float y, float w, float h, float s){
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
	m_speed = s;
	
	m_texture.loadFromFile("assets/pic/pillar.png");
	m_sprite.setTexture(m_texture);
}

void Pillar::update(sf::RenderWindow &window, bool move){
	if(move) m_x += m_speed;
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition({m_x, m_y});
}

void Pillar::draw(sf::RenderWindow &window){
	window.draw(m_sprite);
}

bool Pillar::hitby(float x, float y){
	float radius = 20;
	float lx = m_x, ly = m_y, rx = m_x+m_w, ry = m_y+m_h;
	if(lx-radius <= x && x <= rx+radius && ly-radius <= y && y <= ry+radius)
		return true;
	return false;
}

bool Pillar::notneed(){
	if( m_x > 1500 ) return true;
	return false;
}