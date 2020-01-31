#include <role.h>

Role::Role(float x, float y, float s){
	init(x, y, s);
}

void Role::init(float x, float y, float s){
	m_x = x;
	m_y = y;
	m_status = Status::DOWN;

	m_fly_1.loadFromFile("assets/pic/role/fly_1.png");
	m_fly_2.loadFromFile("assets/pic/role/fly_2.png");
	m_down.loadFromFile("assets/pic/role/down.png");

	m_role.setTexture(m_down);

	m_cnt = 0;
	m_anim = 10;
	m_speed = s;
}

void Role::update(sf::RenderWindow &window){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		m_status = Status::FLY;
		if( m_cnt < m_anim/2 ) m_role.setTexture(m_fly_1);
		else m_role.setTexture(m_fly_2);
		m_y -= m_speed;
	}
	else{
		m_status = Status::DOWN;
		m_role.setTexture(m_down);
		m_y += m_speed;
	}
	m_cnt++;
	m_cnt%= m_anim;

	if( m_y < 5 ) m_y = 5;
	if( m_y > 655 ) m_y = 655;
	m_role.setPosition(m_x,m_y);

}

void Role::draw(sf::RenderWindow &window){
	window.draw(m_role);
}

