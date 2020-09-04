#pragma once

#include <definition.h>

#include <map.h>
#include <role.h>

void SetupSlaveRoom(Map &M, Role &role){

    M.init();
    Object ObjSlaveRoom(0, 200, "irongate");
    M.increase(ObjSlaveRoom);
    role.setPos(80, 300);

}

void RunSlaveRoom(sf::RenderWindow &window, Map &M, Role &role){
}