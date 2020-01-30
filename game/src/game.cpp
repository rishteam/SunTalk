#include <game.h>

Game::Game(int w, int h, float s){

	m_ww = w;
	m_wh = h;
	m_speed = s;
	m_cnt = 0;
	m_score = 0;
	m_lose = false;

	m_font.loadFromFile("assets/font/arial.ttf");

	m_Bird.init((3*m_ww/4),(m_wh/2),m_speed);

	Pillar Up(500,0,100,300,m_speed);
	Pillar Down(500,450,100,300,m_speed);

	m_PillarTable.clear();
	m_PillarTable.push_back(Up);
	m_PillarTable.push_back(Down);

}

void Game::restart(int w, int h, float s){

	m_ww = w;
	m_wh = h;
	m_speed = s;
	m_cnt = 0;
	m_score = 0;
	m_lose = false;

	m_font.loadFromFile("assets/font/arial.ttf");

	m_Bird.init((3*m_ww/4),(m_wh/2),m_speed);

	Pillar Up(500,0,100,300,m_speed);
	Pillar Down(500,450,100,300,m_speed);

	m_PillarTable.clear();
	m_PillarTable.push_back(Up);
	m_PillarTable.push_back(Down);

}

void Game::addPillar(){

	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<float> unif(0.0,1.0);

	float high = unif(generator)*400+50.0;
	float interval = unif(generator)*100+150.0;
	float spacing = unif(generator)*200-100.0;
	
	std::cout << high << " " << interval << " " << spacing << std::endl;
	
	if( -30 < spacing && spacing < 30 ) spacing = 0;
	Pillar Up(  -200+spacing,             0, 100, high, m_speed);
	Pillar Down(-200-spacing, high+interval, 100,  800, m_speed);

	m_PillarTable.push_back(Up);
	m_PillarTable.push_back(Down);

}

void Game::run(sf::RenderWindow &window){

	m_cnt += m_speed;
	if( m_cnt > 50 ){
		m_score++;
		m_cnt = 0;
		m_isAdd = true;
	}
	if( m_score%10 == 0 && m_isAdd ){
		m_isAdd = false;
		addPillar();
	}

	m_Bird.update(window);
	for(int i = 0 ; i < m_PillarTable.size() ; i++ )
		m_PillarTable[i].update(window);

	while( m_PillarTable[0].notneed() )
		m_PillarTable.erase(m_PillarTable.begin(),m_PillarTable.begin()+1);

	for(auto P : m_PillarTable )
		if( P.hitby(m_Bird.getX()+50.0,m_Bird.getY()+50.0) )
			m_lose = true;
}

void Game::update(sf::RenderWindow &window){
	
	if( !m_lose ){
		run(window);
	}

}

void Game::draw(sf::RenderWindow &window){
	m_Bird.draw(window);
	for(auto P : m_PillarTable)
		P.draw(window);
}
