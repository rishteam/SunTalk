#pragma once

#include <definition.h>

#include <map.h>
#include <role.h>

void SetupSlaveRoom(Map &M, Role &role){

    M.init();
    Object ObjSlaveRoom(0, 200, "irongate");
    M.increase(ObjSlaveRoom); // 0
    Object ObjBody(800,400,"body",true,false);
    M.increase(ObjBody); // 1

    role.setPos(80, 300);
    viewX = 0;
    viewY = 0;

}

void RunSlaveRoom(sf::RenderWindow &window, Map &M, Role &role){

    if( role.SuccessObserved() ){
        M.showIT(1);
    }

    switch( M.click(window) ){
        case 1:
            DeadBody = true;
            break;
        default:
            break;
    }

}