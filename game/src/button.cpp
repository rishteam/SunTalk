#include <button.h>

Button::Button(float x, float y, float w, float h, sf::Text text){
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;

	m_rectShape.setPosition({x, y});
	m_rectShape.setSize({w, h});

	m_text = text;
	m_text.setPosition(m_x+10, m_y-10);
}

void Button::init(float x, float y, float w, float h, sf::Text text){
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;

	m_rectShape.setPosition({x, y});
	m_rectShape.setSize({w, h});

	m_text = text;
	m_text.setPosition(m_x+10, m_y-10);
}

void Button::update(sf::RenderWindow &window){
	auto pos = sf::Mouse::getPosition(window);
	float lx = m_x, ly = m_y, rx = m_x+m_w, ry = m_y+m_h;
	if(lx <= pos.x && pos.x <= rx && ly <= pos.y && pos.y <= ry){
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			m_rectShape.setFillColor(sf::Color(128, 128, 128));
		else
			m_rectShape.setFillColor(sf::Color(160, 160, 160));
		m_text.setFillColor(sf::Color(255, 255, 255));
	}
	else{
		m_rectShape.setFillColor(sf::Color(255, 255, 255));
		m_text.setFillColor(sf::Color(0, 0, 0));
	}
}

void Button::draw(sf::RenderWindow &window){
	window.draw(m_rectShape);
	window.draw(m_text);
}

bool Button::mouseIn(float pos_x, float pos_y){
	float lx = m_x, ly = m_y, rx = m_x+m_w, ry = m_y+m_h;
	if(lx <= pos_x && pos_x <= rx && ly <= pos_y && pos_y <= ry)
		return true;
	return false;
}