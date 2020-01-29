#include <role.h>

Role::Role(float x, float y, float s){

	m_x = x;
	m_y = y;
	m_status = Status::STOP;

	m_fly_1.loadFromFile("assets/pic/role/fly_1.png");
	m_fly_2.loadFromFile("assets/pic/role/fly_2.png");
	m_stop_1.loadFromFile("assets/pic/role/stop_1.png");
	m_stop_2.loadFromFile("assets/pic/role/stop_2.png");
	m_down.loadFromFile("assets/pic/role/down.png");

	m_role.setTexture(m_stop_1);

	m_cnt = 0;
	m_anim = 60;
	m_speed = s;

}

void Role::reset(float x, float y){
	m_x = x;
	m_y = y;
	m_status = Status::STOP;
	m_cnt = 0;
}

void Role::update(sf::RenderWindow &window){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		m_status = Status::FLY;
		if( m_cnt < m_anim/2 ) m_role.setTexture(m_fly_1);
		else m_role.setTexture(m_fly_2);
		m_y -= m_speed;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		m_status = Status::STOP;
		if( m_cnt < m_anim/2 ) m_role.setTexture(m_stop_1);
		else m_role.setTexture(m_stop_2);
	}
	else{
		m_status = Status::DOWN;
		m_role.setTexture(m_down);
		m_y += m_speed;
	}
	m_cnt++;
	m_cnt%= m_anim;
	m_role.setPosition(m_x,m_y);
}

void Role::draw(sf::RenderWindow &window){
	window.draw(m_role);
}

