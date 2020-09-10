#pragma once

#include <definition.h>

#include <map.h>
#include <role.h>

void SetupBookRoom(Map &M, Role &role){
    
    M.init();
    Object ObjBookRoom(0, 200, "woodgate");
    M.increase(ObjBookRoom); //
    
    role.setPos(80, 300);
    viewX = 0;
    viewY = 0;

}

void RunBookRoom(sf::RenderWindow &window, Map &M, Role &role){
}