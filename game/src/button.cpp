#include <button.h>

Button::Button(float x, float y, float w, float h, sf::Texture t1, sf::Texture t2){
	init(x,y,w,h,t1,t2);
}

void Button::init(float x, float y, float w, float h, sf::Texture t1, sf::Texture t2){
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;

	m_texture_1 = t1;
	m_texture_2 = t2;
	m_sprite.setTexture(m_texture_2);
	m_sprite.setPosition(m_x,m_y);

}

void Button::update(sf::RenderWindow &window){
	auto pos = sf::Mouse::getPosition(window);
	float lx = m_x, ly = m_y, rx = m_x+m_w, ry = m_y+m_h;
	if(lx <= pos.x && pos.x <= rx && ly <= pos.y && pos.y <= ry){
		m_sprite.setTexture(m_texture_2);
	}
	else{
		m_sprite.setTexture(m_texture_1);
	}
}

void Button::draw(sf::RenderWindow &window){
	window.draw(m_sprite);
}

bool Button::isClick(sf::RenderWindow &window){
	auto pos = sf::Mouse::getPosition(window);
	float lx = m_x, ly = m_y, rx = m_x+m_w, ry = m_y+m_h;
	if(lx <= pos.x && pos.x <= rx && ly <= pos.y && pos.y <= ry)
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			return true;
	return false;
}