#include <map.h>

void Map::init(){
    m_obj.clear();
}

void Map::increase(Object obj){
    m_obj.push_back(obj);
}

void Map::draw(sf::RenderWindow &window){
    for(auto i : m_obj){
        i.draw(window);
    }
}

int Map::click(sf::RenderWindow &window){

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        
        auto X = window.getView().getCenter();
        auto M = sf::Mouse::getPosition(window);

        // printf("%d ",M.x);
        M.x += int(X.x)-640;
        // printf("%d\n",M.x);
        
        for(int i = 0 ; i < m_obj.size() ; i++ ){
            if( m_obj[i].isClick(M) )
                return i;
        }

    }

    return -1;
}