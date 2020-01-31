#include <game.h>

Game::Game(int w, int h, float s){
	init(w,h,s);
}

void Game::init(int w, int h, float s){

	m_ww = w;
	m_wh = h;
	m_speed = s;
	m_cnt = 0;
	m_score = 0;
	m_process = Process::READY;

	m_font.loadFromFile("assets/font/arial.ttf");
	m_scoreText.setFont(m_font);
	m_scoreText.setPosition(600,30);
	m_scoreText.setCharacterSize(30);
	m_scoreText.setString("Score: " + std::to_string(m_score) );
	m_scoreText.setFillColor(sf::Color(0,0,0));

	m_Bird.init((3*m_ww/4),(m_wh/2),m_speed);

	Pillar Up(  500,-500, 100, 800, m_speed);
	Pillar Down(500, 450, 100, 800, m_speed);

	m_PillarTable.clear();
	m_PillarTable.push_back(Up);
	m_PillarTable.push_back(Down);

	m_readyTexture.loadFromFile("assets/pic/other/ready.png");
	m_resetTexture.loadFromFile("assets/pic/other/reset.png");

}

void Game::ready(sf::RenderWindow &window){

	m_Bird.update(window,false);
	for(int i = 0 ; i < m_PillarTable.size() ; i++ )
		m_PillarTable[i].update(window,false);

	m_Sprite.setTexture(m_readyTexture);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		m_process = Process::PLAY;

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
	Pillar Up(  -200+spacing,      high-800, 100,  800, m_speed);
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
		m_scoreText.setPosition(600,30);
		m_scoreText.setCharacterSize(30);
		m_scoreText.setString("Score: " + std::to_string(m_score) );
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
			m_process = Process::LOSE;
}

void Game::restart(sf::RenderWindow &window){

	m_scoreText.setPosition(260,100);
	m_scoreText.setCharacterSize(120);
	m_scoreText.setString("You got " + std::to_string(m_score) + " score");

	m_Bird.update(window,false);
	for(int i = 0 ; i < m_PillarTable.size() ; i++ )
		m_PillarTable[i].update(window,false);

	m_Sprite.setTexture(m_resetTexture);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
		init(m_ww, m_wh, m_speed);
		m_process = Process::READY;
	}

}

void Game::update(sf::RenderWindow &window){
	
	switch (m_process){
		case Process::READY:
			ready(window);
			break;
		case Process::PLAY:
			run(window);
			break;
		case Process::LOSE:
			restart(window);
			break;
		default:
			break;
	}

}

void Game::draw(sf::RenderWindow &window){

	for(auto P : m_PillarTable)
		P.draw(window);
	m_Bird.draw(window);

	switch (m_process){
		case Process::READY:
			window.draw(m_Sprite);
			break;
		case Process::PLAY:
			window.draw(m_scoreText);
			break;
		case Process::LOSE:
			window.draw(m_Sprite);
			window.draw(m_scoreText);
			break;
		default:
			break;
	}

}
