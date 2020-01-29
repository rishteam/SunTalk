#include <game.h>

Game::Game(int w, int h, float s){

	m_ww = w;
	m_wh = h;
	m_speed = s;
	m_cnt = 0;
	m_score = 0;

	m_font.loadFromFile("assets/font/arial.ttf");

	m_Bird.init((3*m_ww/4),(m_wh/2),m_speed);

	Pillar Up(500,0,100,300,m_speed);
	Pillar Down(500,450,100,300,m_speed);

	m_PillarTable.push_back(Up);
	m_PillarTable.push_back(Down);

}

void Game::addPillar(){

	srand(time(NULL));
	int high = rand()%((rand()%10+1)*50)+50;
	printf("%d\n",high);
	int interval = rand()%((rand()%10+1)*30)+150;
	int spacing = (rand()%((rand()%10+1)*100))%200-100;
	if( -30 < spacing && spacing < 30 ) spacing = 0;
	Pillar Up(  -200+spacing,             0, 100, high, m_speed);
	Pillar Down(-200-spacing, high+interval, 100,  800, m_speed);

	m_PillarTable.push_back(Up);
	m_PillarTable.push_back(Down);

}

void Game::update(sf::RenderWindow &window){
	
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

	// printf("%d\n", m_PillarTable.size());
	
}

void Game::draw(sf::RenderWindow &window){
	m_Bird.draw(window);
	for(auto P : m_PillarTable)
		P.draw(window);
}
