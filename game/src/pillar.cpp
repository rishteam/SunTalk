#include <pillar.h>

Pillar::Pillar(float x, float y, float w, float h, float s){
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;

	m_speed = s;
	
	m_rect.setPosition({x, y});
	m_rect.setSize({w, h});
	m_rect.setFillColor(sf::Color(255, 255, 255));
}

void Pillar::update(sf::RenderWindow &window){
	m_x += m_speed;
	m_rect.setPosition({m_x, m_y});
}

void Pillar::draw(sf::RenderWindow &window){
	window.draw(m_rect);
}

bool Pillar::hitby(float x, float y){
	float lx = m_x, ly = m_y, rx = m_x+m_w, ry = m_y+m_h;
	if(lx <= x && x <= rx && ly <= y && y <= ry)
		return true;
	return false;
}