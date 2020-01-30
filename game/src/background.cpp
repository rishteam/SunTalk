#include <background.h>

Background::Background(float bgs, float fgs){

	m_bgSpeed = bgs;
	m_bgTexture.loadFromFile("assets/pic/background/bg.png");

	m_bgSprite_1.setTexture(m_bgTexture);
	m_bgSprite_2.setTexture(m_bgTexture);

	m_bgSprite_1.setPosition(0,0);
	m_bgSprite_2.setPosition(5120,0);
//------------------------------------------
	m_fgSpeed = fgs;
	m_fgTexture.loadFromFile("assets/pic/background/fg.png");

	m_fgSprite_1.setTexture(m_fgTexture);
	m_fgSprite_2.setTexture(m_fgTexture);

	m_fgSprite_1.setPosition(-2560,0);
	m_fgSprite_2.setPosition(0,0);

}

void Background::update(sf::RenderWindow &window){

	auto posBg1 = m_bgSprite_1.getPosition();
	auto posBg2 = m_bgSprite_2.getPosition();
	
	posBg1.x -= m_bgSpeed;
	posBg2.x -= m_bgSpeed;

	if( posBg1.x == 0 ) posBg2.x = 5120;
	if( posBg2.x == 0 ) posBg1.x = 5120;

	m_bgSprite_1.setPosition(posBg1.x,posBg1.y);
	m_bgSprite_2.setPosition(posBg2.x,posBg2.y);

	auto posFg1 = m_fgSprite_1.getPosition();
	auto posFg2 = m_fgSprite_2.getPosition();

	posFg1.x += m_fgSpeed;
	posFg2.x += m_fgSpeed;

	if( posFg1.x == 0 ) posFg2.x = -2560;
	if( posFg2.x == 0 ) posFg1.x = -2560;

	m_fgSprite_1.setPosition(posFg1.x,posFg1.y);
	m_fgSprite_2.setPosition(posFg2.x,posFg2.y);


}

void Background::draw(sf::RenderWindow &window){
	window.draw(m_bgSprite_1);
	window.draw(m_bgSprite_2);
	window.draw(m_fgSprite_1);
	window.draw(m_fgSprite_2);
}